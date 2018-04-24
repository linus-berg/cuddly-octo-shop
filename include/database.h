#ifndef _DB_H
#define _DB_H
/* Data handling stuff */
#include <sqlite3.h> 
#include <string>

namespace db {

class ItemDTO {
public:
  const std::string ean;
  const std::string name;
  const std::string descr;
  const double price;

  ItemDTO(std::string ean, std::string name, std::string descr, double price) :
          ean(ean), name(name), descr(descr), price(price) {}
};

class Database {
public:
  ItemDTO* GetItem(std::string ean);
};

}
#endif
