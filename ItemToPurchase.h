#ifndef ITEMTOPURCHASE_H_INCLUDED
#define ITEMTOPURCHASE_H_INCLUDED

#include "Item.h"


class ItemToPurchase {
private:
    Item* item;
    int quantity;

public:

    //setter functions
    void setItem(Item& it);
    void setQuantity(int q) { quantity = q;}

    //getter functions
    Item* getItem() { return item;}
    int getQuantity() { return quantity;}
};

#endif //ITEMTOPURCHASE_H_INCLUDED
