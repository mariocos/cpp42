#!/bin/bash

echo "========================================="
echo "       RPN CALCULATOR TEST SUITE"
echo "========================================="
echo ""

echo "=== VALID EXPRESSIONS ==="
echo ""

echo "Test: 3 4 +"
./RPN "3 4 +"
echo ""

echo "Test: 5 1 2 + 4 * + 3 -"
./RPN "5 1 2 + 4 * + 3 -"
echo ""

echo "Test: 8 9 * 9 - 9 - 9 - 4 - 1 + (The Answer!)"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo ""

echo "Test: 7 (single number)"
./RPN "7"
echo ""

echo "Test: 9 3 - (subtraction)"
./RPN "9 3 -"
echo ""

echo "Test: 8 2 / (division)"
./RPN "8 2 /"
echo ""

echo "Test: 2 3 * 4 5 * +"
./RPN "2 3 * 4 5 * +"
echo ""

echo ""
echo "=== ERROR CASES ==="
echo ""

echo "Test: 3 4 + + (not enough operands)"
./RPN "3 4 + +" 2>&1
echo ""

echo "Test: 1 2 (too many operands)"
./RPN "1 2" 2>&1
echo ""

echo "Test: 5 0 / (division by zero)"
./RPN "5 0 /" 2>&1
echo ""

echo "Test: (no arguments)"
./RPN 2>&1
echo ""

echo "Test: '' (empty string)"
./RPN "" 2>&1
echo ""

echo "Test: 12 3 + (multi-digit number)"
./RPN "12 3 +" 2>&1
echo ""

echo "Test: a b + (invalid characters)"
./RPN "a b +" 2>&1
echo ""

echo "Test: + + + (only operators)"
./RPN "+ + +" 2>&1
echo ""

echo "Test: -5 2 + (negative number)"
./RPN "-5 2 +" 2>&1
echo ""

echo "========================================="
echo "           TEST SUITE COMPLETE"
echo "========================================="

