#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>
using namespace std;

/** 
* @file Item.h 
* @brief Abstract Item class
*        this header file will contain all required definitions and
*        basic functions related with abstract Item class.
*
* @author Erman Yesil
*
* @date 12/22/2012
*/

class Item {

private:
	string name;
	static int id;
    int itemid;
	int storeid;
	double price;

public:
	/**
	 * @brief Constructor
	 * @param name name of the item as string
	 * @param price price of the item as double
	 */
    Item(string name, double price);
	/**
	 * @brief Overloading Constructor
	 */
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
