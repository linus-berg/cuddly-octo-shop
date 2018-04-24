#include "sale.h"
#include "database.h"

void model::Sale::AddItem(db::ItemDTO *item) {
  this->cart_->UpdateCart(item, 2);
}

void model::Sale::PrintCart() {
  double total = 0;
  printf("-----------------------------------\n");
  printf("|%18s%16s\n", "CART", "|");
  printf("-----------------------------------\n");
  printf("%-14s ¦ %10s ¦ %5s\n", "Item", "Quantity", "Price");
  printf("-----------------------------------\n");
  for (model::cartmap::const_iterator it = cart_->ItBegin(); it != cart_->ItEnd(); it++) {
    printf("%-14s ¦ %9dx ¦ -10.2f\n", (it->first)->name.c_str(),
                                         (it->second), (it->first)->price);
    total += (it->first)->price * (it->second);
  }
  printf("-----------------------------------\n");
  printf("Total: $%.2f\n", total); 
  printf("-----------------------------------\n");
}
