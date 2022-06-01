#ifndef StatisticalDistribution_H
#define StatisticalDistribution_H

#include <cmath>


class StatisticalDistribution
{
public:
    StatisticalDistribution(); // constructor
    virtual ~StatisticalDistribution(); // destructor

    virtual double pdf(const double& x) = 0; // pure virtual method
    virtual double cdf(const double& x) = 0; // pure virtual method
};


class StandardNormal: public StatisticalDistribution
{
public:
    StandardNormal(); // constructor
    virtual ~StandardNormal(); // destructor

    double pdf(const double& x); // PDF for standard normal
    double cdf(const double& x);
};


#endif

// #ifndef StatisticalDistribution_H
// #define StatisticalDistribution_H

// #include <cmath>
// const double M_PI = 3.14159265358979323846;

// class StatisticalDistribution
// {
// public:
//     StatisticalDistribution(); // constructor
//     virtual ~StatisticalDistribution(); // destructor

//     virtual double pdf(const double& x) = 0; // pure virtual method
//     virtual double cdf(const double& x) = 0; // pure virtual method

// };


// class StandardNormal: public StatisticalDistribution
// {
// public:
//     StandardNormal(); // constructor
//     virtual ~StandardNormal(); // destructor

//     double pdf(const double& x); // PDF for standard normal
//     double cdf(const double& x);

// };


// StatisticalDistribution::StatisticalDistribution() {}
// StatisticalDistribution::~StatisticalDistribution() {}

// StandardNormal::StandardNormal() {}
// StandardNormal::~StandardNormal() {}

// double StandardNormal::pdf(const double& x) // PDF for standard normal
// {
//     return 1.0/pow(2*M_PI, 0.5)*exp(-0.5*pow(x, 2));
// }


// double StandardNormal::cdf(const double& x) {
//     double k = 1.0/(1.0 + 0.2316419*x);
//     double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

//     if (x >= 0.0) {
//         return (1.0 - (1.0/(pow(2*M_PI, 0.5)))*exp(-0.5*pow(x, 2)) * k_sum);
//     } else {
//         return 1.0 - StandardNormal::cdf(-x);
//     }
// }


// #endif