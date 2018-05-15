#include "controller.h"
#include "exceptions.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
}

void Controller::EndSale(double paid_amount) {
  if (!this->testing_) {
    this->rev_.AddRevenue(this->sale_->GetDiscount() ?
                          this->sale_->GetTotal() * 1.3 * (1 - this->sale_->GetDiscount()/100.0) :
                          this->sale_->GetTotal() * 1.3);
  }
  this->sale_->Finalize(database_, paid_amount);
}

bool Controller::OnScannedItem(std::string ean) {
  /* GetItem throws database_item_not_found if no item is found */
  const db::ItemDTO *item = this->database_->GetItem(ean);
  return this->sale_->AddItem(item);
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
