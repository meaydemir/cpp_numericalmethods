#include <iostream>
#include <random>


int main()
{
    // Specify number of paths to simulate
    int N{10};

    // Create vector for storing standard normal random variables
    std::vector<double> std_norm_vec;
    std_norm_vec.reserve(N);

    // Generate standard normal random variables and store in vector
    std::random_device rd; // random number generator
    std::normal_distribution<> std_normal_object(0, 1); // standard normal object instantiation
    for (int i = 0; i < N; i++)
    {
        std_norm_vec[i] = std_normal_object(rd);
        std::cout<< std_norm_vec[i] << '\n';
    }

    return 0;
}