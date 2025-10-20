#!/bin/bash

echo "========================================="
echo "      PMERGE ME TEST SUITE"
echo "    Ford-Johnson Merge-Insertion Sort"
echo "========================================="
echo ""

echo "=== BASIC TESTS ==="
echo ""

echo "Test 1: Basic example (5 elements)"
./PmergeMe 3 5 9 7 4
echo ""

echo "Test 2: Two elements"
./PmergeMe 5 3
echo ""

echo "Test 3: Single element"
./PmergeMe 42
echo ""

echo "Test 4: Reverse sorted"
./PmergeMe 9 8 7 6 5 4 3 2 1
echo ""

echo "Test 5: Already sorted"
./PmergeMe 1 2 3 4 5 6 7 8 9 10
echo ""

echo "Test 6: Duplicates"
./PmergeMe 5 2 8 2 9 1 5
echo ""

echo "Test 7: Example from subject"
./PmergeMe 8 6 4 2 0
echo ""

echo ""
echo "=== EDGE CASES ==="
echo ""

echo "Test 8: All identical"
./PmergeMe 7 7 7 7 7
echo ""

echo "Test 9: Odd number of elements (13)"
./PmergeMe 13 8 5 2 11 6 3 9 4 12 7 1 10
echo ""

echo "Test 10: Even number of elements (14)"
./PmergeMe 14 8 5 2 11 6 3 9 4 12 7 1 10 13
echo ""

echo ""
echo "=== PERFORMANCE TESTS ==="
echo ""

echo "Test 11: 50 elements"
./PmergeMe $(seq 1 50 | sort -R | tr '\n' ' ')
echo ""

echo "Test 12: 100 elements"
./PmergeMe $(seq 1 100 | sort -R | tr '\n' ' ')
echo ""

echo "Test 13: 200 elements"
./PmergeMe $(seq 1 200 | sort -R | tr '\n' ' ')
echo ""

echo ""
echo "=== ERROR CASES ==="
echo ""

echo "Test 14: No arguments"
./PmergeMe 2>&1
echo ""

echo "Test 15: Negative number"
./PmergeMe 3 -5 7 2>&1
echo ""

echo "Test 16: Invalid character"
./PmergeMe 1 2 abc 2>&1
echo ""

echo "Test 17: Mixed invalid"
./PmergeMe 5 3.14 2 2>&1
echo ""

echo "========================================="
echo "           TEST SUITE COMPLETE"
echo "========================================="

