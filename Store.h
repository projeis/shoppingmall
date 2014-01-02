    1 #ifndef STORE_H_INCLUDED
    2 #define STORE_H_INCLUDED
    3 
    4 #include "Customer.h"
    5 #include "Item.h"
    6 #include <string>
    7 #include <vector>
    8 
    9 using namespace std;
   10 
   22 class Store {
   23     string name;
   24     static int id;
   25     int store_id;
   26 protected:
   27     vector <Customer*> customers;
   28     vector <Item*> items;
   29 
   30 public:
   40     Store(string s_name) { name = s_name; store_id = id++;}
   41 
   47     void enter(Customer& c);
   48 
   54     void exit(Customer& c);
   55 
   59     void printCustomers();
   60 
   61 
   62     //setter functions
   63     void setStoreName(string s_name) {name = s_name;}
   64 
   65     //getter fuctions
   66     string getStoreName() { return name;}
   67     int getStoreId() { return store_id;}
   68 
   69     //overloading equality operator
   70     Store& operator= (const Store& s);
   71 
   72     virtual void printItems() = 0;
   73 
   79     void addItemtoStore(Item& it);
   80 
   90     bool getItemviaId(int id, Item*& it);
   91 
  101     bool getCustomerFromStore(string c_name, Customer*& c);
  102 };
  103 
  104 #endif // STORE_H_INCLUDED
