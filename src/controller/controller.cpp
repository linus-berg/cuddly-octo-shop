#include "controller.h"
#include "exceptions.h"

void Controller::StartSale() {
  this->sale_ = new model::Sale();
}

void Controller::EndSale(double paid_amount) {
  /* Pay shit */
  this->sale_->Finalize(database_, paid_amount);
}

bool Controller::OnScannedItem(std::string ean) {
  try {
    /* GetItem throws database_item_not_found if no item is found */
    const db::ItemDTO *item = this->database_->GetItem(ean);
  } catch (std::exception &e) {
    /* Throw new error to view. */
    throw error::database_item_not_found(e.what());
  }
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
