#ifndef MALL_H_INCLUDED
#define MALL_H_INCLUDED

#include "Customer.h" 
#include "Store.h"
#include <vector>

using namespace std;

/
class Mall {
	string name;
	vector <Store*> stores;
	vector <Customer*> customers;

public:

	void enter(Customer& c);


	void exit(Customer& c);


	vector <Customer*> getCustomers();

	
	void printCustomers();

	
	void printStores();


	vector <Store*> getStores();

	void setMallName(string name);
	
	string getMallName() {return name;}

	
	void addStore(Store &s);


	bool getStoreviaId(int id, Store*& s);
	

	bool getCustomerFromMall(string c_name, Customer*& c);
};

#endif // MALL_H_INCLUDED
