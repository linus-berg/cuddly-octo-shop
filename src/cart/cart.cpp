#include "cart.h"

bool model::Cart::UpdateCart(const db::ItemDTO *item, unsigned short amount) {
  if (this->cart_map_.find(item->ean_) != this->cart_map_.end()) {
    int old_amount = this->cart_map_[item->ean_].second;
    if (item->stock_ - (amount + old_amount) < 0 && !DEBUG_CART) {
      printf("Error: not enough of the item in stock, item not added to cart.\n");
      return 0;
    }
    /* Quick dirty fix for the compiler not finding insert_or_assing??? */
    delete this->cart_map_[item->ean_].first;
    this->cart_map_.erase(this->cart_map_.find(item->ean_));
    this->cart_map_.insert({item->ean_, std::make_pair(item,
                                                       old_amount + amount)}); 
  } else {
    if (item->stock_ - amount < 0 && !DEBUG_CART) {
      printf("Error: not enough of the item in stock, item not added to cart.\n");
      return 0;
    }
    this->cart_map_.insert({item->ean_, std::make_pair(item, amount)}); 
  }
  this->total_ += item->price_ * amount;
  return 1;
}

double model::Cart::GetTotal() {
  return this->total_;
}

model::cartmap::const_iterator model::Cart::ItBegin() {
  return this->cart_map_.cbegin();
}

model::cartmap::const_iterator model::Cart::ItEnd() {
  return this->cart_map_.cend();
}
