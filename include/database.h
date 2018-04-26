#ifndef _DB_H
#define _DB_H
/* Data handling stuff */
#include <sqlite3.h> 
#include <string>
#include <unordered_map>

namespace db {

class ItemDTO {
public:
  const std::string ean_;
  const std::string name_;
  const std::string descr_;
  const double price_;
  const int stock_;

  ItemDTO(const ItemDTO *item) : ean_(item->ean_), name_(item->name_),
                                 descr_(item->descr_), price_(item->price_),
                                 stock_(item->stock_) {}
  ItemDTO(std::string ean, std::string name, std::string descr, double price, int stock) :
          ean_(ean), name_(name), descr_(descr), price_(price), stock_(stock) {}
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
  sqlite3_stmt *stmt_i_;
  int rc_ = 0;
public:
  const ItemDTO* GetItem(std::string ean);
  const CustomerDTO* GetCustomer(std::string id);
  int LogSale(SaleDTO *sale);
  int SetStock(const ItemDTO *item, int sold_amount);
  Database(const char *database);
  ~Database();
};

}
#endif
