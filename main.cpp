#include <stdio.h>
#include "include/cart.h"

int main() {
  model::Cart *cart = new model::Cart();
  cart->UpdateCart("", 0); 
  for (model::cartmap::const_iterator it = cart->ItBegin(); it != cart->ItEnd();
       it++)
    {
      printf("Contains shit like: %s\n", (it->first).c_str());
    }
}
