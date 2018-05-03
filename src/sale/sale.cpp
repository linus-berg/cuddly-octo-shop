#include "sale.h"
#include "database.h"
#include <iostream>

bool model::Sale::AddItem(const db::ItemDTO *item) {
  return this->cart_->UpdateCart(item, 1);
}

bool model::Sale::SetDiscount(std::string customer, char discount) {
  this->customer_ = customer;
  this->discount_ = discount;
  return this->discount_;
}

void model::Sale::Finalize(db::Database *db, double paid_amount) {
  std::string items = "";
  std::string quantity = "";
  this->paid_ = paid_amount;

  for (model::cartmap::const_iterator it = cart_->ItBegin(); it != cart_->ItEnd(); it++) {
    items += it->second.first->ean_ + (next(it) != cart_->ItEnd() ? "," : "");
    quantity += std::to_string(it->second.second) + (next(it) != cart_->ItEnd() ? "," : "");
    db->SetStock(it->second.first, it->second.second);
  }
  db->LogSale(new db::SaleDTO(this->worker_, this->customer_, this->cart_->GetTotal(),
                              this->discount_, items, quantity));
}

db::DisplayDTO model::Sale::GetDisplayInfo() {
  return db::DisplayDTO(cart_->ItBegin(), cart_->ItEnd(), this->cart_->GetTotal(),
                        this->paid_, this->discount_);
}
