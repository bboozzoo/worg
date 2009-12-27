#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include <boost/shared_ptr.hpp>
#include "error.h"
#include "activity-model.h"

class Application;
typedef boost::shared_ptr<Application> app_sptr_t;
class Application
{
    public:
        ~Application();
        static void init();
        static void finish();
        static app_sptr_t instance();
        std::string get_config_dir();
        std::string get_db_file_path();
    private:
        Application();
        static void create_config_dir();

        static app_sptr_t   m_instance;
        std::string         m_config_dir;
        std::list<atmodel_sptr_t>   m_activity_types;
        std::list<amodel_sptr_t>    m_activities;

};

#endif /* __APPLICATION_H__ */
