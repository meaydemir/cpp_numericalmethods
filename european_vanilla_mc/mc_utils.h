#ifndef MC_UTILS_H
#define MC_UTILS_H


#include <iostream>


std::vector<double> generate_gbm_paths(const unsigned long long int& N, const double& S0,
                                       const double& T, const double& sigma, const double& r, 
                                       const double& q);

#endif