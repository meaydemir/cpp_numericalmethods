#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


std::vector<double> linspace(double start, double end, unsigned long long int N)
{   
    std::vector<double> v(N);
    for (std::vector<double>::size_type i = 0; i <= v.size(); i++)
    {
        v[i] = start + i*(end - start)/static_cast<double>(N);
        //std::cout << v[i] << '\n';
    }

    return v;
}


int main()
{
    // Specify input parameters
    double S0{100};
    double K{100};
    double T{1};
    double sigma{0.2};
    double r{0.05};
    double div_q{0.0};
    unsigned long long int N{1}; // Number of steps

    // Specified up/down constants allow convergence to black-scholes solution
    double u{exp(sigma*pow(T/static_cast<double>(N), 0.5))};
    double d{1.0/u};
    std::cout << u << '\n';
    std::cout << d << '\n';
   
    // Build time array
    std::vector<double> t_array{linspace(0.0, T, N)};
    double dt{t_array[1] - t_array[0]};

    // Risk-neutral probabilities
    double p{(exp((r - div_q)*dt)-d)/(u-d)};
    double q{1 - p};

    // Initialize with boundary conditions
    std::vector<double> v_curr(pow(2, N));
    for (std::vector<double>::size_type i = 0; i <= N; i++)
    {
        v_curr[i] = std::max(S0*pow(u, (N-i))*pow(d, i) - K, 0.0);
        std::cout << v_curr[i] << '\n';
    }
    std::cout << v_curr.size() << '\n';
    std::cout << q << '\n';


    return 0;
} 