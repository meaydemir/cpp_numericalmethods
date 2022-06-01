#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "binomial_utils.h"


std::vector<double> linspace(double start, double end, unsigned long long int N)
{   
    std::vector<double> v(N);
    for (std::vector<double>::size_type i = 0; i <= v.size(); i++)
    {
        v[i] = start + i*(end - start)/static_cast<double>(N);
    }

    return v;
}


double iterate_tree(std::vector<double>& v_curr,
                    double r, double dt, double p, double q)
{

    unsigned long long int N{v_curr.size()};
    unsigned long long int j{0};
    double discount_factor{exp(-r*dt)};

    while(j < N)
    {
        for (std::vector<double>::size_type i = 0; i < N - j - 1; i++)
        {
            v_curr[i] = discount_factor*(p*v_curr[i] + q*v_curr[i+1]); // Calculate the value at each node
        }
        j++;
    }

    return v_curr[0];
}


double get_bs_price_binomial(char type, double S0, double K, double T, double sigma, 
                             double r, double div_q, unsigned long long int N)
{
    // Specified up/down constants allow convergence to black-scholes solution
    double u{exp(sigma*pow(T/static_cast<double>(N), 0.5))};
    double d{1.0/u};

    // Build time array
    std::vector<double> t_array{linspace(0.0, T, N)};
    double dt{t_array[1] - t_array[0]};

    // Risk-neutral probabilities
    double p{(exp((r - div_q)*dt)-d)/(u-d)};
    double q{1 - p};

    // Initialize with boundary conditions
    std::vector<double> v_curr(N + 1);
    for (std::vector<double>::size_type i = 0; i < v_curr.size(); i++)
    {
        if (type == 'c')
        {
            v_curr[i] = std::max(S0*pow(u, (N-i))*pow(d, i) - K, 0.0);
        }
        else
        {
            v_curr[i] = std::max(K - S0*pow(u, (N-i))*pow(d, i), 0.0);
        }
    }

    // Calculate BS option price by iterating backwards through binomial tree
    return iterate_tree(v_curr, r, dt, p, q);
}
