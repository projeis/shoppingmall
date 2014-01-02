 1 #include "ShoeStore.h"
    2 #include <iostream>
    3 using namespace std;
    4 
    9 void ShoeStore::printItems() {
   10 
   11     vector <Item*>::iterator it_item;
   12 
   13     for(it_item = items.begin(); it_item != items.end(); it_item++)
   14     {
   15         cout << "ID : " << (**it_item).getItemId() << "-" << (**it_item).getItemName() << endl;  
   16     }
   17 }
   18 
