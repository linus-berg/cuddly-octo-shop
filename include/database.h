/** 
* @file database.h 
* @brief Database handling code, specifically for Sqlite3. 
* @author Linus Gunnarsson
* @date 03/05/2018
*/
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
  const std::string desc_;
  const double price_;
  const int stock_;

  /**
  * Create ItemDTO object by pointer.
  * @author Linus Gunnarsson 
  * @param *item Constant pointer of another item.
  * @date 03/05/2018
  */
  ItemDTO(const ItemDTO *item) : ean_(item->ean_), name_(item->name_),
                                 desc_(item->desc_), price_(item->price_),
                                 stock_(item->stock_) {}
  
  /**
  * Create ItemDTO by given parameters.
  * @author Linus Gunnarsson 
  * @param ean EAN code of the item.
  * @param name Name of the item.
  * @param desc Description of the item.
  * @param price Price of the item.
  * @param stock Stock of the item.
  * @date 03/05/2018
  */
  ItemDTO(std::string ean, std::string name, std::string desc, double price, int stock) :
          ean_(ean), name_(name), desc_(desc), price_(price), stock_(stock) {}
};

typedef std::unordered_map<std::string, std::pair<const db::ItemDTO*, int>> cartmap;

class DisplayDTO {
public:
  cartmap::const_iterator begin_;
  cartmap::const_iterator end_;
  const double total_;
  const double paid_;
  const char discount_;
  DisplayDTO(cartmap::const_iterator begin,
             cartmap::const_iterator end, double total,
             double paid, char discount) : begin_(begin), end_(end),
                                           total_(total), paid_(paid),
                                           discount_(discount) {}
};

class CustomerDTO {
public:
  const std::string name_;
  const unsigned char discount_;
  /**
  * Create CustomerDTO by given parameters.
  * @author Linus Gunnarsson 
  * @param name Name of the customer (This is actually a 10-digit ID).
  * @param disc Discount of the customer (0-100).
  * @date 03/05/2018
  */
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
  /**
  * Create SaleDTO by given parameters.
  * @author Linus Gunnarsson 
  * @param worker Worker ID.
  * @param customer Customer ID.
  * @param total Total of the sale.
  * @param discount Customer discount (0-100).
  * @param items Items sold, string, delimited by ','.
  * @param quantity Quantity, string, delimited by ','.
  * @date 03/05/2018
  */
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
  /**
  * Get item from database by EAN code.
  * @author Linus Gunnarsson 
  * @param ean Item EAN.
  * @return Pointer to an ItemDTO object.
  * @date 03/05/2018
  */
  const ItemDTO* GetItem(std::string ean);
  
  /**
  * Get customer from database by id.
  * @author Linus Gunnarsson 
  * @param id Customer id.
  * @return Pointer to a CustomerDTO object.
  * @date 03/05/2018
  */
  const CustomerDTO* GetCustomer(std::string id);
  
  /**
  * Log SaleDTO in the database.
  * @author Linus Gunnarsson 
  * @param *sale SaleDTO to log.
  * @return Sqlite return code.
  * @date 03/05/2018
  */
  int LogSale(SaleDTO *sale);
  
  /**
  * Set stock of item in database.
  * @author Linus Gunnarsson 
  * @param *item Item whos stock should be modified. 
  * @param sold_amount Amount to reduce by. 
  * @return Sqlite return code.
  * @date 03/05/2018
  */
  int SetStock(const ItemDTO *item, int sold_amount);
  
  /**
  * Open sqlite database file.
  * @author Linus Gunnarsson 
  * @param *database Database file to be used (ususally './shop.db'). 
  * @date 03/05/2018
  */
  Database(const char *database);
  ~Database();
};

}
#endif
