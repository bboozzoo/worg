#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include "error.h"

class Application
{
    public:
        static void init();
        static void finish();
        static Application * instance();
        std::string get_config_dir();
    private:
        Application();
        ~Application();
        static Application *    m_instance;
        std::string             m_config_dir;

};

#endif /* __APPLICATION_H__ */
