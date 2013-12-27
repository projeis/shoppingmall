    1 #include "Store.h"
    2 
   13 class BookStore : public Store {
   14 
   15 
   16 public:
   17 
   27     BookStore(string name) : Store(name){};
   28 
   33     void printItems();
   34 };
