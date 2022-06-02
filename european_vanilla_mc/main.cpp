#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <vector>
#include "mc_utils.h"


int main()
{
    // Specify number of paths to simulate
    unsigned long long int N{100000};

    // Specify input parameters
    double S0{100};
    double K{100};
    double T{1};
    double sigma{0.2};
    double r{0.05};
    double q{0.0};

    std::cout << "Number of Paths: " << N << std::endl;
    std::cout << "Underlying:      " << S0 << '\n';
    std::cout << "Strike:          " << K << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Volatility:      " << sigma << '\n';
    std::cout << "Maturity:        " << T << '\n';
    std::cout << "Call Price: " << get_bs_mc_option_price(N, 'c', S0, K, T, sigma, r, q) << '\n';
    std::cout << "Put Price: " << get_bs_mc_option_price(N, 'p', S0, K, T, sigma, r, q) << '\n';
    return 0;
}