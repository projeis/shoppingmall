#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>
using namespace std;


class Item {

private:
	string name;
	static int id;
    int itemid;
	int storeid;
	double price;

public:
	
    Item(string name, double price);
	
    Item(){};

    // setter functions
    void setItemName(string it_name) { name = it_name;}
    void setStoreId(int id) {storeid = id;}
    void setItemPrice(double it_price) {price = it_price;}
    void setItemId(int id) {itemid = id;}

    // getter functions
    string getItemName() { return name;}
    int getItemId() { return itemid;}
    int getStoreId() { return storeid;}
    double getItemPrice() { return price;}

    //! pure virtual function
    virtual void printProperties() = 0;
};

#endif // ITEM_H_INCLUDED
