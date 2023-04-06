#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

template <typename T>
void print(const T& value) {
    std::cout << "Array element value: " << value << std::endl;
}

#endif