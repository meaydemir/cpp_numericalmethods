#ifndef IMPLIED_VOL_UTILS_H
#define IMPLIED_VOL_UTILS_H


double vega_bs(double S, double K, double T, double sigma, double r, double q);
double newton_raphson_implied_vol(char type, double mkt_price, double S, double K, double T, double sigma0, double r, double q, double tol=1e-5);

#endif