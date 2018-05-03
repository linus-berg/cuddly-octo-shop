#ifndef _VIEW_H
#define _VIEW_H
#include "controller.h"
#include "database.h"
#include "cart.h"
namespace view {
class View {
public:
  void PrintSale(db::DisplayDTO info, bool sale_ended = false) {
    printf("-----------------------------------\n");
    printf("|%18s%16s\n", "CART", "|");
    printf("-----------------------------------\n");
    printf("%-14s ¦ %10s ¦ %5s\n", "Item", "Quantity", "Price");
    printf("-----------------------------------\n");
    for (model::cartmap::const_iterator it = info.begin_; it != info.end_; ++it) {
      printf("%-14s ¦ %9dx ¦ %-10.2f\n", it->second.first->name_.c_str(),
                                         it->second.second, it->second.first->price_);
    }
    printf("-----------------------------------\n");
    if (info.discount_ && sale_ended) {
      printf("Discount: %20s, %d%\n", "Yes", info.discount_);
    }
    printf("Total%s: %9s$%.2f\n", info.discount_ ? " With Discount" : "", "",
           info.discount_ ? info.total_ * 1.3 * (1 - info.discount_/100.0) :
                            info.total_ * 1.3);
    printf("-----------------------------------\n");
    if (sale_ended) {
      printf("Paid: %10s$%.2f\n", "", info.paid_);
      printf("Change: %8s$%.2f\n", "", info.paid_ - (info.total_ * 1.3));
      printf("-----------------------------------\n");
    }
  }
  void Scan(Controller *ctrl, std::string ean) {
    printf("Attempting to scan: %s\n", ean.c_str());
    if (!ctrl->OnScannedItem(ean)) {
      printf("Invalid EAN-code: %s\n", ean.c_str());
    }
  }
  View() {
    Controller *ctrl = new Controller();
    ctrl->StartSale();
    printf(" ____________\n");
    printf("|SALE STARTED|\n");
    this->Scan(ctrl, "0000000001");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "0000000002");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "0000000001");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "Fucking duck.");
    char discount = ctrl->OnReqDiscount("1234567890"); 
    if (discount) {
      printf("Customer has: %d discount.\n", discount);
    } else {
      printf("No discount available\n");
    }
    /*
    Get stuff to display
    */
    this->PrintSale(ctrl->GetDisplayInfo());
    ctrl->EndSale(20);
    this->PrintSale(ctrl->GetDisplayInfo(), true);
    
    delete ctrl;
  }
};
}
#endif
