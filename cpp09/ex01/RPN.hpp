#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    std::stack<double> _stack;

    // Helper methods
    bool isOperator(const std::string& token) const;
    bool isValidNumber(const std::string& token) const;
    void performOperation(const std::string& op);
    void trim(std::string& str) const;

public:
    // Orthodox Canonical Form
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    // Main functionality
    double evaluate(const std::string& expression);
};

#endif

