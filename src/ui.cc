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
    Gtk::Window w;
    Gtk::Main::run(w);
    LOG(0, "UI main loop finished");
}

