#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>

void swap(T &x, T &y) {
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &min(T const &x, T const &y) {
	if (x < y)
		return (x);
	return (y);
};

template <typename T>
T const &max(T const &x, T const &y) {
	if (x > y)
		return (x);
	return (y);
};


#endif