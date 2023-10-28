#include <iostream>
#include "header.h"

class Tree {
public:
	Tree(int numLeaves) : mNumLeaves{ numLeaves } {}
	void photosynthesise() const {
		for (int i{ 0 }; i < mNumLeaves; i++) {
			std::cout << "Photosynthesising...\n";
		}
	}
private:
	int mNumLeaves{};
};

class Leaf : public Tree {
public:
	Leaf(int numLeaves = 1) : Tree{ numLeaves } {}
	void photosynthesise() const {
		std::cout << "Photosynthesising...\n";
	}
};

int main(void) {
	Leaf l;
	l.photosynthesise();
	
	Tree t(10);
	t.photosynthesise();
	return 0;
}