#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	MutantStack<std::list<std::string> > mutant_stack;

	std::list<std::string> mutant1;
	mutant1.push_back("apples");
	mutant1.push_back("pears");
	mutant1.push_back("bananas");
	std::list<std::string> mutant2;
	mutant2.push_back("oranges");
	mutant2.push_back("peaches");
	mutant2.push_back("watermelons");
	mutant_stack.push(mutant1);
	mutant_stack.push(mutant2);

	std::cout << std::endl;
	std::cout << "MUTANT STACK TEST" << std::endl;
	std::cout << "Stack size: " << mutant_stack.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Top element content: " << std::endl;
	for (MutantStack<std::list<std::string> >::value_type::iterator it = mutant_stack.top().begin(); it != mutant_stack.top().end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "Iterate over stack elements:" << std::endl;
	for (MutantStack<std::list<std::string> >::iterator it = mutant_stack.begin(); it != mutant_stack.end(); ++it) {
		for (std::list<std::string>::iterator mutant_it = it->begin(); mutant_it != it->end(); ++mutant_it)
			std::cout << *mutant_it << std::endl;
		std::cout << "--------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Pop method applied" << std::endl;
	mutant_stack.pop();

	std::cout << "Stack size: " << mutant_stack.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Top element content: " << std::endl;
	for (MutantStack<std::list<std::string> >::value_type::iterator it = mutant_stack.top().begin(); it != mutant_stack.top().end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "Iterate over stack elements:" << std::endl;
	for (MutantStack<std::list<std::string> >::iterator it = mutant_stack.begin(); it != mutant_stack.end(); ++it) {
		for (std::list<std::string>::iterator mutant_it = it->begin(); mutant_it != it->end(); ++mutant_it)
			std::cout << *mutant_it << std::endl;
		std::cout << "--------" << std::endl;
	}
	std::cout << std::endl;

	std::list<std::list<std::string> > list_stack;

	std::list<std::string> list1;
	list1.push_back("apples");
	list1.push_back("pears");
	list1.push_back("bananas");
	std::list<std::string> list2;
	list2.push_back("oranges");
	list2.push_back("peaches");
	list2.push_back("watermelons");
	list_stack.push_back(list1);
	list_stack.push_back(list2);

	std::cout << std::endl;
	std::cout << "LIST TEST" << std::endl;
	std::cout << "List size: " << list_stack.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Front element content: " << std::endl;
	for (std::list<std::list<std::string> >::value_type::iterator it = list_stack.front().begin(); it != list_stack.front().end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "Iterate over list elements:" << std::endl;
	for (std::list<std::list<std::string> >::iterator it = list_stack.begin(); it != list_stack.end(); ++it) {
		for (std::list<std::string>::iterator list_it = it->begin(); list_it != it->end(); ++list_it)
			std::cout << *list_it << std::endl;
		std::cout << "--------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Pop_front method applied" << std::endl;
	list_stack.pop_front();

	std::cout << "Stack size: " << list_stack.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Front element content: " << std::endl;
	for (std::list<std::list<std::string> >::value_type::iterator it = list_stack.front().begin(); it != list_stack.front().end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "Iterate over list elements:" << std::endl;
	for (std::list<std::list<std::string> >::iterator it = list_stack.begin(); it != list_stack.end(); ++it) {
		for (std::list<std::string>::iterator list_it = it->begin(); list_it != it->end(); ++list_it)
			std::cout << *list_it << std::endl;
		std::cout << "--------" << std::endl;
	}
	std::cout << std::endl;

	return 0;
}