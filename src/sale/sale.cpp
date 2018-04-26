#include "sale.h"
#include "database.h"
#include <iostream>

void model::Sale::AddItem(const db::ItemDTO *item) {
  this->cart_->UpdateCart(item, 1);
}

void model::Sale::SetDiscount(std::string customer, char discount) {
  this->customer_ = customer;
  this->discount_ = discount;
}

void model::Sale::Finalize(db::Database *db, double paid_amount) {
  std::string items = "";
  std::string quantity = "";
  for (model::cartmap::const_iterator it = cart_->ItBegin(); it != cart_->ItEnd(); it++) {
    items += it->second.first->ean_ + (next(it) != cart_->ItEnd() ? "," : "");
    quantity += std::to_string(it->second.second) + (next(it) != cart_->ItEnd() ? "," : "");
    db->SetStock(it->second.first, it->second.second);
  }
  db->LogSale(new db::SaleDTO(this->worker_, this->customer_, this->cart_->GetTotal(),
                                this->discount_, items, quantity));
  this->PrintCart();
  printf("Paid: %10s$%.2f\n", "", paid_amount);
  printf("Change: %8s$%.2f\n", "", paid_amount - this->cart_->GetTotal());
  printf("-----------------------------------\n");
}

void model::Sale::PrintCart() {
  printf("-----------------------------------\n");
  printf("|%18s%16s\n", "CART", "|");
  printf("-----------------------------------\n");
  printf("%-14s ¦ %10s ¦ %5s\n", "Item", "Quantity", "Price");
  printf("-----------------------------------\n");
  for (model::cartmap::const_iterator it = cart_->ItBegin(); it != cart_->ItEnd(); it++) {
    printf("%-14s ¦ %9dx ¦ %-10.2f\n", it->second.first->name_.c_str(),
                                       it->second.second, it->second.first->price_);
  }
  printf("-----------------------------------\n");
  if (this->discount_) {
    printf("Discount: %20s, %d%\n", "Yes", this->discount_);
  }
  printf("Total%s: %9s$%.2f\n", this->discount_ ? " With Discount" : "", "",
         this->discount_ ? this->cart_->GetTotal() * (1 - this->discount_/100.0) :
                           this->cart_->GetTotal());
  printf("-----------------------------------\n");
}
