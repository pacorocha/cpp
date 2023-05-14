#include "RPN.hpp"

// Constructors
RPN::RPN(void) {};

RPN::RPN(const RPN &copy) :
	_op_stack(copy._op_stack)
{};

//Destructor
RPN::~RPN(void) {};

// Operators
RPN & RPN::operator=(const RPN &assign) {
	if (this !=&assign)
		_op_stack = assign._op_stack;
	return (*this);
};

void RPN::validateInput(std::string rpn_exp) {
	int operandCount = 0;
	int operatorCount = 0;
	for (size_t i = 0; i < rpn_exp.size(); i++) {
		if (std::isspace(rpn_exp[i]))
			continue;
		else if (std::isdigit(rpn_exp[i])) {
			_op_stack.push(rpn_exp[i] - '0');
			operandCount++;
		} else {
			_buildStack(rpn_exp[i]);
			operatorCount++;
		}
	}
	if (operandCount < 2 || operatorCount < 1)
		throw std::invalid_argument("Invalid input: At least 2 operands and 1 operator required");
	getResult();
};

void RPN::_buildStack(char op){
	if (_op_stack.size() < 2)
		throw std::invalid_argument("Not enough operands ");
	int op2 = _op_stack.top();
	_op_stack.pop();
	int op1 = _op_stack.top();
	_op_stack.pop();
	int result = _processOperations(op, op1, op2);
	_op_stack.push(result);
};

int RPN::_processOperations(char op, int op1, int op2) {
	switch (op) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			if (op2 == 0) {
				throw std::invalid_argument("Division by zero");
			}
			return op1 / op2;
		default:
			throw std::invalid_argument("Unknown operator: " + std::string(1, op));
	}
};

void RPN::getResult(void) {
	if (_op_stack.size() != 1)
		throw std::invalid_argument("Invalid input: expected one result");
	std::cout << _op_stack.top() << std::endl;
}
