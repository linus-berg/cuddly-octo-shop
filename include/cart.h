#ifndef _CART_H
#define _CART_H
#define DEBUG_CART 0 
#include <unordered_map>
#include <string>
#include <stdio.h>
#include "database.h"

namespace model {
typedef std::unordered_map<std::string, std::pair<const db::ItemDTO*, int>> cartmap;
class Cart { 
private:
  double total_ = 0;
  cartmap cart_map_;
public:
  bool UpdateCart(const db::ItemDTO *item, unsigned short amount);
  double GetTotal();
  cartmap::const_iterator ItBegin();
  cartmap::const_iterator ItEnd();
  ~Cart() {
    for (cartmap::iterator it = cart_map_.begin(); it != cart_map_.end(); it++) {
      delete it->second.first;
    }
  }
};
}
#endif
