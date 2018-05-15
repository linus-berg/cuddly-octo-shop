#include "display.h"
#include "stdio.h"

void Display::PrintRevenue(double new_rev) {
  printf("Revenue: %f\n", new_rev); 
}

void TotalRevenueView::SaleEnded(double new_rev) {
  this->PrintRevenue(new_rev);
}