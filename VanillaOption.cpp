#ifndef __VANILLA_OPTION_CPP
#define __VANILLA_OPTION_CPP

#include "VanillaOption.h"
#include <cmath>
#include "cdf_normal.cpp"

// Intialises the member data
void VanillaOption::init(){
    K = 100.0;
    r = 0.05;    // 5% interest rate
    T = 1.0;     // One year till maturity
    S = 100.0;   // Options is "at the money" as spot equals the strike
    sigma = 0.2; // 20% volatility
}

// Copies the member data
void VanillaOption::copy(const VanillaOption& rhs){
    K = rhs.getK();
    r = rhs.getr();
    T = rhs.getT();
    S = rhs.getS();
    sigma = rhs.getsigma();
}

VanillaOption::VanillaOption(){
    init();
}

VanillaOption::VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma){
    K = _K;
    r = _r;
    T = _T;
    S = _S;
    sigma = _sigma;
}

// Copy Constructor 
VanillaOption::VanillaOption(const VanillaOption& rhs){
    copy(rhs);
}

// Assignment Operator
VanillaOption& VanillaOption::operator=(const VanillaOption& rhs){
    if (this == &rhs){
        return *this;
    }
    copy(rhs);
    return *this;
}

// Destructor
VanillaOption::~VanillaOption(){ }

// Getters
double VanillaOption::getK() const { return K; }
double VanillaOption::getr() const { return r; }
double VanillaOption::getT() const { return T; }
double VanillaOption::getS() const { return S; }
double VanillaOption::getsigma() const { return sigma; }

// Option price calculators
double VanillaOption::calc_call_price() const {
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1 = ( log(S/K) + (r + sigma * sigma * 0.5) * T ) / sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;

    return S*cdf_normal(d_1) - K * exp(-r*T) * cdf_normal(d_2);
}

double VanillaOption::calc_put_price() const {
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1 = ( log(S/K) + (r + sigma * sigma * 0.5) * T ) / sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;

    return  K * exp(-r*T) * cdf_normal(-d_2) - S*cdf_normal(-d_1);
}

#endif
