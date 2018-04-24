#include "sale.h"
#include "database.h"

void model::Sale::AddItem(const db::ItemDTO *item) {
  this->cart_->UpdateCart(item, 1);
}

void model::Sale::Finalize(double paid_amount) {
  this->PrintCart();
  printf("Change: $%.2f\n", paid_amount - this->cart_->GetTotal());
  printf("-----------------------------------\n");
}

void model::Sale::PrintCart() {
  printf("-----------------------------------\n");
  printf("|%18s%16s\n", "CART", "|");
  printf("-----------------------------------\n");
  printf("%-14s ¦ %10s ¦ %5s\n", "Item", "Quantity", "Price");
  printf("-----------------------------------\n");
  for (model::cartmap::const_iterator it = cart_->ItBegin(); it != cart_->ItEnd(); it++) {
    printf("%-14s ¦ %9dx ¦ %-10.2f\n", (it->second).first->name_.c_str(), (it->second).second,
                                       (it->second).first->price_);
  }
  printf("-----------------------------------\n");
  printf("Total: $%.2f\n", this->cart_->GetTotal()); 
  printf("-----------------------------------\n");
}
