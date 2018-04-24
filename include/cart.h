#ifndef _CART_H
#define _CART_H
#include <unordered_map>
#include <string>
#include <stdio.h>
#include <iostream>

namespace model {
typedef std::unordered_map<std::string, int> cartmap;
class Cart { 
private:
  int total_;
  cartmap cart_;
public:
  void UpdateCart(std::string ean, unsigned short amount);
  cartmap::const_iterator ItBegin();
  cartmap::const_iterator ItEnd();
};
}
#endif
