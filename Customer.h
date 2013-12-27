#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "ShoppingCard.h"
#include <string>
using namespace std;

/** 
* @file Customer.h 
* @brief this header file will contain all required definitions and
*        basic functions related with Customer class.
*
* @author Suheda Toplu
*
* @date 01/2/2012
*/

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

	/**
	 * @brief gets the value of flag which indicates whether customer
	 *        has entered to mall or not
	 * @return false if customer has not entered to mall
	 *         true if he or she entered to mall
	 */
    bool getEntertoMallStatus() { return isCustomerEnteredtoMall;}

	/**
	 * @brief returns shopping card of customer
	 * @return ShoppingCard object
	 */
    ShoppingCard* getShoppingCard() { return shop_card;}
};

#endif
