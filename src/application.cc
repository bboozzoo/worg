#include <glibmm.h>
#include <giomm.h>
#include "application.h"
#include "log.h"

Application * Application::m_instance = NULL;

Application::Application()
{

}

Application::~Application()
{

}

void
Application::init()
{
    if (m_instance != NULL)
        throw Error("Application already initialized", ERR_HERE);
    m_instance = new Application();
    m_instance->m_config_dir = Glib::build_filename(Glib::get_user_config_dir(), "worg");
    LOG(1, "config dir: " << m_instance->m_config_dir);
    try 
    {
        Glib::RefPtr<Gio::File> config_dir = Gio::File::create_for_path(m_instance->m_config_dir);
        LOG(1, "make directory");
        config_dir->make_directory();
    }
    catch (Gio::Error & err) 
    {
        if (err.code() != Gio::Error::EXISTS)
            throw;
        else 
        {
            LOG(1, "directory exists");
        }
            
    }
    LOG(1, "directory done");
}

void 
Application::finish()
{
    if (m_instance != NULL)
    {
        delete m_instance;
        m_instance = NULL;
    }
}


std::string
Application::get_config_dir()
{

}

