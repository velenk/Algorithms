#include <iostream>
#include <time.h>
#include <math.h>

double calculate(const int n, const double a[], const double x){
	int i;
	double p = a[n-1];
	for (i=n-1;i>=0;i--){
		p = x * p + a[i-1];
	}
	return p;
}

int main(){
	const int n = 9;
	const int MAXK = 1e5;
	double x = 1.1;
	double a[n];
	int i;
	
	clock_t start, stop;
	
	for (i=0;i<n;i++){
		a[i] = i;
	}
	
	start = clock();
	for (i=0;i<MAXK;i++){
		calculate(n, a, x);
	}
	double num = calculate(n, a, x);
	std::cout << num << std::endl;
	
	stop = clock();
	std::cout << stop - start << std::endl;
	std::cout << (double)(stop - start)/CLK_TCK/MAXK << std::endl;
	
	return 0;
}
