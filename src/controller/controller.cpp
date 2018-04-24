#include "controller.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
}

void Controller::FinalizeSale() {
  return;
}

void Controller::ScanItem(std::string ean) {
  db::ItemDTO *item = this->database_->GetItem(ean);
  this->sale_->AddItem(item);
}

void Controller::PrintCart() {
  this->sale_->PrintCart();
}
