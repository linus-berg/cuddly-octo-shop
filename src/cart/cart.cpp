#include "cart.h"

void model::Cart::UpdateCart(const db::ItemDTO *item, unsigned short amount) {
  this->total_ += item->price_ * amount;
  if (this->cart_map_.find(item->ean_) != this->cart_map_.end()) {
    /* Quick dirty fix for the compiler not finding insert_or_assing??? */
    int old_amount = this->cart_map_[item->ean_].second;
    delete this->cart_map_[item->ean_].first;
    this->cart_map_.erase(this->cart_map_.find(item->ean_));
    this->cart_map_.insert({item->ean_, std::make_pair(item,
                                                       old_amount + amount)}); 
  } else {
    this->cart_map_.insert({item->ean_, std::make_pair(item, amount)}); 
  }
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
