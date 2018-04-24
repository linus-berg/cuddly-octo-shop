#include "cart.h"

void model::Cart::UpdateCart(db::ItemDTO *item, unsigned short amount) {
  /* TODO: Everything */
  this->cart_map_.insert({item, amount}); 
}

model::cartmap::const_iterator model::Cart::ItBegin() {
  return this->cart_map_.cbegin();
}

model::cartmap::const_iterator model::Cart::ItEnd() {
  return this->cart_map_.cend();
}
