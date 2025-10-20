#include "RPN.hpp"
#include <stdexcept>

// Orthodox Canonical Form

RPN::RPN() {
}

RPN::RPN(const RPN& other) : _stack(other._stack) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
}

// Helper methods

void RPN::trim(std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }
    
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t')) {
        end--;
    }
    
    str = str.substr(start, end - start);
}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidNumber(const std::string& token) const {
    // Only single-digit positive integers (0-9) are allowed
    if (token.length() != 1) {
        return false;
    }
    
    return token[0] >= '0' && token[0] <= '9';
}

void RPN::performOperation(const std::string& op) {
    // Check if we have at least 2 operands
    if (_stack.size() < 2) {
        throw std::runtime_error("Error");
    }
    
    // Pop two operands (note: order matters for - and /)
    double right = _stack.top();
    _stack.pop();
    double left = _stack.top();
    _stack.pop();
    
    double result;
    
    if (op == "+") {
        result = left + right;
    } else if (op == "-") {
        result = left - right;
    } else if (op == "*") {
        result = left * right;
    } else if (op == "/") {
        if (right == 0) {
            throw std::runtime_error("Error");
        }
        result = left / right;
    } else {
        throw std::runtime_error("Error");
    }
    
    _stack.push(result);
}

// Main functionality

double RPN::evaluate(const std::string& expression) {
    // Clear stack for new evaluation
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    if (expression.empty()) {
        throw std::runtime_error("Error");
    }
    
    // Parse tokens separated by spaces
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isValidNumber(token)) {
            // Convert single digit to double and push to stack
            double num = token[0] - '0';
            _stack.push(num);
        } else if (isOperator(token)) {
            // Perform operation
            performOperation(token);
        } else {
            // Invalid token
            throw std::runtime_error("Error");
        }
    }
    
    // After processing all tokens, stack should have exactly one element
    if (_stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    
    return _stack.top();
}

