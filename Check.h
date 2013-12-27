#include "Check.h"


Check::Check(double amount, string c_name, int c_bankid) : Payment(amount) {
    name = c_name;
    bankId = c_bankid;
}


void Check::performPayment() {
    double lim = getLimit();
    lim -= getAmount();
    setLimit(lim);
}

