/** 
* @file sale.h 
* @brief Contains all things related to the sale objects. 
* @author Linus Gunnarsson
* @date 03/05/2018
*/
#ifndef _SALE_H
#define _SALE_H
#include <string>
#include "cart.h"
#include "database.h"

namespace model {

class Sale {
private:
  std::string customer_;
  char discount_ = 0;
  double paid_ = 0;
  Cart *cart_;
  /* Hardcoded worker id */
  const int worker_ = 1;
public:
  /**
  * Add item to cart_.
  * @author Linus Gunnarsson 
  * @param *item Item pointer to ItemDTO to add.
  * @return True if item succesfully added to cart_.
  * @date 03/05/2018
  */
  bool AddItem(const db::ItemDTO *item);
  
  /**
  * Finalize the sale.
  * @author Linus Gunnarsson 
  * @param *db Database to modify with finalized sale info.
  * @param paid_amount Amount paid.
  * @date 03/05/2018
  */
  void Finalize(db::Database *db, double paid_amount);
  
  /**
  * Set the discount based on the customer data.
  * @author Linus Gunnarsson 
  * @param customer Customer ID.
  * @param discount Discount percentage (0-100).
  * @date 03/05/2018
  */
  bool SetDiscount(std::string customer, char discount);
  db::DisplayDTO GetDisplayInfo();
  /* Finalize */
  Sale() {
    this->cart_ = new Cart();
  }
  ~Sale() {
    delete this->cart_;
  }
};

}

#endif
