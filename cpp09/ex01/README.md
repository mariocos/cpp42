# Exercise 01 - RPN (Reverse Polish Notation) Calculator

## Description
A calculator that evaluates mathematical expressions written in Reverse Polish Notation using a stack-based algorithm.

## What is Reverse Polish Notation?
RPN is a postfix notation where operators come after their operands.

**Examples:**
- Infix: `3 + 4` → RPN: `3 4 +`
- Infix: `(1 + 2) * 4` → RPN: `1 2 + 4 *`
- Infix: `5 - 3 + 8` → RPN: `5 3 - 8 +`

## Implementation Details

### Classes
- **RPN**: Main class implementing the stack-based RPN evaluation
  - Follows Orthodox Canonical Form (Coplien Form)
  - Uses `std::stack<double>` for operand storage
  - LIFO (Last In, First Out) semantics perfect for RPN

### Algorithm
```
For each token in the expression:
  if token is a number:
    push onto stack
  else if token is an operator:
    pop two operands (right, then left)
    apply operation: left OP right
    push result onto stack
  else:
    error (invalid token)

Final check: stack must have exactly one element (the result)
```

### Features
- ✅ Stack-based RPN evaluation (std::stack)
- ✅ Supports operators: +, -, *, /
- ✅ Single-digit positive integers (0-9) only
- ✅ Comprehensive error handling
- ✅ Division by zero detection
- ✅ Operand validation
- ✅ No memory leaks (verified with valgrind)
- ✅ Orthodox Canonical Form implemented

### Error Handling
- Invalid syntax/format
- Division by zero
- Insufficient operands for operation
- Too many operands (invalid expression)
- Non-numeric tokens (except operators)
- Empty input
- Multi-digit numbers (not allowed)
- Negative numbers (not allowed)

## Compilation
```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## Usage
```bash
./RPN "<expression>"
```

The expression must be enclosed in quotes and tokens separated by spaces.

## Examples

### Valid Expressions

```bash
$ ./RPN "3 4 +"
7

$ ./RPN "5 1 2 + 4 * + 3 -"
14

$ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

$ ./RPN "7"
7

$ ./RPN "9 3 -"
6

$ ./RPN "8 2 /"
4
```

### Error Cases

```bash
$ ./RPN "3 4 + +"
Error                    # Not enough operands

$ ./RPN "1 2"
Error                    # Too many operands (no final operator)

$ ./RPN "5 0 /"
Error                    # Division by zero

$ ./RPN
Error                    # No arguments

$ ./RPN ""
Error                    # Empty expression

$ ./RPN "12 3 +"
Error                    # Multi-digit numbers not allowed

$ ./RPN "a b +"
Error                    # Invalid characters

$ ./RPN "+ + +"
Error                    # Only operators, no operands

$ ./RPN "-5 2 +"
Error                    # Negative numbers not allowed
```

## Step-by-Step Example

**Expression:** `5 1 2 + 4 * + 3 -`

1. Push 5 → Stack: [5]
2. Push 1 → Stack: [5, 1]
3. Push 2 → Stack: [5, 1, 2]
4. Operator `+`: pop 2, pop 1, compute 1+2=3, push 3 → Stack: [5, 3]
5. Push 4 → Stack: [5, 3, 4]
6. Operator `*`: pop 4, pop 3, compute 3*4=12, push 12 → Stack: [5, 12]
7. Operator `+`: pop 12, pop 5, compute 5+12=17, push 17 → Stack: [17]
8. Push 3 → Stack: [17, 3]
9. Operator `-`: pop 3, pop 17, compute 17-3=14, push 14 → Stack: [14]

**Result:** 14 ✓

## Technical Highlights

### Container Choice: std::stack

**Why std::stack?**
- **LIFO Semantics**: Last In, First Out - exactly what RPN needs
- **Perfect API**: `push()`, `pop()`, `top()` match algorithm operations
- **Prevents Errors**: Interface restricts access to only top element
- **Clear Intent**: Code is immediately recognizable as stack algorithm
- **Efficient**: O(1) for all operations

### Algorithm Complexity
- **Time**: O(n) where n is the number of tokens
- **Space**: O(n) in worst case (all numbers pushed before any operation)

### Design Decisions
1. **Single-digit only**: Simplifies parsing and matches requirement
2. **Double precision**: Allows division results to be precise
3. **Operator order matters**: For `-` and `/`, we pop right then left
4. **Exception handling**: Clean error propagation with std::runtime_error

## Standards Compliance
- ✅ C++98 standard
- ✅ Compiled with `-Wall -Wextra -Werror`
- ✅ Orthodox Canonical Form implemented
- ✅ No memory leaks
- ✅ Proper error handling
- ✅ Clean, readable code

## Memory Management
Verified with valgrind:
```bash
$ valgrind --leak-check=full ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
...
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## RPN vs Infix Notation

**Advantages of RPN:**
- No parentheses needed
- No operator precedence rules to remember
- Easy to evaluate with a stack
- Calculators (HP calculators) use RPN
- More efficient for computers to process

**Example Comparison:**
```
Infix:  (3 + 4) * (5 - 2)
RPN:    3 4 + 5 2 - *

Infix:  3 + 4 * 5
RPN:    3 4 5 * +    (respects precedence naturally)
```

## Fun Fact
The expression `8 9 * 9 - 9 - 9 - 4 - 1 +` equals 42, the answer to life, the universe, and everything! 🚀

