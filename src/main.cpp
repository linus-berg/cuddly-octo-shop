#include <stdio.h>
#include "cart.h"
#include "controller.h"

int main() {
  Controller *ctrl = new Controller();
  ctrl->StartSale();
  ctrl->ScanItem("0000000001");
  ctrl->ScanItem("0000000002");
  ctrl->ScanItem("0000000001");
  ctrl->ScanItem("0005");
  ctrl->PrintCart();
  ctrl->FinalizeSale(20);
  delete ctrl;
  /* A lot of watermelon. */
}
