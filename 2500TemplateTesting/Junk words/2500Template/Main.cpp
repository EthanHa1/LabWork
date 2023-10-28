#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include<stdexcept>
#include "header.h"


int main(void) {
	std::string junk{ "junk.txt" };
	std::ofstream ofstJunk{ junk };
	if (!ofstJunk) {
		throw std::runtime_error("File not opened!\n");
	}
	ofstJunk << "order" << '\n';
	ofstJunk << "hello" << '\n';
	ofstJunk << "does" << '\n';
	ofstJunk << "not" << '\n';
	ofstJunk << "matter" << '\n';
	ofstJunk << "world" << '\n';
	ofstJunk << "junk" << '\n';
	ofstJunk.close();

	std::ifstream ifstJunk{ junk };
	if (!ifstJunk) {
		throw std::runtime_error("File not opened!\n");
	}
	std::string junkStr{};
	std::vector<std::string> vJunk;
	while (std::getline(ifstJunk, junkStr)) {
		vJunk.push_back(junkStr);
	}
	ifstJunk.close();

	std::string lexi{ "lexi.txt" };
	std::ofstream ofstLexi{ lexi };
	if (!ofstLexi) {
		throw std::runtime_error("File not opened!\n");
	}
	ofstLexi << "world" << '\n';
	ofstLexi << "hello" << '\n';
	ofstLexi.close();

	std::ifstream ifstLexi{ lexi };
	if (!ifstLexi) {
		throw std::runtime_error("File not opened!\n");
	}
	std::string lexiStr{};
	std::vector<std::string> vLexi;
	while (std::getline(ifstLexi, lexiStr)) {
		vLexi.push_back(lexiStr);
	}
	ifstJunk.close();

	std::ofstream ofstValid{ "valid.txt" };
	for (int i{ 0 }; i < vJunk.size(); i++) {
		for (int j{ 0 }; j < vLexi.size(); j++) {
			if (vJunk[i] == vLexi[j]) {
				ofstValid << vLexi[j] << '\n';
				std::cout << vLexi[j] << '\n';
			}
		}
	}
	ofstValid.close();

	return 0;
}