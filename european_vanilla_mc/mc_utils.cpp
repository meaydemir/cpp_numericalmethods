#include <iostream>
#include <cmath>
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
            std::cout<< path << '\n';
        }

        return s_vec;
    }