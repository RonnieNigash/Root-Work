#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>

bool quadratic(double a, double b, double c, double& positive, double& negative)
{
	double det = b*b-4.0*a*c;
	if (det < 0){	
		return false;
	}
	positive = (-1*b+sqrt(det))/(2.0*a);
	negative = (-1*b-sqrt(det))/(2.0*a);
	return true;
}

double multiply(double a, double b)
{
	return a*b;
}

void print(double a)
{
	std::cout << "Result = " << a << std::endl;
}

int main()
{
	double a, b, c;

	double pos;
	double neg;
	std::cout << "Quadratic Formula. Please enter a, b, c coefficients: ";
	std::cin >> a >> b >> c;
	printf("Our function is: %fx^2+%fx+%f\n", a, b, c);
	if(quadratic(a,b,c,pos,neg)){
		printf("Our positive root is: %f\n", pos);
		printf("Our negative root is: %f", neg);
	} else {
		printf("No solutions found.");
	}
	return 0;
}
