#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>

void bubbleSort(int *ptr, int k)
{
	int temp;
	for (int i = 1; i < k; i++) {
		for (int j = 0; j < (k - 1); j++) {
			if (*(ptr + j) > *(ptr + j + 1)){
				temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}
	}
}

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

void sum(double a, double b, double& result)
{
	result = a + b;
}

void multiply(double a, double b, double& result)
{
	result = a*b;
}
void print(double a)
{
	std::cout << "Result = " << a << std::endl;
}





int main()
{
	double a, b, c, result;
	double pos;
	double neg;
	printf("Let's do some simple operations! Enter two numbers: ");
	std::cin >> a >> b;
	sum(a, b, result);
	printf("\nThe sum of %.1f and %.1f is: %.2f", a, b, result);
	multiply(a, b, result);
	printf("\nThe product of %.1f and %.1f is: %.2f", a, b, result);


	printf("\nLet's do some Quadratic Formula! Enter coefficients a, b ,c: ");
	std::cin >> a >> b >> c;
	printf("Our function is: %.1fx^2+%.1fx+%.1f\n", a, b, c);
	if(quadratic(a,b,c,pos,neg)){
		printf("Our positive root is: %.1f\n", pos);
		printf("Our negative root is: %.1f\n", neg);
	} else {
		printf("No solutions found.\n");
	}

	printf("\nLet's sort some arrays with Bubble Sort!\n");
	int list[10];
	int size;
	printf("Enter the number of values: ");
	scanf("%d", &size);
	printf("\nEnter the element(s): ");	
	for (int i = 0; i < size; i++) {
		scanf("%d", &list[i]);
	}

	printf("\nBefore Bubble Sort!:\n");
	for (int i = 0; i < size; i++) {
		printf("%d   ", list[i]);
	}
	bubbleSort(list, size);

	printf("\nAfter!:\n");
	for (int i = 0; i < size; i++) {
		printf("%d   ", list[i]);
	}
	return 0;
}
