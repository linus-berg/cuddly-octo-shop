#ifndef _CART_H
#define _CART_H
#include <unordered_map>
#include <string>
#include <stdio.h>
#include <iostream>
#include "database.h"

namespace model {
typedef std::unordered_map<db::ItemDTO*, int> cartmap;
class Cart { 
private:
  int total_;
  cartmap cart_map_;
public:
  void UpdateCart(db::ItemDTO *item, unsigned short amount);
  cartmap::const_iterator ItBegin();
  cartmap::const_iterator ItEnd();
};
}
#endif
