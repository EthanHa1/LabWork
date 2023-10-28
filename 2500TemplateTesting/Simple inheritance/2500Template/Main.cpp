#include <iostream>
#include "header.h"

class A {
public:
	A() { std::cout << "A\n"; };
	~A() { std::cout << "Destructing A\n"; };


	int mA{ 5 };
};

class B: public A {
public:
	B() { std::cout << "B" << mA << '\n'; };
	~B() { std::cout << "Destructing B\n"; };
	int member1{ 1 };
protected:
	int mB{ 10 };
};

class C: public B {
public:
	C() { std::cout << "C\n"; };
	~C() { std::cout << "Destructing C\n"; };
};

class D : public C {
public:
	D() { std::cout << "D\n"; };
	~D() { std::cout << "Destructing D\n"; };
};

int main(void) {
	/*std::cout << "Constructing A: \n";
	A a{};

	std::cout << "Constructing B: \n";*/
	B b{};

	std::cout << b.mA << '\n';

	/*std::cout << "Constructing D: \n";
	D d{};

	std::cout << "Constructing C: \n";
	C c{};*/

	return 0;
}