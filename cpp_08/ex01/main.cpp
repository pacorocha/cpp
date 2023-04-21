#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
	Span s1 = Span(2);
	s1.addNumber(6);
	// s1.addNumber(15);
	std::cout << s1.shortestSpan() << std::endl;
	std::cout << s1.longestSpan() << std::endl;

	Span s2 = Span(5);
	s2.addNumber(6);
	s2.addNumber(3);
	s2.addNumber(17);
	s2.addNumber(9);
	s2.addNumber(11);
	// s2.addNumber(27);
	std::cout << s2.shortestSpan() << std::endl;
	std::cout << s2.longestSpan() << std::endl;

    std::srand(std::time(0));
    Span s3(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(std::rand());
    }
    s3.addRange(v.begin(), v.end());
    std::cout << "Shortest span: " << s3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s3.longestSpan() << std::endl;
    return 0;
}