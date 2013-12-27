#include "Payment.h"


class Check : public Payment {
    string name;
    int bankId;
public:

	
    Check(double, string, int);
    // setter functions
    void setBankName(string n) {name = n;}
    void setBankId(int b) {bankId = b;}

    // getter functions
    string getBankName() { return name;}
    int getBankId() { return bankId;}


    void performPayment();
};
