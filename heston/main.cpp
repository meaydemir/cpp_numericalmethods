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
    char type{'p'};
    double S0{50};
    double K{50};
    double T{0.5};
    double r{0.02};
    double q{0.0};
    unsigned long long int N{10000}; // Number of steps
    int M{10000}; // Number of simulations

    // Build time array
    std::vector<double> t_array{linspace(0.0, T, N)};
    double dt{t_array[1] - t_array[0]};

    // Stochastic volatility parameters
    double v0{pow(0.15, 2)}; // Starting volatility
    double theta{pow(0.15, 2)}; // Long-term mean volatility
    double kappa{0.5};  // Speed of reversion
    double xi{0.05}; // Volatility of the volatility

    // lambda parameter for multidimensional Girsanov theorem
    double lambda{0.02}; // Needs to be estimate in practice somehow, I choose this arbitrarily for now

    // Generate standard normal random variables under risk-neutral probability measure
    double rho{0.3}; // Correlation between W1 and W2 brownian motions under the risk-neutral probability measure

    std::random_device rd; // random number generator
    std::normal_distribution<> N1(0, 1);
    std::normal_distribution<> N3(0, 1); 
    
    // Variables to hold standard normals generated during path simulation
    double z1{};
    double z2{};

    // Run M number of simulations
    double payoff_total_sum{0};
    double S{};
    double v{};

    for (int h = 0; h < M; h++)
    {
        // Reset initial values
        S = S0;
        v = v0;

        // Generate stock paths under risk neutral measure
        for (std::vector<double>::size_type i = 0; i < t_array.size(); i++)
        {
            // Generate N1 and N3 standard normals
            z1 = N1(rd);
            z2 = rho*z1 + pow(1 - pow(rho, 2), 0.5)*N3(rd); // N2 is correlated to N1
            
            // Update stock path under risk-neutral measure
            S = S + (r - q)*S*dt + S*pow(v*dt, 0.5)*z1;

            // Update stochastic volatility under risk-neutral measure
            v = v + (kappa*theta - (kappa + lambda)*std::max(v, 0.0))*dt + xi*pow(std::max(v, 0.0)*dt, 0.5)*z2;
        }
        
        if (type == 'c')
        {
            payoff_total_sum += std::max(S - K, 0.0);
        }

        else
        {
            payoff_total_sum += std::max(K - S, 0.0);
        }
     
    }

    double option_price{exp(-r*T)*payoff_total_sum/static_cast<double>(M)};
    std::cout << option_price;

    return 0;
}
