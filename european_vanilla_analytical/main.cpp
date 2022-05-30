#include <cmath>
#include <iostream>
#include "analytical_pricing_utils.h"


int main()
{
    double S{};
    double K{};
    double T{};
    double sigma{};
    double r{};
    double q{};

    S = 50.0;
    K = 50.0;
    T = 0.5;
    sigma = 0.15;
    r = 0.02;
    q = 0.0;

    std::cout << "Underlying:      " << S << '\n';
    std::cout << "Strike:          " << K << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Volatility:      " << sigma << '\n';
    std::cout << "Maturity:        " << T << '\n';
    std::cout << "Call Price: " << bs_option_price_analytical('c', S, K, T, sigma, r, q) << '\n';
    std::cout << "Put Price: " << bs_option_price_analytical('p', S, K, T, sigma, r, q) << '\n';

    return 0;
}