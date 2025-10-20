# Exercise 00 - Bitcoin Exchange

## Description
A program that calculates the value of Bitcoin amounts on specific dates using historical exchange rate data.

## Implementation Details

### Classes
- **BitcoinExchange**: Main class implementing the Bitcoin exchange rate lookup
  - Follows Orthodox Canonical Form (Coplien Form)
  - Uses `std::map<std::string, float>` for efficient date-based lookups
  - Implements closest earlier date algorithm using `lower_bound()`

### Features
- ✅ Loads historical exchange rates from CSV database
- ✅ Processes input queries with date and value
- ✅ Finds exact or closest earlier date for exchange rate
- ✅ Comprehensive date validation (including leap years)
- ✅ Robust error handling for all edge cases
- ✅ No memory leaks (verified with valgrind)

### Error Handling
- Invalid date formats (YYYY-MM-DD required)
- Dates outside valid range (2009-2024)
- Invalid month/day combinations
- Leap year validation
- Negative values
- Values exceeding 1000
- Non-numeric inputs
- Missing files
- Malformed input lines

## Compilation
```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## Usage
```bash
./btc <input_file>
```

### Input Format
The input file should contain lines with format:
```
date | value
2011-01-03 | 3
2012-01-11 | 1
```

### Database Format
The `data.csv` file should have format:
```
date,exchange_rate
2009-01-02,0
2011-01-03,2.0
```

## Examples

### Valid Queries
```bash
$ ./btc input.txt
2011-01-03 => 3 = 6
2011-01-09 => 1 = 1.5
2012-01-11 => 1 = 18.7
```

### Error Cases
```bash
$ ./btc input.txt
Error: not a positive number.         # Negative value
Error: too large a number.            # Value > 1000
Error: bad input => 2001-01-01        # Date before 2009
Error: could not open file.           # Missing file
```

## Testing
Included test files:
- `input.txt` - Basic test cases
- `test_edge_cases.txt` - Edge case validation
- `test_closest_date.txt` - Closest earlier date logic

Run valgrind to verify no memory leaks:
```bash
valgrind --leak-check=full ./btc input.txt
```

## Technical Highlights

### Container Choice: std::map
- **Automatic sorting**: Keys (dates) are kept in chronological order
- **Efficient lookup**: O(log n) search complexity
- **lower_bound()**: Enables finding closest earlier date efficiently
- **No duplicates**: Each date has exactly one exchange rate

### Algorithm: Closest Earlier Date
```cpp
// If exact date not found, find closest earlier date
it = _database.lower_bound(date);
if (it == _database.begin()) {
    return -1.0f; // Date before all database entries
}
--it; // Go back one position to get closest earlier date
return it->second;
```

This algorithm leverages std::map's sorted nature to efficiently find the closest earlier date in O(log n) time.

## Standards Compliance
- ✅ C++98 standard
- ✅ Compiled with `-Wall -Wextra -Werror`
- ✅ Orthodox Canonical Form implemented
- ✅ No memory leaks
- ✅ Proper error handling
- ✅ Clean, readable code

