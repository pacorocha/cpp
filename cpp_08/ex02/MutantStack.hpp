#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class iterator : public std::stack<T>::container_type::iterator
		{
			public:
				iterator(typename std::stack<T>::container_type::iterator it) :
					std::stack<T>::container_type::iterator(it) {}
		};

		iterator begin() {
			return (iterator(std::stack<T>::c.begin()));
		}

		iterator end() {
			return (iterator(std::stack<T>::c.end()));
		}

		class const_iterator : public std::stack<T>::container_type::const_iterator
		{
			public:
				const_iterator(typename std::stack<T>::container_type::const_iterator it) :
					std::stack<T>::container_type::const_iterator(it) {}
		};

		const_iterator begin() const {
			return (const_iterator(std::stack<T>::c.begin()));
		}

		const_iterator end() const {
			return (const_iterator(std::stack<T>::c.end()));
		}

};

#endif