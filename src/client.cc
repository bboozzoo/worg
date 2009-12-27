#include <giomm.h>
#include "db.h"
#include "application.h"
#include "log.h"

int main(int argc, char ** argv) 
{
    try 
    {
        Application::init(argc, argv);
        log_level = 2;
        LOG(0, "init DB");
        DB::init();
        LOG(0, "get instance");
        db_sptr_t db = DB::instance();

        LOG(0, "get all activity types");
        std::list<atmodel_sptr_t> activity_types;
        db->get_all_activity_types(activity_types);
        for (std::list<atmodel_sptr_t>::iterator i = activity_types.begin(); i != activity_types.end(); i++)
        {
            atmodel_sptr_t atm = *i;
            std::cout << "name: " << atm->get_name() << " id: " << atm->get_id();
        }

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
