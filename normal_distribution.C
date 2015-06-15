// Normal Distribution
//
//
#include <iostream>
#include <random>

int main()
{

	const int num_experiments = 10000;
	const int num_stars = 100;

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(5.0, 2.0);

	int p[10] = {};

	for (int i = 0; i < num_experiments; ++i) {

		double number = distribution(generator);
		if ( (number >= 0.0) && (number < 10.0))
				++p[int(number)];
	}

	std::cout << "normal_distribution (5.0, 2.0): " << std::endl;

	for (int i = 0; i < 10; ++i) {

		std::cout << i << "-" << (i+1) << ": ";
		std::cout << std::string(p[i]*num_stars/num_experiments, '*') << std::endl;

	}

	return 0;

}
