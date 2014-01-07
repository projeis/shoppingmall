#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED

#include <string>
using namespace std;


class Payment {
    double amount;
    double limit;

public:

    Payment(double p_amount) {amount = p_amount;}

    //setter functions
    void setAmount(double a) { amount = a;}
    void setLimit(double s) {limit = s;}
    
    //getter functions
    double getAmount() { return amount;}
    double getLimit() { return limit;}


    virtual void performPayment () = 0;
};

#endif PAYMENT_H_INCLUDED
