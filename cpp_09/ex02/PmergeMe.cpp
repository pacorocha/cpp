#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe(void) :
	_size(0),
	_buildTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy) :
	_size(copy._size),
	_buildTime(copy._buildTime) {}

PmergeMe::PmergeMe(int size, char** input) : _size(size - 1) {
	if (_size <= 1)
		throw std::invalid_argument("Not enough numbers in sequence.");
	validateInput(input);
}

// Destructor
PmergeMe::~PmergeMe(void) {}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign) {
	if (this != &assign) {
		_size = assign.get_size();
		_buildTime = assign._buildTime;
	}
	return (*this);
}

// Getters / Setters
int PmergeMe::get_size() const {
	return (_size);
}

// Methods
void PmergeMe::validateInput(char** input) {
	std::set<int> parsed_numbers;
	std::clock_t start_time = std::clock();
	for (int i = 1; i <= _size; i++) {
		size_t len = strlen(input[i]);
		for (size_t j = 0; j < len; j++) {
			if (!isdigit(input[i][j]))
				throw std::invalid_argument("Argument is not a positive integer.");
		}
		int number = atoi(input[i]);
		if (number <= 0)
			throw std::invalid_argument("Argument is not a positive integer.");

		std::set<int>::iterator it = parsed_numbers.find(number);
		if (it != parsed_numbers.end())
				throw std::invalid_argument("Duplicate number detected.");

		parsed_numbers.insert(number);
		_seq_vector.push_back(number);
		_seq_deque.push_back(number);
	}
    std::clock_t end_time = std::clock();
    this->_buildTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}

template <typename T>
void PmergeMe::mergeInsert(T& container) {
    T sorted_container(_size);

    if (_size <= std::numeric_limits<int>::max()) {
        for (int i = 1; i < _size; ++i) {
            int key = container[i];
            int j = i - 1;
            while (j >= 0 && container[j] > key) {
                container[j + 1] = container[j];
                --j;
            }
            container[j + 1] = key;
        }
        return;
    }
    mergeSort(container, sorted_container, 0, _size - 1);
    container = sorted_container;
}

template <typename T>
void PmergeMe::mergeSort(T& container, T& sorted_container, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(container, sorted_container, start, mid);
        mergeSort(container, sorted_container, mid + 1, end);
        _merge(container, sorted_container);
    }
}

template <typename T>
void PmergeMe::_merge(T& container, T& sorted_container) {
    typedef typename T::size_type size_type;

    size_type leftSize = container.size() / 2;
    size_type rightSize = container.size() - leftSize;
    std::vector<typename T::value_type> leftSubvector(container.begin(), container.begin() + leftSize);
    std::vector<typename T::value_type> rightSubvector(container.begin() + leftSize, container.end());

    size_type i = 0;
    size_type j = 0;
    size_type k = 0;

    while (i < leftSize && j < rightSize) {
        if (leftSubvector[i] <= rightSubvector[j]) {
            container[k] = leftSubvector[i];
            i++;
        } else {
            container[k] = rightSubvector[j];
            j++;
        }
        k++;
    }
    std::copy(leftSubvector.begin() + i, leftSubvector.end(), container.begin() + k);
    std::copy(rightSubvector.begin() + j, rightSubvector.end(), container.begin() + k);
    sorted_container = container;
}

template <typename T>
void PmergeMe::printContainer(const T& container) {
	typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printInfo(void) {
    std::cout << "Before: ";
	printContainer(_seq_vector);

    std::vector<int> sorted_vector(_seq_vector);
    std::clock_t start = std::clock();
    mergeInsert(sorted_vector);
    std::clock_t end = std::clock();
    double elapsedTimeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printContainer(sorted_vector);

    std::cout << "Time to process a range of " << _size << " elements with std::vector: " << elapsedTimeVector + _buildTime << " seconds" << std::endl;

    std::deque<int> sorted_deque(_seq_deque);
    start = std::clock();
    mergeInsert(sorted_deque);
    end = std::clock();
    double elapsedTimeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << _size << " elements with std::deque: " << elapsedTimeDeque + _buildTime << " seconds" << std::endl;
}
