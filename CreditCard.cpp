#include "CreditCard.h"


CreditCard::CreditCard(double amount, string cc_number, string cc_type, string cc_expdate) : Payment(amount) {
    number = cc_number;
    type = cc_type;
    exp_date = cc_expdate;
}


void CreditCard::performPayment() {
    double lim = getLimit();
    lim -= getAmount();
    setLimit(lim);
}
