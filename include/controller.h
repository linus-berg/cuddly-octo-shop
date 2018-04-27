#ifndef _CTRL_H
#define _CTRL_H
#include "sale.h"
#include "database.h"

class Controller {
private:
  model::Sale *sale_ = NULL;
  db::Database *database_ = new db::Database("./shop.db");
public:
  void StartSale();
  void EndSale(double paid_amount);
  bool OnScannedItem(std::string ean);
  void PrintCart();
  bool OnReqDiscount(std::string id);
  ~Controller() {
    if (sale_ != NULL) {
      delete this->sale_;
    }
    delete this->database_;
  }
};

#endif
