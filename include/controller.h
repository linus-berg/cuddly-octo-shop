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
  void FinalizeSale(double paid_amount);
  void ScanItem(std::string ean);
  void PrintCart();

  ~Controller() {
    delete this->sale_;
    delete this->database_;
  }
};

#endif
