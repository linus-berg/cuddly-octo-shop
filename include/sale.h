#ifndef _SALE_H
#define _SALE_H
#include <string>
#include "cart.h"

namespace model {

class Sale {
private:
  bool discount = false;
  Cart cart_;

public:
  void AddItem(std::string item);
  bool SetDiscount();
  /* Finalize */
  Sale() {
    cart_ = new Cart();
  }
  ~Sale() {
    delete cart_;
  }
};

}

#endif
