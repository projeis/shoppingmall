#include <iostream> 
#include "Mall.h"
#include "Customer.h"
#include <vector>
#include <algorithm>

using namespace std;

void Mall::enter(Customer& c) {
	customers.push_back(&c);
    c.setEntertoMallStatus(true);
}

void Mall::exit(Customer& c) {
	
	vector <Customer*>::iterator it_customer;

	for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
	{
		if((**it_customer).getCustomerName() == c.getCustomerName())
		{
			customers.erase(customers.begin() + distance(customers.begin(),it_customer));
            c.setEntertoMallStatus(false);
			break;
		}
	}
}

vector<Customer*> Mall::getCustomers() {
	return customers;
}

void Mall::printCustomers() {

    vector <Customer*>::iterator it_customer;

    if(customers.size() == 0)
    {
        cout << "There are no customers at the mall right now! Please add customer from main menu!" << endl;
        return;
    }

	for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
	{
		cout << distance(customers.begin(),it_customer)+1 << ". " << (**it_customer).getCustomerName() << endl; 
	}
}

void Mall::printStores() {
	vector <Store*>::iterator it_store;

	for(it_store = stores.begin(); it_store != stores.end(); it_store++)
	{
		cout << "ID: "<< (**it_store).getStoreId() << " " << (**it_store).getStoreName() << endl; 
	}	
}

vector<Store*> Mall::getStores() {
	return stores;
}

void Mall::addStore(Store& s) {
	stores.push_back(&s);
}

void Mall::setMallName(string m_name) {
	name = m_name;
}

bool Mall::getStoreviaId(int id, Store*& s)
{
	vector <Store*>::iterator it_store;

	for(it_store = stores.begin(); it_store != stores.end(); it_store++)
	{
		if((**it_store).getStoreId() == id)
		{
			//customers.erase(customers.begin() + distance(stores.begin(), it_store));
			s = *it_store;
			return true;
		}
	}

	return false;
}

bool Mall::getCustomerFromMall(string c_name, Customer*& c)
{
	vector <Customer*>::iterator it_customer;

	for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
	{
		if((**it_customer).getCustomerName() == c_name)
		{
			//customers.erase(customers.begin() + distance(customers.begin(),it_customer));
			c = *it_customer;
            return true;
		}
	}
    return false;
}
