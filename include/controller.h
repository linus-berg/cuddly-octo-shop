/** 
* @file controller.h 
* @brief Contains the controller class and all methods related to controlling the
* rest of the program. 
* @author Linus Gunnarsson
* @date 03/05/2018
*/
#ifndef _CTRL_H
#define _CTRL_H
#include "database.h"
#include "sale.h"

class Controller {
private:
  model::Sale *sale_ = NULL;
  db::Database *database_ = new db::Database("./shop.db");
public:
  /**
  * Start a sale by creating a new Sale object.
  * @author Linus Gunnarsson 
  * @date 03/05/2018
  */
  void StartSale();
  
  /**
  * Finalize the sale by entering the amount the customer paid.
  * @author Linus Gunnarsson 
  * @param paid_amount Important: Always assumed to be >= total of the sale.
  * @date 03/05/2018
  */
  void EndSale(double paid_amount);
  
  /**
  * On scanning an item this function is called by the theoretical 'view'.
  * @author Linus Gunnarsson 
  * @param ean EAN code of the item that was scanned, error checking occurs.
  * @return True if item was scanned and added succesfully.
  * @date 03/05/2018
  */
  bool OnScannedItem(std::string ean);
  
  /**
  * Print cart content.
  * @author Linus Gunnarsson 
  * @date 03/05/2018
  */
  db::DisplayDTO GetDisplayInfo();
  
  /**
  * If the customer requests a discount, do stuff based on the customer id.
  * @author Linus Gunnarsson 
  * @param id The customer id.
  * @return True if customer has discount.
  * @date 03/05/2018
  */
  bool OnReqDiscount(std::string id);
  
  /**
  * On controller destruction, obliterate the rest of the program, Boom.
  * @author Linus Gunnarsson 
  * @date 03/05/2018
  */
  ~Controller() {
    if (sale_ != NULL) {
      delete this->sale_;
    }
    delete this->database_;
  }
};

#endif
