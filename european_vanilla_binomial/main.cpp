#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "binomial_utils.h"
#include <chrono>

int main()
{
    // Specify input parameters
    double S0{50};
    double K{50};
    double T{0.5};
    double sigma{0.15};
    double r{0.02};
    double div_q{0.0};
    unsigned long long int N{10000}; // Number of steps
   
    std::cout << "Number of Steps: " << N << std::endl;
    std::cout << "Underlying:      " << S0 << '\n';
    std::cout << "Strike:          " << K << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Volatility:      " << sigma << '\n';
    std::cout << "Maturity:        " << T << '\n';

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::cout << "Call Price: " << get_bs_price_binomial('c', S0, K, T, sigma, r, div_q, N) << '\n';
    std::cout << "Put Price: " << get_bs_price_binomial('p', S0, K, T, sigma, r, div_q, N) << '\n';
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
} 