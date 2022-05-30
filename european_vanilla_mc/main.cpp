#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include "mc_utils.h"


int main()
{
    // Specify number of paths to simulate
    unsigned long long int N{10};

    // Specify input parameters
    double S0{50};
    double K{50};
    double T{0.5};
    double sigma{0.15};
    double r{0.02};
    double q{0.0};

    // Generate GBM paths
    std::vector<double> s_vec{generate_gbm_paths(N, S0, T, sigma, r, q)};

    // Calculate payoffs
    std::vector<double> payoff_vec(N, 0);
    for (std::vector<double>::size_type i = 0; i < s_vec.size(); i++)
    {
        payoff_vec[i] = std::max(s_vec[i] - K, 0.0);
        std::cout << payoff_vec[i] << '\n';
    }

    return 0;
}