#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
    private:
        std::stack<float> _stack;
        
        // Private methods
        bool _isOperator(const std::string& token) const;
        bool _isValidNumber(const std::string& token) const;
        float _performOperation(float a, float b, const std::string& op) const;
        void _processToken(const std::string& token);

    public:
        // Orthodox Canonical Form
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        
        // Public methods
        bool validateExpression(const std::string& expression) const;
        float calculate(const std::string& expression);
        
        // Exception classes
        class InvalidExpressionException : public std::exception {
            private:
                std::string _message;
            public:
                InvalidExpressionException(const std::string& message);
                virtual ~InvalidExpressionException() throw();
                virtual const char* what() const throw();
        };
        
        class DivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class NotEnoughOperandsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif