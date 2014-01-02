  1 #ifndef SHOPPINGCARD_H_INCLUDED
    2 #define SHOPPINGCARD_H_INCLUDED
    3 
    4 #include "ItemToPurchase.h"
    5 #include "Payment.h"
    6 #include <vector>
    7 #include <algorithm>
    8 
   20 class ShoppingCard {
   21     Payment* payment;
   22 
   23 protected:
   24     vector <ItemToPurchase> itemsToPurchase;
   25 
   26 public:
   27     
   28     // setter functions
   29     void setPayment(Payment& pay) {payment = &pay;}
   30 
   31     // getter functions
   32     Payment* getPayment() {return payment;}
   33 
   39     void addItemToCard(ItemToPurchase& itpurchase);
   40 
   46     void removeItemFromCard(int itemid);
   47 
   51     void printItems();
   52 
   57     void placeOrder();
   58 
   63     void cancelOrder();
   64 
   71     double calculateTotalPrice();
   72 
   73 };
   74 
   75 #endif SHOPPINGCARD_H_INCLUDED
