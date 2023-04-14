# include "Array.hpp"

int main() {
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i) {
        a[i] = i;
    }

    Array<int> b = a;
    a[3] = 99;

    std::cout << "Array<int> a:" << std::endl;
    for (unsigned int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
	std::cout << std::endl;


    std::cout << "Array<int> b:" << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    Array<char> c(5);
    for (unsigned int i = 0; i < c.size(); ++i) {
        c[i] = 'a' + i;
    }
	std::cout << std::endl;

    Array<char> d = c;
    c[2] = 'n';

    std::cout << "Array<char> c:" << std::endl;
    for (unsigned int i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
	std::cout << std::endl;


    std::cout << "Array<char> d:" << std::endl;
    for (unsigned int i = 0; i < d.size(); ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

	Array<std::string> string_array(3);
    string_array[0] = "hello";
    string_array[1] = "world";
    string_array[2] = "!";
	std::cout << std::endl;

    Array<std::string> string_array2 = string_array;
    string_array[1] = "pal";

    std::cout << "Array<std::string> string_array:" << std::endl;
    for (unsigned int i = 0; i < string_array.size(); ++i) {
        std::cout << string_array[i] << " ";
    }
    std::cout << std::endl;
	std::cout << std::endl;

    std::cout << "Array<std::string> string_array2:" << std::endl;
    for (unsigned int i = 0; i < string_array2.size(); ++i) {
        std::cout << string_array2[i] << " ";
    }
    std::cout << std::endl;

    return (0);
}