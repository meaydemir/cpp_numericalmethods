#include <iostream>
#include <cmath>
#include "analytical_pricing_utils.h"
#include "StatisticalDistribution.h"


double vega(char type, double S, double K, double T, double sigma, double r, double q)
{
    if (type == 'c')
    {
        StandardNormal std_norm{};
        return exp(-q*T)*S*pow(T, 0.5)*std_norm.pdf(get_d1_d2_const(1, S, K, T, sigma, r, q));
    }
    else
    {
        return 0;
    }
}

int main()
{
    double S{100};
    double K{100};
    double T{0.5};
    double sigma{0.15};
    double r{0.02};
    double q{0.0};

    //double c_price_mkt{2.36229}; // Market price of option
    std::cout << vega('c', S, K, T, sigma, r, q);

    return 0;
}