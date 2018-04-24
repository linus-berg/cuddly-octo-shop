#include <stdio.h>
#include "cart.h"
#include "controller.h"

int main() {
  Controller *ctrl = new Controller();
  ctrl->StartSale();
  ctrl->ScanItem("0001");
  ctrl->ScanItem("0002");
  ctrl->ScanItem("0003");
  ctrl->PrintCart();

  /* A lot of watermelon. */
}
