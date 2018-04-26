#ifndef _CTRL_H
#define _CTRL_H
#include "sale.h"
#include "database.h"

class Controller {
private:
  model::Sale *sale_;
  db::Database *database_ = new db::Database("shop.db");
public:
  void StartSale();
  void EndSale(double paid_amount);
  void OnScannedItem(std::string ean);
  void PrintCart();
  void OnReqDiscount(std::string id);
  ~Controller() {
    delete this->sale_;
    delete this->database_;
  }
};

#endif
