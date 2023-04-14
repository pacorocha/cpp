#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		// Constructors
		Array() :
			_data(NULL),
			_size(0) {};
		Array(const Array &copy) :
			_data(new T[copy._size]),
			_size(copy._size) {
				for (unsigned int i = 0; i < _size; ++i) {
					_data[i] = copy._data[i];
				}
			};
		Array(unsigned int n) :
			_data(new T[n]),
			_size(n) {
			for (unsigned int i = 0; i < _size; i++) {
				_data[i] = T();
			}
		};

		// Destructor
		~Array() {
			delete[] _data;
		};

		// Operators
		Array<T> & operator=(const Array &assign) {
			if (this != &assign) {
				T* temp_data = new T[assign._size];
				for (unsigned int i = 0; i < assign._size; i++) {
					temp_data[i] = assign._data[i];
				}
				delete [] _data;
				_data = temp_data;
				_size = assign._size;
			}
			return (*this);
		};

		// Subscript operator
		T& operator[](unsigned int i) {
			if (i >= _size)
				throw std::exception();
			return (_data[i]);
		}

		// Methods
		unsigned int size() const {
			return (_size);
		}

	private:
	T*				_data;
	unsigned int	_size;
};

#endif