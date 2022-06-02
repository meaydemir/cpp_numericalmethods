#include <cmath>
#include <stdlib.h>
#include "analytical_pricing_utils.h"
#include "StatisticalDistribution.h"
#include "implied_vol_utils.h"


double vega_bs(double S, double K, double T, double sigma, double r, double q)
{
    StandardNormal std_norm{};
    return exp(-q*T)*S*pow(T, 0.5)*std_norm.pdf(get_d1_d2_const(1, S, K, T, sigma, r, q));
}


double newton_raphson_implied_vol(char type, double mkt_price, double S, double K, double T, double sigma0, double r, double q, double tol)
{
    // Initialize variables
    double bs_price_old{bs_option_price_analytical(type, S, K, T, sigma0, r, q)};
    double bs_mkt_diff{bs_price_old - mkt_price}; // To avoid repeated calculations in While condition
    double sigma_new{-bs_price_old/vega_bs(S, K, T, sigma0, r, q) + sigma0}; // First new value (to be updated iteratively later) 

    // Iterate using Newton-Raphson method
    while (abs(bs_mkt_diff/mkt_price) > tol)
    {
        bs_price_old = bs_option_price_analytical(type, S, K, T, sigma_new, r, q);
        bs_mkt_diff = bs_price_old - mkt_price;
        sigma_new = -bs_mkt_diff/vega_bs(S, K, T, sigma_new, r, q) + sigma_new;
    }

    return sigma_new;
}