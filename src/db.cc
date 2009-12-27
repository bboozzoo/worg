#include <sqlite3.h>
#include "db.h"
#include "log.h"
#include "error.h"

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
DB * DB::m_db = NULL;


DB::DB() 
    : m_dbi(db_sqlite)
{
    LOG(1, "DB constructor");
    if (sqlite3_open("file.db", &DBsq.m_sql3))
    {
        LOG(0, "DB open failed: " << sqlite3_errmsg(DBsq.m_sql3));
        DBsq.m_sql3 = NULL;
        throw Error("database initialization failed", ERR_HERE);
    }
    LOG(1, "DB opened");
}

DB::~DB() 
{
    LOG(1, "DB destructor");
    if (DBsq.m_sql3 != NULL)
    {
        sqlite3_close(DBsq.m_sql3);
        DBsq.m_sql3 = NULL;
    }
}

void
DB::init() 
{
    LOG(1, "DB init");
    if (m_db != NULL) 
    {
        LOG(0, "DB already initialized");
        throw Error("database already initialized", ERR_HERE);
    }
    m_db = new DB();
}

void 
DB::finish()
{
    LOG(1, "DB finish");
    if (m_db != NULL) 
    {
        LOG(1, "DB delete db");
        delete m_db;
        m_db = NULL;
    }
}

DB * 
DB::instance()
{
    if (m_db)
        return m_db;
    else 
        throw Error("DB not initialized", ERR_HERE);
    return NULL;
}

