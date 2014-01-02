 1 #include <iostream>
    2 #include "Store.h"
    3 #include <algorithm>
    4 /*
    5 Store::Store(string s_name, int s_id)
    6 {
    7     name = s_name;
    8     id = s_id;
    9 }*/
   10 
   11 int Store::id = 0;
   12 
   13 void Store::enter(Customer& c)
   14 {
   15     (&c)->setCStoreId(this->getStoreId());
   16     customers.push_back(&c);    
   17 }
   18 
   19 void Store::exit(Customer& c) {
   20     
   21     vector <Customer*>::iterator it_customer;
   22 
   23     for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
   24     {
   25         if((**it_customer).getCustomerName() == c.getCustomerName())
   26         {
   27             customers.erase(customers.begin() + distance(customers.begin(),it_customer));
   28             break;
   29         }
   30     }
   31 }
   32 
   33 /*void Store::printItems() {
   34     throw "Not yet implemented";
   35 }*/
   36 
   37 void Store::printCustomers()
   38 {
   39     vector <Customer*>::iterator it_customer;
   40 
   41     for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
   42     {
   43         cout << distance(customers.begin(),it_customer)+1 << ". " << (**it_customer).getCustomerName() << endl; 
   44     }
   45 }
   46 
   47 void Store::addItemtoStore(Item& it)
   48 {
   49     items.push_back(&it);
   50 }
   51 
   52 bool Store::getItemviaId(int id, Item*& it)
   53 {
   54     vector <Item*>::iterator it_item;
   55 
   56     for(it_item = items.begin(); it_item != items.end(); it_item++)
   57     {
   58         if((**it_item).getItemId() == id)
   59         {
   60             //customers.erase(customers.begin() + distance(stores.begin(), it_store));
   61             it = *it_item;
   62             return true;
   63         }
   64     }
   65 
   66     return false;
   67 }
   68 
   69 bool Store::getCustomerFromStore(string c_name, Customer*& c)
   70 {
   71     vector <Customer*>::iterator it_customer;
   72 
   73     for(it_customer = customers.begin(); it_customer != customers.end(); it_customer++)
   74     {
   75         if((**it_customer).getCustomerName() == c_name)
   76         {
   77             //customers.erase(customers.begin() + distance(customers.begin(),it_customer));
   78             c = *it_customer;
   79             return true;
   80         }
   81     }
   82     return false;
   83 }
   84 
   85 Store& Store::operator=(const Store& s)
   86 {
   87     name = s.name;
   88     id = s.id;
   89 
   90     return *this;
   91 }
