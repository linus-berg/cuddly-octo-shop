#include <stdio.h>
#include "cart.h"
#include "controller.h"

int main() {
  Controller *ctrl = new Controller();
  ctrl->StartSale();
  ctrl->OnScannedItem("0000000001");
  ctrl->OnScannedItem("0000000002");
  ctrl->OnScannedItem("0000000001");
  ctrl->OnScannedItem("Fucking duck.");
  ctrl->OnReqDiscount("1234567890");
  ctrl->PrintCart();
  ctrl->EndSale(20);
  delete ctrl;
  /* A lot of watermelon. */
}
