#include "Customer.h"
#include <vector>
#include <algorithm>
#include "Mall.h"


Customer::Customer(string name) {
	c_name = name;
    isCustomerEnteredtoMall = false;
}


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
