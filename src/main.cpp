#include <stdio.h>
#include "cart.h"

int main() {
  model::Cart *cart = new model::Cart();
  /* A lot of watermelon. */
  cart->UpdateCart("Watermelon", 512); 
  for (model::cartmap::const_iterator it = cart->ItBegin(); it != cart->ItEnd();
       it++)
    {
      printf("Contains: %s\n", (it->first).c_str());
    }
  delete cart;
}
