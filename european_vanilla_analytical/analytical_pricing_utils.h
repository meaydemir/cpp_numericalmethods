#ifndef Analytical_Pricing_Utils_H
#define Analytical_Pricing_Utils_H


double get_d1_d2_const(int x, const double& S, const double& K, const double& T,
                       const double& sigma, const double& r, const double& q);


double bs_option_price_analytical(char type, const double& S, const double& K, const double& T,
                                   const double& sigma, const double& r, const double& q);

#endif