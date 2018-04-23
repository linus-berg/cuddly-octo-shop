#include "cart.h"

void model::Cart::UpdateCart(std::string ean, unsigned short amount) {
  /* TODO: Everything */
  cart_.insert({ean, amount}); 
}

model::cartmap::const_iterator model::Cart::ItBegin() {
  return cart_.cbegin();
}

model::cartmap::const_iterator model::Cart::ItEnd() {
  return cart_.cend();
}
