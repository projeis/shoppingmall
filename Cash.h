  1 #include "Payment.h"
    2 
   13 class Cash : public Payment {
   14 
   15 public:
   20     Cash(double amount) : Payment(amount) {};
   21     void performPayment();
   22 
   23 };
