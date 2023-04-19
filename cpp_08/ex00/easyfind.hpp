#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>

typename T::iterator easyfind(T& container, int needle) {
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw std::out_of_range("Int not found in container");
	return (it);
}

#endif