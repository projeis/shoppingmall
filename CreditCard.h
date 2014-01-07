#include "Payment.h"


class CreditCard : public Payment {
    string number;
    string type;
    string exp_date;

public:

	
    CreditCard(double, string, string, string);

    //setter functions
    void setCCNumber(string num) {number = num;}
    void setCCType(string t) {type = t;}
    void setCCExpDate(string edate) {exp_date = edate;}

    //getter functions
    string getCCNumber() { return number;}
    string getCCType() { return type;}
    string getExpDate() { return exp_date;}


    void performPayment();
};
