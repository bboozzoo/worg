#ifndef __DB_H__
#define __DB_H__
#include <boost/shared_ptr.hpp>

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

    private:
        DB();
        void open_db();
        void close_db();
        bool check_db_exists(std::string & path);
        void create_schema();
        void run_query(const char * query);
        void run_query_prepared(void * query_format);

        static db_sptr_t    m_db;
        DB_interface &      m_dbi;        
};

#endif /* __DB_H__ */
