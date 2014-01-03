#include "Item.h"

int Item::id = 0;

Item::Item(string it_name, double it_price)
{
    name = it_name;
    price = it_price;
    itemid = id++;
    storeid = 0;
}


