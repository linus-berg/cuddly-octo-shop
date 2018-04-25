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
  const unsigned char discount_;
  CustomerDTO(std::string name, unsigned char disc) : name_(name), discount_(disc) {
  }
};

class SaleDTO {
public:
  const int worker_;
  const std::string customer_;
  const double total_;
  const char discount_;
  const std::string items_;
  const std::string quantity_;
  SaleDTO(int worker, std::string customer, double total, char discount,
          std::string items, std::string quantity) : worker_(worker), customer_(customer),
                                                     total_(total), discount_(discount),
                                                     items_(items), quantity_(quantity) {
  }
};

class Database {
private:
  sqlite3 *db_;
  sqlite3_stmt *stmt_;
  sqlite3_stmt *stmt_c_;
  sqlite3_stmt *stmt_s_;
public:
  const ItemDTO* GetItem(std::string ean);
  const CustomerDTO* GetCustomer(std::string id);
  void  StoreSale(SaleDTO *sale);
  Database(const char *database);
  ~Database();
};

}
#endif
