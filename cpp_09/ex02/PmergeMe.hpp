#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <limits>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	public:
		// Constructors
		PmergeMe(void);
		PmergeMe(const PmergeMe &copy);
		PmergeMe(int size, char** input);

		// Destructor
		~PmergeMe(void);

		// Operators
		PmergeMe & operator=(const PmergeMe &assign);

		// Getters / Setters
		int get_size() const;

		// Methods
		void validateInput(char ** input);
		template <typename T>
		void mergeInsert(T& container);
		template <typename T>
		void mergeSort(T& container, T& sorted_container, int start, int end);
		template <typename T>
		void printContainer(const T& container);
		void printInfo(void);

	private:
		std::vector<int> _seq_vector;
		std::deque<int> _seq_deque;
		int _size;

		template <typename T>
		void _merge(T& container, T& sorted_container);
};

#endif