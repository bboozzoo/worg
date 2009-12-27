#include <giomm.h>
#include "db.h"
#include "application.h"
#include "log.h"

int main(int argc, char ** argv) 
{
    try 
    {
        Gio::init();
        Application::init();
        log_level = 2;
        LOG(0, "init DB");
        DB::init();
        LOG(0, "get instance");
        db_sptr_t db = DB::instance();

        LOG(0, "finish");
        DB::finish();
        Application::finish();
    } 
    catch (std::exception & e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }
    return 0;
}
