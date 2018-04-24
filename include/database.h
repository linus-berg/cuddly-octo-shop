#ifndef _DB_H
#define _DB_H
/* Data handling stuff */
#include <sqlite3.h> 
#include <string>

namespace db {

class ItemDTO {
private:
  std::string ean;
  std::string name;
  std::string descr;
  double price;
public:
  ItemDTO(std::string ean, std::string name, std::string descr, double price) :
          ean(ean), name(name), descr(descr), price(price) {}
};

class Database {
public:
  ItemDTO GetItem();
};

}
#endif
