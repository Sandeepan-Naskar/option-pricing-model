#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H

class VanillaOption {
    private:
        /* Construction helper methods */
        void init ();
        void copy (const VanillaOption& rhs);
        
        /* Member Data */
        double K; //Strike Price
        double r ; //Risk-free rate (interest)
        double T; // Maturity Time (Expiry of option)
        double S ; // Underlying Asset Price
        double sigma ; //Volatility of underlying asset
    
    public:
        /* Constructors, Destructor, assignment operator */
        VanillaOption();
        VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma);
        VanillaOption(const VanillaOption& rhs); //copy constructor
        VanillaOption& operator=(const VanillaOption& rhs); //assignment operator overload
        virtual ~VanillaOption();
        
        /* getter methods */
        double getK() const;
        double getr() const;
        double getT() const;
        double getS() const;
        double getsigma() const;

        /* Option price calculation methods */
        double calc_call_price() const;
        double calc_put_price() const;

};

#endif