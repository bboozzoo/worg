#include <giomm.h>
#include "db.h"
#include "application.h"
#include "log.h"

int main(int argc, char ** argv) 
{
    Gio::init();
    log_level = 2;
    LOG(0, "init DB");
    DB::init();
    LOG(0, "get instance");
    DB * db = DB::instance();

    Application::init();
    Application::finish();
    LOG(0, "finish");
    DB::finish();
    return 0;
}
