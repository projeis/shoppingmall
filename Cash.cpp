   1 #include "Cash.h"
    2 
    8 void Cash::performPayment() {
    9     double lim = getLimit();
   10     lim -= getAmount();
   11     setLimit(lim);
   12 }
