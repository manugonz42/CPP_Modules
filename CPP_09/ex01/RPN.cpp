#include "RPN.hpp"
#include <cctype>

// Orthodox Canonical Form implementation
RPN::RPN() {
}

RPN::RPN(const RPN& other) : _stack(other._stack) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
}

// Exception implementations
RPN::InvalidExpressionException::InvalidExpressionException(const std::string& message) : _message(message) {
}

RPN::InvalidExpressionException::~InvalidExpressionException() throw() {
}

const char* RPN::InvalidExpressionException::what() const throw() {
    return _message.c_str();
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "Error: Division by zero";
}

const char* RPN::NotEnoughOperandsException::what() const throw() {
    return "Error: Not enough operands";
}

// Private methods
bool RPN::_isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::_isValidNumber(const std::string& token) const {
    if (token.length() == 1 && std::isdigit(token[0])) {
        return true; // Single digit
    } else if (token.length() == 2 && token[0] == '-' && std::isdigit(token[1])) {
        return true; // Negative single digit
    }
    return false;
}

float RPN::_performOperation(float a, float b, const std::string& op) const {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/") {
        if (b == 0)
            throw DivisionByZeroException();
        return a / b;
    }
    throw InvalidExpressionException("Error: Invalid operator");
}

void RPN::_processToken(const std::string& token) {
    if (_isOperator(token)) {
        if (_stack.size() < 2)
            throw NotEnoughOperandsException();
        
        float b = _stack.top();
        _stack.pop();
        float a = _stack.top();
        _stack.pop();
        
        float result = _performOperation(a, b, token);
        _stack.push(result);
    } else if (_isValidNumber(token)) {
        std::stringstream ss(token);
        float num;
        ss >> num;
        _stack.push(num);
    } else {
        throw InvalidExpressionException("Error: Invalid expression");
    }
}

// Public methods
bool RPN::validateExpression(const std::string& expression) const {
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        if (!_isOperator(token) && !_isValidNumber(token)) {
            return false;
        }
    }
    return true;
}

float RPN::calculate(const std::string& expression) {
    // Clear the stack before calculation
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    if (!validateExpression(expression)) {
        throw InvalidExpressionException("Error: Invalid arguments");
    }
    
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        _processToken(token);
    }
    
    if (_stack.size() != 1) {
        throw InvalidExpressionException("Error: Invalid expression");
    }
    
    return _stack.top();
}
