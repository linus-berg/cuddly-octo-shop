#include "controller.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
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
    return false;
  }
}

char Controller::OnReqDiscount(std::string id) {
  const db::CustomerDTO *cust = this->database_->GetCustomer(id);
  char ret = 0;
  if (cust != NULL && cust->discount_ != 0) {
    this->sale_->SetDiscount(cust->name_, cust->discount_);
    ret = cust->discount_;
    delete cust;
  }
  return ret;
}

db::DisplayDTO Controller::GetDisplayInfo() {
  return this->sale_->GetDisplayInfo();
}
