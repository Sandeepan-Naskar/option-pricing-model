#ifndef __PAY_OFF_H
#define __PAY_OFF_H

#include <algorithm>

class PayOff {   
    public:
        /* Constructors, Destructor, assignment operator */
        PayOff();
        virtual double operator() (const double S) const = 0; //Overloaded operator() turns PayOff into an abstract function object
        virtual ~PayOff();
};

class PayOffCall : public PayOff{   
    private:
        double K; //strike price
    public:
        /* Constructors, Destructor, assignment operator */
        PayOffCall(const double K_) {};
        virtual double operator() (const double S) const; //Overloaded operator() turns PayOff into an abstract function object
        virtual ~PayOffCall();
};

class PayOffPut : public PayOff{   
    private:
        double K; //strike price
    public:
        /* Constructors, Destructor, assignment operator */
        PayOffPut(const double K_) {};
        virtual double operator() (const double S) const; //Overloaded operator() turns PayOff into an abstract function object
        virtual ~PayOffPut();
};

// Implement PayOffDigitalCall //
// Implement PayOffDigitalPut //
// Implement Power Option //

class PayOffDoubleDigital : public PayOff{   
    private:
        double U; //Upper strike price
        double D; //Lower strike price
    public:
        /* Constructors, Destructor, assignment operator */
        PayOffDoubleDigital(const double U_, const double D_) {};
        virtual double operator() (const double S) const; //Overloaded operator() turns PayOff into an abstract function object
        virtual ~PayOffDoubleDigital();
};

#endif