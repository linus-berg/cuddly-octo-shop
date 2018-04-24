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

class CustomerDTO {
public:
  const std::string name_;
};


class Database {
private:
  sqlite3 *db_;
  sqlite3_stmt *stmt_;
public:
  const ItemDTO* GetItem(std::string ean);
  Database(const char *database);
  ~Database();
};

}
#endif
