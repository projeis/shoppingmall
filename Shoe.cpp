#include "Shoe.h"
#include <iostream>


Shoe::Shoe(string it_name, double it_price, int shoe_number, string shoe_gender) : Item(it_name, it_price) {
    number = shoe_number;
    gender = shoe_gender;
}


void Shoe::printProperties() {
	cout << "Shoe name : " << getItemName() << endl;
    cout << "Shoe price : " << getItemPrice() << " TL" << endl;
    cout << "Shoe size : " << getShoeNumber() << endl;
    cout << "Shoe gender : " << getShoeGender() << endl;
}
