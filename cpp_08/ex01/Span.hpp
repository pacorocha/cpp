#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
# include <stdexcept>

class Span
{
	public:
		// Constructors
		Span(unsigned int n);
		Span(const Span &copy);

		// Destructor
		~Span(void);

		// Operators
		Span & operator=(const Span &assign);

		// Methods
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		template <typename Iterator>
		void addRange(Iterator first, Iterator last) {
			while (first != last && _numbers.size() < _max_size) {
				_numbers.push_back(*first);
				++first;
			}
			if (first != last) {
				throw std::out_of_range("Span is full");
			}
		}

	private:
		unsigned int _max_size;
		std::vector<int> _numbers;
};

#endif