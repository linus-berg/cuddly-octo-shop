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

bool Controller::OnScannedItem(std::string ean) {
  const db::ItemDTO *item = this->database_->GetItem(ean);
  if (item != NULL) {
    return this->sale_->AddItem(item);
  } else {
    printf("Invalid EAN-code: %s\n", ean.c_str());
    return false;
  }
}

bool Controller::OnReqDiscount(std::string id) {
  const db::CustomerDTO *cust = this->database_->GetCustomer(id);
  bool ret = false;
  if (cust != NULL && cust->discount_ != 0) {
    printf("Customer has: %d discount.\n", cust->discount_);
    ret = this->sale_->SetDiscount(cust->name_, cust->discount_);
    delete cust;
  } else {
    printf("No discount available\n");
  }
  return ret;
}

db::DisplayDTO Controller::GetDisplayInfo() {
  return this->sale_->GetDisplayInfo();
}
