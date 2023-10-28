#include <stdexcept>
#include <iostream>

void assign(int& var, int const& value) {
	if (value % 2 == 0) {
		throw std::runtime_error("Illegal assignment.");
	}
	var = value;
}
void cleanup(int& var) {
	var = 0;
}
int main() {
	int a{ 0 };
	int b{ 0 };
	// MODIFY BELOW HERE.
	try {
		assign(a, 42);
		assign(b, 31);
	}
	catch (const std::runtime_error& e) {
		cleanup(b);
		std::cout << e.what() << '\n';
	}
	std::cout << b << '\n';
}
