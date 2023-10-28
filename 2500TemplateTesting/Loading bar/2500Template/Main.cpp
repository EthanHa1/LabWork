#include <iostream>
#include <iomanip>
#include "header.h"


int main(void) {
	int input{};
	std::cin >> input;
	for (int i{ 0 }; i <= input; i++) {
		std::cout << "[" << std::setfill('*') << std::setw(i) << "";
		std::cout << std::setfill(' ') << std::setw(input - i + 2) << "] ";
		double percent{};
		percent = static_cast<double>(100) * i / input;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::setw(6) << percent << '%' << '\n';

	}

	return 0;
}