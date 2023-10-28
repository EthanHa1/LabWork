#include <iostream>
#include <sstream>
#include <string>
int count_words(std::string const& sentence, std::string const& word) {
	// WRITE YOUR SOLUTION HERE.
	std::stringstream sst{ sentence };
	std::string subStr;
	int count{};
	while (sst >> subStr) {
		if (subStr == word) {
			count++;
		}
	}
	return count;
}
int main() {
	std::string sentence, word;
	std::getline(std::cin, sentence);
	std::cin >> word;
	std::cout << count_words(sentence, word) << std::endl;
}