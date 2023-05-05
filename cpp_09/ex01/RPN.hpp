#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		// Constructors
		RPN(void);
		RPN(const RPN &copy);

		// Destructor
		~RPN(void);

		// Operators
		RPN & operator=(const RPN &assign);

		// Methods
		void validateInput(std::string rpn_exp);
		void getResult(void);

	private:
		std::stack<int> _op_stack;

		void	_buildStack(char op);
		int		_processOperations(char op, int op1, int op2);
};

#endif