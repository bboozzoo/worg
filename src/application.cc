#include <glibmm.h>
#include <giomm.h>
#include <config.h>
#include "application.h"
#include "log.h"
#include "fileconfig.h"
#include "db.h"
#include "ui.h"

app_sptr_t Application::m_instance;

Application::Application()
{
}

Application::~Application()
{
}

void
Application::init(int argc, char ** argv)
{
    LOG(0, "APP GIO init");
    Gio::init();
   
    LOG(0, "APP create instance");
    if (m_instance)
        throw Error("Application already initialized", ERR_HERE);
    m_instance = app_sptr_t(new Application());
    create_config_dir();

    LOG(0, "APP init DB");
    DB::init();
    LOG(0, "APP init UI");
    UI::init(argc, argv);
}

void 
Application::finish()
{
    if (!m_instance)
        throw Error("Application not initialized", ERR_HERE);

    LOG(0, "APP finish");
    LOG(0, "APP finish UI");
    UI::finish();
    LOG(0, "APP finish DB");
    DB::finish();

    LOG(0, "APP release instance");
    m_instance.reset();
}

app_sptr_t
Application::instance()
{
    if (!m_instance)
        throw Error("Application not initialized", ERR_HERE);
    return m_instance;
}

void
Application::run()
{
    if (!m_instance)
        throw Error("Application not initialized", ERR_HERE);
    LOG(1, "APP run");
    UI::instance()->run();
    LOG(1, "APP run finished");
}

std::string
Application::get_config_dir()
{
    if (!m_instance)
        throw Error("applicatin not initialized", ERR_HERE);
    return m_instance->m_config_dir;
}

void
Application::create_config_dir()
{
    m_instance->m_config_dir = Glib::build_filename(Glib::get_user_config_dir(), PACKAGE_NAME);
    LOG(1, "APP config dir: " << m_instance->m_config_dir);
    try 
    {
        Glib::RefPtr<Gio::File> config_dir = Gio::File::create_for_path(m_instance->m_config_dir);
        LOG(1, "APP make directory");
        config_dir->make_directory();
    }
    catch (Gio::Error & err) 
    {
        if (err.code() != Gio::Error::EXISTS)
            throw;
        else 
        {
            LOG(1, "APP directory exists");
        }
            
    }
    LOG(1, "APP directory done");
}

std::string
Application::get_db_file_path()
{
    if (!m_instance)
        throw Error("Application not initialized", ERR_HERE);
    std::string db_file = Glib::build_filename(m_instance->m_config_dir, DB_FILE_NAME);
    LOG(1, "APP db file: " << db_file);
    return db_file;
}

