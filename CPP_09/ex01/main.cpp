#include "RPN.hpp"

float string_to_float(const std::string str) {
    std::stringstream ss(str);
    float result;
    ss >> result; // Extract number
    return result;
}

int err(string s){
    if (s == "args")
        std::cerr << "Error: Invalid arguments" << std::endl;
    else if (s == "operands")
        std::cerr << "Error: Not enough operands" << std::endl;
    else if (s == "division")
        std::cerr << "Error: Division by zero" << std::endl;
    else if (s == "operator")
        std::cerr << "Error: Invalid operator" << std::endl;
    else if (s == "expression")
        std::cerr << "Error: Invalid expression" << std::endl;
    else
        std::cerr << "Error" << std::endl;
    return 1;
}

int is_operand(char c){
    if (c == '*' || c == '/' || c == '-' || c == '+')
        return 1;
    return 0;
}

int is_valid_arg(char c){
    if (is_operand(c) || c == ' ' || std::isdigit(c))
        return 1;
    return 0;
}

int valid_args(string args){
    for (size_t i = 0; i < args.size(); i++)
        if (!is_valid_arg(args[i]))
            return 0;
    return 1;
}

int rpn(string s){
    std::stack<float> stk;
    float a, b, r;
    for (size_t i = 0; i < s.size(); i++){
        if (s[i] == ' ')
            continue ;
        if (std::isdigit(s[i]))
            stk.push(string_to_float(s.substr(i, 1)));
        else{
            if (stk.size() < 2)
                return err("operands");
            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
            switch (s[i]) {
                case '+':
                    r = a + b;
                    break;
                case '-':
                    r = a - b;
                    break;
                case '*':
                    r = a * b;
                    break;
                case '/':
                    if (b == 0)
                        return err("division");
                    r = a / b;
                    break;
                default:
                    return err("operator");
            }
            stk.push(r);
        }
    }
    if (stk.size() != 1)
        return err("expression");
    cout << stk.top() << endl;
    return 0;
}
int main(int argc, char **argv){
    if (argc != 2 || !valid_args(argv[1])){        
        return err("args");
    }
    return rpn(argv[1]);
}