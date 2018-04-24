#ifndef _SALE_H
#define _SALE_H
#include <string>
#include "cart.h"

namespace model {

class Sale {
private:
  bool discount = false;
  Cart *cart_;

public:
  void AddItem(db::ItemDTO *item);
  bool SetDiscount();
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
