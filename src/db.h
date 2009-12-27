#ifndef __DB_H__
#define __DB_H__
#include <boost/shared_ptr.hpp>
#include "activity-model.h"

class DB_interface
{
};

class DB;
typedef boost::shared_ptr<DB> db_sptr_t;
class DB 
{
    public:
        ~DB();
        static void init();
        static void finish();
        static db_sptr_t instance();
        void get_all_activities(std::list<amodel_sptr_t> & alist);        
        void get_all_activity_types(std::list<atmodel_sptr_t> & atlist);

    private:

        typedef int (*sqlite_clbk_f)(void *, int, char **, char **);
        DB();
        void open_db();
        void close_db();
        bool check_db_exists(std::string & path);
        void create_schema();
        void run_query(const char * query, sqlite_clbk_f, void * param);
        void run_query_prepared(void * query_format);

        static db_sptr_t    m_db;
        DB_interface &      m_dbi;        
};

#endif /* __DB_H__ */
