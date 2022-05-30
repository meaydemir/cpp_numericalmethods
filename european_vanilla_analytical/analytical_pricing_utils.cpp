#ifndef Analytical_Pricing_Utils_CPP
#define Analytical_Pricing_Utils_CPP

#include <cmath>
#include "analytical_pricing_utils.h"
#include "StatisticalDistribution.h"


double get_d1_d2_const(int x, const double& S, const double& K, const double& T,
                       const double& sigma, const double& r, const double& q){
    if (x == 1) // d1
    {
        return (log(S/K) + (r - q + pow(sigma, 2)/2)*T)/(sigma*pow(T, 0.5));
    }
    
    else // d2
    {
        return (log(S/K) + (r - q + pow(sigma, 2)/2)*T)/(sigma*pow(T, 0.5)) - sigma*pow(T, 0.5);
    }
}


double bs_option_price_analytical(char type, const double& S, const double& K, const double& T,
                                   const double& sigma, const double& r, const double& q)
    {
        StandardNormal std_norm{};

        if (type == 'c')
        {
            return S*exp(-q*T)*std_norm.cdf(get_d1_d2_const(1, S, K, T, sigma, r, q)) - K*exp(-r*T)*std_norm.cdf(get_d1_d2_const(2, S, K, T, sigma, r, q));
        }
        else
        {
            return S*exp(-q*T)*std_norm.cdf(get_d1_d2_const(1, S, K, T, sigma, r, q)) - K*exp(-r*T)*std_norm.cdf(get_d1_d2_const(2, S, K, T, sigma, r, q)) - S*exp(-q*T) + K*exp(-r*T);
        }
    }   




#endif