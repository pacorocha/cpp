#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe pmergeMe(argc, argv);
        pmergeMe.printInfo();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}