    1 #include "Item.h"
    2 
   13 class Book : public Item {
   14 
   15 private:
   16     string author;
   17     string publisher;
   18 
   19 public:
   23     Book(string it_name, double it_price, string author, string publisher);
   24 
   25     //setter functions
   26     void setBookAuthor(string a) { author = a;}
   27     void setBookPublisher(string p) { publisher = p;}
   28 
   29     //getter functions
   30     string getBookAuthor() { return author;}
   31     string getBookPublisher() { return publisher;}
   32 
   36     void printProperties();
   37 };
