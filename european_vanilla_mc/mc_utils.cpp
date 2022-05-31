#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>

std::vector<double> generate_gbm_paths(const unsigned long long int& N, const double& S0,
                                       const double& T, const double& sigma, const double& r, 
                                       const double& q)
    {
        // Create vector for storing GBM paths for stock under risk-neutral measure
        std::vector<double> s_vec(N, 0);

        // Generate standard normal random variables and store in vector
        std::random_device rd; // random number generator
        std::normal_distribution<> std_normal_object(0, 1); // standard normal object instantiation

        for (auto& path : s_vec)
        {
            path = S0*exp((r - q - 0.5*pow(sigma, 2))*T + sigma*pow(T, 0.5)*std_normal_object(rd));
        }

        return s_vec;
    }


double get_bs_mc_option_price(const unsigned long long int& N, const char& type,
                              const double& S0, const double& K, const double& T, 
                              const double& sigma,
                              const double& r, const double& q)
    {
        // Generate GBM paths
        std::vector<double> s_vec{generate_gbm_paths(N, S0, T, sigma, r, q)};

        // Calculate payoffs
        double payoff_sum{0};
        for (auto ST : s_vec)
        {
            if (type == 'c')
            {
                payoff_sum += std::max(ST - K, 0.0);
            }
            else
            {
                payoff_sum += std::max(K - ST, 0.0);
            }
        }

        // Calculate average discounted payoff under risk neutral measure
        return 1.0/s_vec.size()*exp(-r*T)*payoff_sum;
    }