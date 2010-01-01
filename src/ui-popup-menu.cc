#include "ui-popup-menu.h"
#include "error.h"
#include "log.h"

ui_popmenu_sptr_t UIPopupMenu::m_instance;

UIPopupMenu::UIPopupMenu()
{
    LOG(1, "UIPM constructor");
}

UIPopupMenu::~UIPopupMenu()
{
    LOG(1, "UIPM destructor");
}

void
UIPopupMenu::init(Glib::RefPtr<Gtk::StatusIcon> icon)
{
    try 
    {
        if (m_instance)
            throw Error("UIPM already initialized", ERR_HERE);

        m_instance = ui_popmenu_sptr_t(new UIPopupMenu());
        m_instance->m_ui_builder = Gtk::Builder::create_from_file("ui-menu.glade", "popup-menu");
        /* get popup menu widget */
        m_instance->m_ui_builder->get_widget("popup-menu", m_instance->m_popup_menu);
        /* connect quit menu entry */
        Gtk::MenuItem * quit_item = NULL;
        m_instance->m_ui_builder->get_widget("menu-quit", quit_item);
        quit_item->signal_activate().connect(sigc::mem_fun(*m_instance, &UIPopupMenu::on_menu_quit));

        m_instance->m_parent_icon = icon;
        m_instance->m_parent_icon->signal_popup_menu().connect(sigc::mem_fun(*m_instance, &UIPopupMenu::on_menu_popup));
    }
    catch (Glib::Exception & e)
    {
        LOG(0, "UI ERROR: " << e.what());
        throw;
    }
}

void
UIPopupMenu::finish()
{
    if (!m_instance)
        throw Error("UIPM not initialized", ERR_HERE);
   
    LOG(1, "UIPM finishing");
    m_instance->m_popup_menu = NULL;
    m_instance.reset();
    LOG(1, "UIPM finished"); 
}

ui_popmenu_sptr_t
UIPopupMenu::instance()
{
    if (!m_instance)
        throw Error("UIPM not initialized", ERR_HERE);
    return m_instance;
}

Gtk::Menu *
UIPopupMenu::menu()
{
    if (!m_instance)
        throw Error("UIPM not initialized", ERR_HERE);
    return m_popup_menu;
}

sigc::signal<void>
UIPopupMenu::signal_quit()
{
    LOG(1, "UIPM requesting signal quit proxy");
    return m_signal_quit;
}

void
UIPopupMenu::on_menu_quit()
{
    LOG(1, "UIPM popup, emit signal QUIT");
    m_signal_quit.emit();
}

void
UIPopupMenu::on_menu_popup(guint button, guint32 time)
{
    LOG(1, "UIPM popup, button: " << button << " time: " << time);
    if (m_parent_icon)
        m_popup_menu->popup(sigc::mem_fun(*this, &UIPopupMenu::on_menu_position), button, time);
    else
        m_popup_menu->popup(button, time);
}

void 
UIPopupMenu::on_menu_position(int & x, int & y, bool & push_in)
{
    int ix, iy;
    gboolean ipush_in;
    LOG(1, "UIPM position popup menu");
    gtk_status_icon_position_menu(m_popup_menu->gobj(), &x, &y, &ipush_in, m_parent_icon->gobj());
    push_in = (ipush_in == TRUE) ? true : false;
}

