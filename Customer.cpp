#include "Customer.h"
#include <vector>
#include <algorithm>
#include "Mall.h"

/**
 * @brief Constructor
 *        A flag which shows whether customer has entered 
 *        to mall or not will be set as false by default.
 * @param name customer name as string
 */
Customer::Customer(string name) {
	c_name = name;
    isCustomerEnteredtoMall = false;
}

/**
 * @brief Overloading Constructor
 *        A flag which shows whether customer has entered 
 *        to mall or not will be set as false by default.
 * @param name customer name as string
 * @param storeid id of store which customer has entered as integer
 */
Customer::Customer(string name, int storeid) {
	c_name = name;
	c_storeid = storeid;
    isCustomerEnteredtoMall = false;
}

//setter functions
void Customer::setCName(string name)
{
	c_name = name;
}

void Customer::setCStoreId(int storeid)
{
	c_storeid = storeid;
}

//getter functions
string Customer::getCustomerName() {
    return c_name;
}

int Customer::getCStoreId()
{
	return c_storeid;
}
