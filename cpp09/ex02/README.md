# Exercise 02 - PmergeMe (Ford-Johnson Merge-Insertion Sort)

## Description
Implementation of the Ford-Johnson merge-insertion sort algorithm with performance comparison between `std::vector` and `std::deque` containers.

## What is Ford-Johnson Algorithm?
The Ford-Johnson algorithm (also called merge-insertion sort) is a comparison-based sorting algorithm that **minimizes the number of comparisons** needed to sort a sequence. It's provably optimal for sequences up to 47 elements.

### Key Features
- Minimizes comparison count (not total operations)
- Combines recursive sorting with binary insertion
- Uses Jacobsthal sequence for optimal insertion order
- Optimal for n ≤ 47 elements in comparison count

## Algorithm Overview

### The 5 Steps

**1. Pairing and Comparison**
```
Input: [5, 2, 8, 1, 9, 3, 7]
Pairs: (5,2), (8,1), (9,3), straggler: 7
→ Larger: [5, 8, 9]
→ Pend:   [2, 1, 3]
```

**2. Recursive Sort of Larger Elements**
```
Sort larger elements: [5, 8, 9]
Creates the "main chain"
```

**3. Initial Insertion**
```
Insert first pend (partner of first main chain element)
Insert 2 at start: [2, 5, 8, 9]
```

**4. Binary Insertion Using Jacobsthal Order**
```
Jacobsthal sequence: 0, 1, 1, 3, 5, 11, 21, 43...
Formula: J(n) = J(n-1) + 2*J(n-2)

Insert remaining pend elements:
- Insert pend[3]: 3 → [2, 3, 5, 8, 9]
- Insert pend[2]: 1 → [1, 2, 3, 5, 8, 9]
```

**5. Handle Straggler**
```
Binary insert 7: [1, 2, 3, 5, 7, 8, 9]
```

### Why Jacobsthal Sequence?
The Jacobsthal sequence minimizes the **maximum number of comparisons** needed during binary insertion. It's mathematically proven to be optimal for this purpose.

## Implementation Details

### Classes
- **PmergeMe**: Main class implementing Ford-Johnson algorithm
  - Orthodox Canonical Form (Coplien Form)
  - Template methods for both `std::vector` and `std::deque`
  - Jacobsthal sequence generator
  - Binary insertion helpers

### Container Comparison

**std::vector:**
- Contiguous memory → excellent cache locality
- Fast random access: O(1)
- Binary search benefits from cache hits
- Typically faster for Ford-Johnson (comparison-heavy)

**std::deque:**
- Non-contiguous chunks → some cache misses
- Random access: O(1) but slightly slower
- No reallocation overhead
- Better for very large datasets or frequent insertions

### Performance Characteristics

**Algorithm Complexity:**
- Comparisons: ~n log₂(n) - 1.415n (optimal for small n)
- Time: O(n log n)
- Space: O(n)

**Expected Results:**
- Vector usually wins for Ford-Johnson
- Reason: Algorithm is comparison-heavy, benefits from cache locality
- Deque may perform better with very large datasets

## Compilation
```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## Usage
```bash
./PmergeMe <positive_integers>
```

All arguments must be positive integers separated by spaces.

## Examples

### Basic Sorting

```bash
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 4 us
Time to process a range of 5 elements with std::deque  : 4 us
```

### Example from Subject

```bash
$ ./PmergeMe 8 6 4 2 0
Before: 8 6 4 2 0
After:  0 2 4 6 8
Time to process a range of 5 elements with std::vector : 6 us
Time to process a range of 5 elements with std::deque  : 2 us
```

### Reverse Sorted

```bash
$ ./PmergeMe 9 8 7 6 5 4 3 2 1
Before: 9 8 7 6 5 4 3 2 1
After:  1 2 3 4 5 6 7 8 9
Time to process a range of 9 elements with std::vector : 31 us
Time to process a range of 9 elements with std::deque  : 9 us
```

### Large Dataset

```bash
$ ./PmergeMe $(seq 1 100 | sort -R | tr '\n' ' ')
Before: 23 65 17 30 19 9 55 48 75 71 [...]
After:  1 2 3 4 5 6 7 8 9 10 [...]
Time to process a range of 100 elements with std::vector : 110 us
Time to process a range of 100 elements with std::deque  : 139 us
```

### Error Cases

```bash
$ ./PmergeMe
Error

$ ./PmergeMe 3 -5 7
Error

$ ./PmergeMe 1 2 abc
Error
```

## Edge Cases Handled

- ✅ Single element (already sorted)
- ✅ Two elements
- ✅ Odd number of elements (straggler)
- ✅ Even number of elements
- ✅ Already sorted sequences
- ✅ Reverse sorted sequences
- ✅ Duplicate values
- ✅ All identical elements
- ✅ Large datasets (100+, 1000+ elements)

## Algorithm Step-by-Step Example

**Input:** `[5, 2, 8, 1, 9, 3, 7]`

**Step 1 - Pair & Compare:**
```
Pairs: (5,2), (8,1), (9,3), straggler: 7
Larger: [5, 8, 9]
Pend:   [2, 1, 3]
```

**Step 2 - Recursive Sort:**
```
Sort [5, 8, 9] → [5, 8, 9] (already sorted)
Main chain: [5, 8, 9]
```

**Step 3 - Initial Insertion:**
```
Insert pend[0]=2 at start
Result: [2, 5, 8, 9]
```

**Step 4 - Jacobsthal Insertion:**
```
Jacobsthal: [0, 1, 1, 3, 5, ...]
Insert pend[1] using Jacobsthal index 3 (but we have index 1)
- Binary insert pend[2]=1 → [1, 2, 5, 8, 9]
- Binary insert pend[1]=3 → [1, 2, 3, 5, 8, 9]
Wait, let me recalculate...

Actually for 3 pend elements [2, 1, 3]:
- pend[0]=2 inserted in step 3
- Following Jacobsthal for remaining: pend[2]=3, then pend[1]=1
- Insert 3: [2, 3, 5, 8, 9]
- Insert 1: [1, 2, 3, 5, 8, 9]
```

**Step 5 - Insert Straggler:**
```
Binary insert 7
Final: [1, 2, 3, 5, 7, 8, 9]
```

## Jacobsthal Sequence Details

```
J(0) = 0
J(1) = 1
J(n) = J(n-1) + 2*J(n-2)

Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341...
```

**Why use it?**
When inserting elements using binary search, the Jacobsthal sequence provides the optimal order that minimizes the worst-case number of comparisons.

## Technical Highlights

### Optimization for Small Arrays
- Arrays ≤ 10 elements use simple insertion sort
- Avoids overhead of complex algorithm for tiny datasets

### Binary Insertion
```cpp
// Uses std::lower_bound for O(log n) search
std::lower_bound(begin, end, value)
```

### Template Implementation
```cpp
template <typename Container>
void fordJohnsonSort(Container& container);
```
- Works with both vector and deque
- No code duplication
- Clean, maintainable design

## Performance Analysis

**Ford-Johnson vs Other Algorithms:**
- **Fewer comparisons** than quicksort or mergesort
- **More data movement** due to insertions
- **Optimal** for comparison count when n ≤ 47
- **Practical** for real-world use with modern optimizations

**Vector vs Deque Results:**
- Vector: Better cache locality → faster for most cases
- Deque: No reallocation → better for huge datasets
- Difference: Usually small (microseconds)
- Educational: Shows real-world container trade-offs

## Standards Compliance

- ✅ C++98 standard
- ✅ Compiled with `-Wall -Wextra -Werror`
- ✅ Orthodox Canonical Form implemented
- ✅ No memory leaks (verified with valgrind)
- ✅ Proper error handling
- ✅ Clean, readable code
- ✅ Template-based design

## Memory Management

Verified with valgrind:
```bash
$ valgrind --leak-check=full ./PmergeMe 3 5 9 7 4
...
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Testing

Run comprehensive test suite:
```bash
chmod +x test.sh
./test.sh
```

The test suite covers:
- Basic functionality (2-10 elements)
- Edge cases (odd/even, duplicates, sorted)
- Performance tests (50-200 elements)
- Error handling (negative, invalid, no args)

## References

- Ford-Johnson Algorithm (1959)
- Merge-Insertion Sort
- Jacobsthal Numbers
- Binary Insertion
- Comparison-based Sorting Algorithms

## Fun Facts

- The algorithm was published in 1959 by L. R. Ford Jr. and Selmer M. Johnson
- It held the record for minimum comparisons for decades
- Still optimal for n ≤ 22 elements
- Very close to optimal for n ≤ 47 elements
- Real-world implementations often use hybrid approaches

---

**Exercise 02 demonstrates mastery of:**
- Complex algorithm implementation
- STL container usage and comparison
- Template programming
- Performance measurement
- Algorithm optimization

