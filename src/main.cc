#include "application.h"
#include "log.h"

int main(int argc, char ** argv) 
{
    log_level = 2;
    try 
    {
        LOG(0, "MAIN app init");
        Application::init(argc, argv);
        LOG(0, "MAIN run");
        Application::instance()->run();
        LOG(0, "MAIN finish");
        Application::finish();
    } 
    catch (std::exception & e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }
    return 0;
}
