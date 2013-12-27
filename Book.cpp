    1 #include "Book.h"
    2 #include <iostream>
    3 
   12 Book::Book(string it_name, double it_price, string b_author, string b_publisher) : Item(it_name, it_price) {
   13     author = b_author;
   14     publisher = b_publisher;
   15 }
   16 
   20 void Book::printProperties() {
   21     cout << "Book name : " << getItemName() << endl;
   22     cout << "Book price : " << getItemPrice() << endl;
   23     cout << "Book author : " << getBookAuthor() << endl;
   24     cout << "Book Publisher : " << getBookPublisher() << endl;
   25 }
