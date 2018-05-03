/** 
* @file cart.h 
* @brief Contains the cart class and all methods related to dealing with the cart. 
* @author Linus Gunnarsson
* @date 03/05/2018
*/

#ifndef _CART_H
#define _CART_H
#define DEBUG_CART 0 
#include <unordered_map>
#include <string>
#include <stdio.h>
#include "database.h"

namespace model {
typedef std::unordered_map<std::string, std::pair<const db::ItemDTO*, int>> cartmap;

class Cart { 
private:
  double total_ = 0;
  cartmap cart_map_;
public:
  /**
  * This method updates the cart with given ItemDTO and adds amount to the quantity.
  * @author Linus Gunnarsson 
  * @param *item Item to add.
  * @param amount Amount to increase quantity by.
  * @return bool True if item was added succesfully.
  * @date 03/05/2018
  */
  bool UpdateCart(const db::ItemDTO *item, unsigned short amount);
  
  /**
  * Get total of cart.
  * @author Linus Gunnarsson 
  * @return Total amount.
  * @date 03/05/2018
  */
  double GetTotal();
 
  /**
  * Get iterator beginning from cart hashmap.
  * @author Linus Gunnarsson
  * @return Constant iterator to the beginning of the cart hashmap.
  * @date 03/05/2018
  */
  cartmap::const_iterator ItBegin();
  
  /**
  * Get iterator ending from cart hashmap.
  * @author Linus Gunnarsson 
  * @return Constant iterator to the end of the cart hashmap.
  * @date 03/05/2018
  */
  cartmap::const_iterator ItEnd();
  
  /**
  * On cart destruction, clean up all memory reserved by the pointers in the cart map.
  * @author Linus Gunnarsson 
  * @date 03/05/2018
  */
  ~Cart() {
    for (cartmap::iterator it = cart_map_.begin(); it != cart_map_.end(); it++) {
      delete it->second.first;
    }
  }
};
}
#endif
