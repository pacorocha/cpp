# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int	main(void) {
	// const Animal* meta = new Animal();
	Dog* j = new Dog();
	Cat* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	// delete meta;
	delete j;
	delete i;

	return (0);
}
