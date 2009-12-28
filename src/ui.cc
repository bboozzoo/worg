#include "ui.h"
#include "log.h"
#include "error.h"

ui_sptr_t UI::m_instance;

UI::UI(int argc, char ** argv)
    : m_kit(argc, argv)
{
    LOG(1, "UI constructor");
}

UI::~UI()
{
    LOG(1, "UI destructor");
}

void
UI::init(int argc, char ** argv)
{
    LOG(1, "UI init");
    if (m_instance)
        throw Error("UI already initialized", ERR_HERE);
    LOG(1, "UI create instance");
    m_instance = ui_sptr_t(new UI(argc, argv));
    m_instance->init_gfx();
}

void
UI::finish()
{
    LOG(1, "UI finish");
    m_instance.reset();
}

ui_sptr_t
UI::instance()
{
    return m_instance;
}

void
UI::run()
{
    if (!m_instance)
        throw Error("UI not initialized", ERR_HERE);

    LOG(0, "UI entering main loop");
    Gtk::Main::run();
    LOG(0, "UI main loop finished");
}

void 
UI::quit()
{
    LOG(0, "UI quit");
    Gtk::Main::quit();
}

void
UI::init_gfx()
{
    m_icon = Gtk::StatusIcon::create_from_file("clock.svg");
    m_icon->signal_popup_menu().connect(sigc::mem_fun(*this, &UI::on_tray_icon_popup));
    init_popup_menu();
}

void
UI::init_popup_menu()
{
    try 
    {
        Glib::RefPtr<Gtk::Builder> menu_builder = Gtk::Builder::create_from_file("ui.glade", "popup-menu");

        menu_builder->get_widget("popup-menu", m_popup_menu);

        Gtk::MenuItem * quit_item = NULL;
        menu_builder->get_widget("menu-quit", quit_item);
        quit_item->signal_activate().connect(sigc::mem_fun(*this, &UI::on_tray_icon_quit));
    }
    catch (Glib::Exception & e)
    {
        LOG(0, "UI ERROR: " << e.what());
        throw;
    }
}

void 
UI::on_tray_icon_position(int & x, int & y, bool & push_in)
{
    int ix, iy;
    gboolean ipush_in;
    LOG(1, "UI position popup menu");
    gtk_status_icon_position_menu(m_popup_menu->gobj(), &x, &y, &ipush_in, m_icon->gobj());
    push_in = (ipush_in == TRUE) ? true : false;
}

void
UI::on_tray_icon_popup(guint button, guint32 time)
{
    LOG(1, "UI popup, button: " << button << " time: " << time);
    m_popup_menu->popup(sigc::mem_fun(*this, &UI::on_tray_icon_position), button, time);
}

void
UI::on_tray_icon_quit()
{
    LOG(1, "UI popup, QUIT");
    quit();
}

