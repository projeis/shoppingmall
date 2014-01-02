1 #include "ShoppingCard.h"
    2 #include <iostream>
    3 using namespace std;
    4 
    5 void ShoppingCard::addItemToCard(ItemToPurchase& itpurchase)
    6 {
    7     itemsToPurchase.push_back(itpurchase);
    8 }
    9 
   10 void ShoppingCard::removeItemFromCard(int itemid)
   11 {
   12     vector <ItemToPurchase>::iterator it_topurchase;
   13 
   14     for(it_topurchase = itemsToPurchase.begin(); it_topurchase != itemsToPurchase.end(); it_topurchase++)
   15     {
   16         if(((*it_topurchase).getItem())->getItemId() == itemid)
   17         {
   18             itemsToPurchase.erase(itemsToPurchase.begin() + distance(itemsToPurchase.begin(),it_topurchase));
   19             break;
   20         }
   21     }   
   22 }
   23 
   24 void ShoppingCard::printItems()
   25 {
   26     vector <ItemToPurchase>::iterator it_topurchase;
   27 
   28     for(it_topurchase = itemsToPurchase.begin(); it_topurchase != itemsToPurchase.end(); it_topurchase++)
   29     {
   30         cout << (*it_topurchase).getQuantity() << " pieces of " << ((*it_topurchase).getItem())->getItemName() 
   31              << "(Item id : " << ((*it_topurchase).getItem())->getItemId() << ")" << endl;
   32     }   
   33 }
   34 
   35 double ShoppingCard::calculateTotalPrice()
   36 {
   37     double totalprice = 0;
   38     vector <ItemToPurchase>::iterator it_topurchase;
   39 
   40     for(it_topurchase = itemsToPurchase.begin(); it_topurchase != itemsToPurchase.end(); it_topurchase++)
   41     {
   42         totalprice += (*it_topurchase).getQuantity() * ((*it_topurchase).getItem())->getItemPrice();
   43     }
   44 
   45     return totalprice;
   46 }
   47 
   48 void ShoppingCard::placeOrder() {
   49 
   50     
   51 }
   52 
   53 void ShoppingCard::cancelOrder() {
   54     itemsToPurchase.erase(itemsToPurchase.begin(), itemsToPurchase.end());
   55 }
   56 
