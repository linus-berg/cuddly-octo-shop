#include "display.h"
#include "stdio.h"

void Display::PrintRevenue(double revenue) {
  printf("Total Revenue: %f\n", revenue); 
}

void TotalRevenueView::SaleEnded(double new_rev) {
  this->PrintRevenue(new_rev);
}
