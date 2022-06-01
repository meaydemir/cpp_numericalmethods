#ifndef BINOMIAL_UTILS_H
#define BINOMIAL_UTILS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


std::vector<double> linspace(double start, double end, unsigned long long int N);


double iterate_tree(std::vector<double>& v_curr,
                    double r, double dt, double p, double q);


double get_bs_price_binomial(char type, double S0, double K, double T, double sigma, 
                             double r, double div_q, unsigned long long int N);

#endif