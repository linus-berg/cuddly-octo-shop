#ifndef _SALE_H
#define _SALE_H
#include <string>
#include "cart.h"

namespace model {

class Sale {
private:
  std::string customer_;
  char discount_ = 0;
  Cart *cart_;
  /* Hardcoded worker id */
  const int worker_ = 1;
public:
  bool AddItem(const db::ItemDTO *item);
  void Finalize(db::Database *db, double paid_amount);
  bool SetDiscount(std::string customer, char discount);
  void PrintCart();
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
