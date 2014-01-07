#include "Item.h"



class Shoe : public Item {

private:
	int number;
	string gender;

public:
	
    Shoe(string it_name, double it_price, int number, string gender);

    //setter functions
    void setShoeNumber(int n) { number = n;}
    void setShoeGender(string s) { gender = s;}

    //getter functions
    int getShoeNumber() { return number;}
    string getShoeGender() { return gender;}

	
	void printProperties();

};
