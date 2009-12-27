#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include "error.h"
#include <boost/shared_ptr.hpp>

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

};

#endif /* __APPLICATION_H__ */
