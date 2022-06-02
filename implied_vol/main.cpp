#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> // std::stringstream
#include "implied_vol_utils.h"


int main()
{
    // Input parameters (SPY ETF as of 6/1/2022)
    double S{409.59};
    double T{0.08219178082};
    double sigma0{0.2}; // initial guess
    double r{0.0208};
    double q{0.0};
    double tol{1e-10};

    // Read CSV into vectors
    std::ifstream inputFile;
    inputFile.open("spy_option_data.csv");

    std::vector<std::string> date_vec;
    std::vector<double> c_mid_vec;
    std::vector<double> p_mid_vec;
    std::vector<double> k_vec;

    int iter_{0};
    std::string line;
    while (getline(inputFile, line))
    {
        if (iter_ == 0) // Omit column names
        {
            iter_ ++;
            continue;
        }

        std::string tempString;
        std::stringstream inputString(line);
        getline(inputString, tempString, ',');
        date_vec.push_back(tempString);

        // Strike
        getline(inputString, tempString, ',');
        k_vec.push_back(atof(tempString.c_str()));

        // Call & Put mid prices
        getline(inputString, tempString, ',');
        c_mid_vec.push_back(atof(tempString.c_str()));

        getline(inputString, tempString, ',');
        p_mid_vec.push_back(atof(tempString.c_str()));
    }

    // Output results
    std::cout << "Underlying:      " << S << '\n';
    std::cout << "Risk-Free Rate:  " << r << '\n';
    std::cout << "Maturity:        " << T << '\n';
    for (std::vector<double>::size_type i = 0; i < k_vec.size(); i++)
    {
        std::cout << "Implied Volatility for Call with market price " << c_mid_vec[i] << " and strike " << k_vec[i] << ": " << newton_raphson_implied_vol('c', c_mid_vec[i], S, k_vec[i], T, sigma0, r, q, tol) << '\n';
    }

    std::cout << "\n\n";

    for (std::vector<double>::size_type i = 0; i < k_vec.size(); i++)
    {
        std::cout << "Implied Volatility for Put with market price " << p_mid_vec[i] << " and strike " << k_vec[i] << ": " << newton_raphson_implied_vol('p', p_mid_vec[i], S, k_vec[i], T, sigma0, r, q, tol) << '\n';
    }

    return 0;
}