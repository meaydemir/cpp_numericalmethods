#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include "StatisticalDistribution.h"
#include "binomial_utils.h"


int main()
{
    // Specify input parameters
    double S{50};
    //double K{50};
    double T{0.5};
    double r{0.02};
    double q{0.0};
    unsigned long long int N{4}; // Number of steps

    // Stochastic volatility parameters
    double v(0.15); // Starting volatility
    double theta(0.15); // Long-term mean volatility
    double kappa(0.5);  // Speed of reversion
    double xi(0.05); // Volatility of the volatility

    // Correlation between W1 and W2 brownian motions
    double rho{0.3};

    // Build time array
    std::vector<double> t_array{linspace(0.0, T, N)};
    double dt{t_array[1] - t_array[0]};

    // Generate standard normal random variables
    std::random_device rd; // random number generator
    std::normal_distribution<> N1(0, 1); // standard normal object instantiation

    // N2 = rho*N1 + sqrt(1-rho^2)*N3
    std::normal_distribution<> N3(0, 1); // standard normal object instantiation for brownian motion W3
    
    // Variables to hold standard normals generated during path simulation
    double z1{};
    double z2{};

    for (std::vector<double>::size_type i = 0; i < t_array.size(); i++)
    {
        // Generate N1 and N3 standard normals
        z1 = N1(rd);
        z2 = rho*z1 + pow(1-pow(rho, 2), 0.5)*N3(rd);
        
        // Update stochastic volatility
        S = S + (r - q)*dt + S*pow(v*dt, 0.5)*z1;
        v = kappa*(theta - std::max(v, 0.0))*dt + xi*pow(std::max(v, 0.0)*dt, 0.5)*z2;
        std::cout << S << '\n';
        std::cout << v << '\n';
        
    }

    return 0;
}
