#include "controller.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
  printf(" ____________\n");
  printf("|SALE STARTED|\n");
}

void Controller::EndSale(double paid_amount) {
  /* Pay shit */
  this->sale_->Finalize(database_, paid_amount);
}

void Controller::OnScannedItem(std::string ean) {
  const db::ItemDTO *item = this->database_->GetItem(ean);
  if (item != NULL) {
    this->sale_->AddItem(item);
  } else {
    printf("Invalid EAN-code: %s\n", ean.c_str());
  }
}

void Controller::OnReqDiscount(std::string id) {
  const db::CustomerDTO *cust = this->database_->GetCustomer(id);
  if (cust != NULL && cust->discount_ != 0) {
    printf("Customer has: %d discount.\n", cust->discount_);
    this->sale_->SetDiscount(cust->name_, cust->discount_);
    delete cust;
  } else {
    printf("No discount available\n");
  }
}

void Controller::PrintCart() {
  this->sale_->PrintCart();
}
