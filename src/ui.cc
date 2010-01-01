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
    UIPopupMenu::finish();
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
    init_popup_menu();
}

void
UI::init_popup_menu()
{
    LOG(1, "UI init popup menu");
    UIPopupMenu::init(m_icon);
    UIPopupMenu::instance()->signal_quit().connect(sigc::mem_fun(*this, &UI::on_popup_menu_quit));
}

void
UI::on_popup_menu_quit()
{
    LOG(1, "UI popup, QUIT");
    quit();
}

