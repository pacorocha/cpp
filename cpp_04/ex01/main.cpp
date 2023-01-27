# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int	main(void) {
	const Animal* animals[100];
	 for (int i = 0; i < 100; i++) {
	 	std::cout << "[" << i + 1 << "]" << std::endl;
        if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
    for (int i = 0; i < 100; i++) {
		std::cout << "[" << i + 1 << "]" << std::endl;
        delete animals[i];
    }
	return (0);
}