// find_if example
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main () {
	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);
	myvector.push_back(17);
	myvector.push_back(22);
	myvector.push_back(47);
	myvector.push_back(59);

	for (int i = 0; i <= 60; i++) {
		std::cout << "Checking int = " << i << "..." << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(myvector, i);
			std::cout << "\e[0;32mFound value at position " << std::distance(myvector.begin(), it) << " of vector \e[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}