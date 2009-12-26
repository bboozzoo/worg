#include <sqlite3.h>
#include <iostream>

int clbk(void * none, int col_count, char ** val, char ** col_name) {
    for (int i = 0; i < col_count; i++) {
        std::cout << "i: " << i << " val: " << ((val[i] != NULL) ? val[i] : "null") << " col: " << col_name[i] << std::endl;
    }
}

int main(int argc, char ** argv) {
    sqlite3 * db;
    char * err;
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " <db file>" << std::endl;
        return 1;
    }
    std::cout << "try open: " << argv[1] << std::endl;
    if (sqlite3_open(argv[1], &db)) {
        std::cerr << "cannot open database " << argv[1] << " reason: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    }
    if (sqlite3_exec(db, "select * from temp;", clbk, NULL, &err)) {
        std::cerr << "error: " << err << std::endl;
        sqlite3_free(err);
    }
    sqlite3_close(db);
    return 0;

}
