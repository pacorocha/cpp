#include "Span.hpp"

// Constructors
Span::Span(unsigned int n) :
	_max_size(n) {}

Span::Span(const Span &copy) :
	_max_size(copy._max_size),
	_numbers(copy._numbers) {}

// Destructor
Span::~Span(void) {}

// Operators
Span & Span::operator=(const Span &assign) {
	if (this != &assign) {
		_max_size = assign._max_size;
		_numbers = assign._numbers;
	}
	return *this;
}

void Span::addNumber(int num) {
        if (_numbers.size() == _max_size) {
            throw std::out_of_range("Span is full");
        }
        _numbers.push_back(num);
    }

int Span::shortestSpan() const {
	if (_numbers.size() <= 1) {
		throw std::out_of_range("Not enough numbers in Span");
	}
	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());
	int min_span = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < sorted_numbers.size(); i++) {
		int span = sorted_numbers[i] - sorted_numbers[i-1];
		if (span < min_span) {
			min_span = span;
		}
	}
	return min_span;
}

int Span::longestSpan() const {
	if (_numbers.size() <= 1) {
		throw std::out_of_range("Not enough numbers in Span");
	}
	int max_num = *std::max_element(_numbers.begin(), _numbers.end());
	int min_num = *std::min_element(_numbers.begin(), _numbers.end());
	return max_num - min_num;
}
