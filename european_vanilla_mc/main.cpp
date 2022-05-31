#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <vector>
#include "mc_utils.h"


int main()
{
    // Specify number of paths to simulate
    unsigned long long int N{10000000};

    // Specify input parameters
    double S0{50};
    double K{50};
    double T{0.5};
    double sigma{0.15};
    double r{0.02};
    double q{0.0};

    std::cout << "Underlying:      " << S0 << '\n';
    std::cout << "Strike:          " << K << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Volatility:      " << sigma << '\n';
    std::cout << "Maturity:        " << T << '\n';
    std::cout << "Call Price: " << get_bs_mc_option_price(N, 'c', S0, K, T, sigma, r, q) << '\n';
    std::cout << "Put Price: " << get_bs_mc_option_price(N, 'p', S0, K, T, sigma, r, q) << '\n';
    return 0;
}