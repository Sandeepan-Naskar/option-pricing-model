#ifndef __PAY_OFF_CPP
#define __PAY_OFF_CPP

#include "PayOff.h"
#include "iostream"
using namespace std;

// PAY OFF CALL Implementation
PayOffCall::PayOffCall(const double _K) { K=_K; }
PayOffCall::~PayOffCall() {}

double PayOffCall::operator() (const double S) const {
    return max(S-K, 0.0);
}

// PAY OFF PUT Implementation
// PAY OFF DIGITAL CALL Implementation
// PAY OFF DIGITAL PUT Implementation
// PAY OFF POWER OPTION Implementation


// PAY Double Digital Implementation
PayOffDoubleDigital::PayOffDoubleDigital(const double _U, const double _D) {
    U = _U;
    D = _D;
}
PayOffDoubleDigital::~PayOffDoubleDigital() {}

double PayOffDoubleDigital::operator() (const double S) const {
    if (S>=D && S<=U) {
        return 1.0;
    } else  {
        return 0.0;
    }
}

#endif
