#include <stdio.h>
#include "cart.h"
#include "controller.h"

int main() {
  Controller *ctrl = new Controller();
  ctrl->StartSale();
  ctrl->ScanItem("0000000001");
  ctrl->ScanItem("0000000002");
  ctrl->ScanItem("0000000001");
  ctrl->ScanItem("Fucking duck.");
  ctrl->ReqDiscount("1234567890");
  ctrl->PrintCart();
  ctrl->FinalizeSale(20);
  delete ctrl;
  /* A lot of watermelon. */
}
