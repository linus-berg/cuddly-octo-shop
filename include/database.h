#ifndef _DB_H
#define _DB_H
/* Data handling stuff */
#include <sqlite3.h> 
#include <string>
#include <unordered_map>
#include <iostream>
namespace db {

class ItemDTO {
public:
  const std::string ean_;
  const std::string name_;
  const std::string descr_;
  const double price_;

  ItemDTO(const ItemDTO *item) : ean_(item->ean_), name_(item->name_),
                                 descr_(item->descr_), price_(item->price_) {}
  ItemDTO(std::string ean, std::string name, std::string descr, double price) :
          ean_(ean), name_(name), descr_(descr), price_(price) {}
};

class Database {
private:
  sqlite3 *db_;
  sqlite3_stmt *stmt_;
public:
  const ItemDTO* GetItem(std::string ean);
  Database(const char *database) {
    /* Dangerous, no error checking. Fuck it. */
    sqlite3_open_v2(database, &db_, SQLITE_OPEN_READONLY, NULL);
    sqlite3_prepare_v2(db_, "SELECT * FROM items WHERE ean=?1", -1, &stmt_, NULL);
  }
};

}
#endif
