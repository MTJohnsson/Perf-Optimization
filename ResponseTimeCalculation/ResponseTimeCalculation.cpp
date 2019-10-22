// ResponseTimeCalculation.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>



int main(int argc, char* argv) {
	double* Qi = new double[100];
	double* Rprime = new double[100];
	double* X = new double[100];

	int m = 1;              // # of queuing node
	int N = 50;              // # of customers

	double Di = 77.1 * 0.001;       // service demand
	double Z = 2.0;                  // think time
	if (argc == 3) {
		Di = double(argv[1]);
		Z = double(argv[2]);

	}

	Qi[0] = 0.0;

	// iterate over the # of customers
	for (int n = 1; n < N; n++) {
		Rprime[n] = Di * (1.0 + Qi[n - 1]); //residen
		X[n] = n / (Z + Rprime[n]); //througput
		Qi[n] = X[n] * Rprime[n];

		// open model
		double Ui = X[n] * Di * 100.0;
		double Ri = Di / (1.0 - Ui * 0.01);

		std::cout << "n = "<< n << " Ri: " << Ri << std::endl;
	}
	system("PAUSE");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
