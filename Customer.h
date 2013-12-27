#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "ShoppingCard.h"
#include <string>
using namespace std;



class Customer {
	string c_name;
	int c_storeid;
    ShoppingCard* shop_card;
    bool isCustomerEnteredtoMall;

public:
	Customer(string);
	Customer(string, int);
	//~Customer();

	//setter functions
	void setCStoreId(int storeid);
	void setCName(string name);
    void setEntertoMallStatus(bool value){isCustomerEnteredtoMall = value;}
    void setShoppingCard(ShoppingCard* s_card) {shop_card = s_card;}

	//getter functions
	string getCustomerName();
    int getCStoreId();

	
    bool getEntertoMallStatus() { return isCustomerEnteredtoMall;}

	
    ShoppingCard* getShoppingCard() { return shop_card;}
};

#endif
