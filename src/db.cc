#include <giomm.h>
#include <sqlite3.h>
#include "application.h"
#include "db.h"
#include "log.h"
#include "error.h"

#define NEED_SCHEMA
#include "db-schema.h"
#undef NEED_SCHEMA


class DB_sqlite : public DB_interface
{
    public:
        DB_sqlite() 
            : m_sql3(NULL)
        {}
        ~DB_sqlite()
        {}
        sqlite3 * m_sql3;
};
#define DBsq (static_cast<DB_sqlite&>(this->m_dbi))
static DB_sqlite db_sqlite;


db_sptr_t DB::m_db;

DB::DB() 
    : m_dbi(db_sqlite)
{
}

DB::~DB() 
{
}

void
DB::init() 
{
    LOG(1, "DB init");
    if (m_db) 
    {
        LOG(0, "DB already initialized");
        throw Error("database already initialized", ERR_HERE);
    }
    m_db = db_sptr_t(new DB());
    m_db->open_db();
}

void 
DB::finish()
{
    LOG(1, "DB finish");
    if (m_db) 
    {
        m_db->close_db();
        m_db.reset();
    }
}

db_sptr_t
DB::instance()
{
    if (m_db)
        return m_db;
    throw Error("DB not initialized", ERR_HERE);
}

void 
DB::open_db() 
{
    bool needs_schema = false;

    LOG(1, "DB open");
    std::string db_path = Application::instance()->get_db_file_path();

    /* check if db file is present, if not create it and schema */
    if (check_db_exists(db_path) == false) 
    {
        LOG(1, "DB not present, will need schema");
        needs_schema = true;
    }

    if (SQLITE_OK != sqlite3_open(db_path.c_str(), &DBsq.m_sql3))
    {
        LOG(0, "DB open failed: " << sqlite3_errmsg(DBsq.m_sql3));
        DBsq.m_sql3 = NULL;
        throw Error("database initialization failed", ERR_HERE);
    }
    LOG(1, "DB opened");

    if (needs_schema)
        create_schema();
}

void 
DB::close_db()
{
    LOG(1, "DB close");
    if (DBsq.m_sql3 != NULL)
    {
        sqlite3_close(DBsq.m_sql3);
        DBsq.m_sql3 = NULL;
        LOG(1, "DB closed");
    }
}

bool
DB::check_db_exists(std::string & path)
{
    Glib::RefPtr<Gio::File> db_path = Gio::File::create_for_path(path);
    return db_path->query_exists();
}

void
DB::create_schema()
{
    LOG(0, "DB creating schema");
    try 
    {
        LOG(1, "creating activities table");
        run_query(sch_create_acitivities_table);
        LOG(1, "creating activity types table");
        run_query(sch_create_acitivity_types_table);
        LOG(1, "creating activities-types map table");
        run_query(sch_create_activities_map_table);
    }
    catch (Error & e)
    {
        LOG(0, "creating schema failed");
        throw;
    }
}

void
DB::run_query(const char * query)
{
    char * err = NULL;
    if (SQLITE_OK != sqlite3_exec(DBsq.m_sql3, query, NULL, NULL, &err)) 
    {
        throw Error(std::string("executing query failed").append(err), ERR_HERE);
    }
}

void
DB::run_query_prepared(void * query_format)
{

}

