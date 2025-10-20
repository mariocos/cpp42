#include "PmergeMe.hpp"

// Orthodox Canonical Form

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) 
    : _vectorData(other._vectorData), _dequeData(other._dequeData) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

// Jacobsthal sequence generator
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    
    while (true) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

// Binary insertion helper
template <typename Container>
typename Container::iterator PmergeMe::binaryInsert(Container& container,
                                                      typename Container::iterator begin,
                                                      typename Container::iterator end,
                                                      int value) {
    return container.insert(std::lower_bound(begin, end, value), value);
}

// Insertion sort for small sequences
template <typename Container>
void PmergeMe::insertionSort(Container& container) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        int value = *it;
        typename Container::iterator pos = it;
        
        while (pos != container.begin()) {
            typename Container::iterator prev = pos;
            --prev;
            if (*prev <= value) break;
            *pos = *prev;
            pos = prev;
        }
        *pos = value;
    }
}

// Ford-Johnson merge-insertion sort algorithm
template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    size_t n = container.size();
    
    // Base cases
    if (n <= 1) {
        return;
    }
    
    if (n == 2) {
        if (container[0] > container[1]) {
            std::swap(container[0], container[1]);
        }
        return;
    }
    
    // Use simple insertion sort for very small arrays
    if (n <= 10) {
        insertionSort(container);
        return;
    }
    
    // Step 1: Pair elements and sort within pairs
    Container larger;
    Container smaller;
    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);
    
    if (hasStraggler) {
        straggler = container[n - 1];
    }
    
    size_t pairs = n / 2;
    
    for (size_t i = 0; i < pairs; ++i) {
        int a = container[2 * i];
        int b = container[2 * i + 1];
        
        if (a > b) {
            larger.push_back(a);
            smaller.push_back(b);
        } else {
            larger.push_back(b);
            smaller.push_back(a);
        }
    }
    
    // Step 2: Recursively sort the larger elements
    fordJohnsonSort(larger);
    
    // Step 3 & 4: Build result by merging sorted larger with smaller using binary insertion
    Container result;
    result = larger;  // Start with sorted larger elements
    
    // Binary insert all smaller elements
    for (size_t i = 0; i < smaller.size(); ++i) {
        binaryInsert(result, result.begin(), result.end(), smaller[i]);
    }
    
    // Step 5: Insert straggler if exists
    if (hasStraggler) {
        binaryInsert(result, result.begin(), result.end(), straggler);
    }
    
    // Copy result back to container
    container = result;
}

// Input parsing
bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // Check if all characters are digits
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
        
        // Convert to integer
        char* end;
        long num = strtol(arg.c_str(), &end, 10);
        
        if (*end != '\0' || num < 0 || num > 2147483647) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
    
    return true;
}

// Sort using vector
void PmergeMe::sortVector() {
    fordJohnsonSort(_vectorData);
}

// Sort using deque
void PmergeMe::sortDeque() {
    fordJohnsonSort(_dequeData);
}

// Display results
void PmergeMe::displayResults(double vectorTime, double dequeTime) {
    size_t n = _vectorData.size();
    
    std::cout << "After:  ";
    size_t displayLimit = (n > 10) ? 10 : n;
    for (size_t i = 0; i < displayLimit; ++i) {
        std::cout << _vectorData[i];
        if (i < displayLimit - 1) std::cout << " ";
    }
    if (n > 10) {
        std::cout << " [...]";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << n 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << n 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDeque() const {
    return _dequeData;
}

// Explicit template instantiations
template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::insertionSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::insertionSort<std::deque<int> >(std::deque<int>&);

