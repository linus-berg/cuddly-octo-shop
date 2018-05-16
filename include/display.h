#ifndef _DISPLAY_H
#define _DISPLAY_H
class Display {
protected:
  void PrintRevenue(double revenue);
public:
  virtual void SaleEnded(double new_rev) = 0;
};

class TotalRevenueView : public Display {
  void SaleEnded(double new_rev);
};
#endif
