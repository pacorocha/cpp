#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		// Constructors
		Cat(void);
		Cat(const Cat &copy);

		// Destructor
		virtual ~Cat(void);

		// Operators
		Cat & operator=(const Cat &assign);

		// Methods
		void makeSound(void) const;

	private:
		Brain* _brain;
};

#endif