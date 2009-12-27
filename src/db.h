#ifndef __DB_H__
#define __DB_H__

class DB_interface
{
};

class DB 
{
    public:
        static void init();
        static void finish();
        static DB * instance();

    private:
        DB();
        ~DB();

        static DB *    m_db;
        DB_interface & m_dbi;        
};

#endif /* __DB_H__ */
