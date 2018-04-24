#include "controller.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
  printf(" ____________\n");
  printf("|SALE STARTED|\n");
}

void Controller::FinalizeSale(double paid_amount) {
  /* Pay shit */
  this->sale_->Finalize(paid_amount); 
}

void Controller::ScanItem(std::string ean) {
  const db::ItemDTO *item = this->database_->GetItem(ean);
  if (item != NULL) {
    this->sale_->AddItem(item);
  } else {
    printf("Invalid item: %s\n", ean.c_str());
  }
}

void Controller::PrintCart() {
  this->sale_->PrintCart();
}
