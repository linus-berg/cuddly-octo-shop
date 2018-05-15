#ifndef _VIEW_H
#define _VIEW_H
#include "controller.h"
#include "database.h"
#include "cart.h"
#include <iostream>
#include <iomanip>
#include "termcolour.hpp"
#include "exceptions.h"

namespace view {
class View {
public:
  void PrintSale(db::DisplayDTO info, bool sale_ended = false) {
    /*
      Well I kind of wanted to implement streams.
      Honestly, what the fuck is this?
    */
    std::cout << termcolor::cyan << termcolor::underline;
    std::cout << "Item" << std::setw(12) << "|"; 
    std::cout << std::setw(11) << "Quantity" << std::setw(2) << "|";
    std::cout << std::setw(6) << "Price" << std::endl;
    std::cout << termcolor::reset; 
    std::cout << std::left;
    for (model::cartmap::const_iterator it = info.begin_; it != info.end_; ++it) {
      std::cout << std::left << std::setw(15) << it->second.first->name_;
      std::cout << termcolor::cyan << "|";
      std::cout << termcolor::magenta;
      std::cout << std::right << std::setw(10) << it->second.second << "x ";
      std::cout << termcolor::reset;
      std::cout << termcolor::cyan << "|" << termcolor::reset;
      std::cout << std::setw(6) << it->second.first->price_ << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(36) << "" << std::endl; 
    std::cout << std::setfill(' ');
    if (info.discount_) {
      std::cout << "Discount:";
      std::cout << termcolor::green << std::setw(26);
      std::cout << static_cast<int>(info.discount_) << "%" << std::endl;
      std::cout << termcolor::reset;
    }
    /* Well, this is a quick fix */
    std::cout << std::left << termcolor::bold;
    std::cout << std::setw(20) << (info.discount_ ? "Total with discount:" : "Total:");
    std::cout << std::right << termcolor::reset;
    std::cout << termcolor::red << std::setw(16);
    std::cout << (info.discount_ ? info.total_ * 1.3 * (1 - info.discount_/100.0) :
                                   info.total_ * 1.3);
    std::cout << termcolor::reset << std::endl;

    std::cout << std::setfill('-') << std::setw(36) << "" << std::endl; 
    std::cout << std::setfill(' ');
    if (sale_ended) {
      std::cout << std::left;
      std::cout << std::setw(22) << "Paid:";
      std::cout << std::right;
      std::cout << std::setw(14) << info.paid_ << std::endl;
      
      std::cout << std::left;
      std::cout << std::setw(22) << "Change:";
      std::cout << std::right;
      std::cout << termcolor::green << std::setw(14);
      std::cout << info.paid_ - (info.discount_ ? info.total_ * 1.3 * (1 - info.discount_/100.0) : info.total_ * 1.3) << std::endl;
      std::cout << termcolor::reset;
      std::cout << std::setfill('-') << std::setw(36) << "" << std::endl; 
      std::cout << std::setfill(' ');
    }
  }

  void Scan(Controller *ctrl, std::string ean) {
    printf("Attempting to scan: %s\n", ean.c_str());
    try {
      ctrl->OnScannedItem(ean);
    } catch (std::exception &e) {
      std::cout << "Exception Warning: " << e.what() << std::endl; 
    }
  }

  View() {
    Controller *ctrl = new Controller();
    ctrl->StartSale();
    printf(" ____________\n");
    printf("|SALE STARTED|\n");
    this->Scan(ctrl, "0000000003");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "0000000002");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "0000000003");
    this->PrintSale(ctrl->GetDisplayInfo());
    this->Scan(ctrl, "Duck.");
    char discount = ctrl->OnReqDiscount("1234567890"); 
    if (discount) {
      printf("Customer has: %d%% discount.\n", discount);
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
