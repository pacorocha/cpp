#include "iter.hpp"

int main( void ) {
    char str[] = "streetwise";
	std::cout << "<<<<<<<<<<<<<<< TEST NUMBER ONE >>>>>>>>>>>>>>" << std::endl;
	std::cout << std::endl;
    iter(str, 10, print<char>);
    int arr[] = {1, 2, 3, 4, 5};
	std::cout << std::endl;
	std::cout << "<<<<<<<<<<<<<<< TEST NUMBER TWO >>>>>>>>>>>>>>" << std::endl;
	std::cout << std::endl;
    iter(arr, 5, print<int>);
    std::string fruits[] = {"apple", "pear", "banana", "watermelon", "pineapple", "peach"};
	std::cout << std::endl;
	std::cout << "<<<<<<<<<<<<<<< TEST NUMBER THREE >>>>>>>>>>>>>>" << std::endl;
	std::cout << std::endl;
    iter(fruits, 6, print<std::string>);
	return 0;
}