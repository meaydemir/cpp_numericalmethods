#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "binomial_utils.h"


int main()
{
    // Specify input parameters
    double S0{100};
    double K{100};
    double T{1};
    double sigma{0.2};
    double r{0.05};
    double div_q{0.0};
    unsigned long long int N{10000}; // Number of steps
   
    std::cout << "Number of Steps: " << N << std::endl;
    std::cout << "Underlying:      " << S0 << '\n';
    std::cout << "Strike:          " << K << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Volatility:      " << sigma << '\n';
    std::cout << "Maturity:        " << T << '\n';
    std::cout << "Call Price: " << get_bs_price_binomial('c', S0, K, T, sigma, r, div_q, N) << '\n';
    std::cout << "Put Price: " << get_bs_price_binomial('p', S0, K, T, sigma, r, div_q, N) << '\n';

    return 0;
} 