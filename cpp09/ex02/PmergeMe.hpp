#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <sstream>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Jacobsthal sequence
    std::vector<size_t> generateJacobsthalSequence(size_t n);
    
    // Helper methods for Ford-Johnson algorithm
    template <typename Container>
    void fordJohnsonSort(Container& container);
    
    template <typename Container>
    void insertionSort(Container& container);
    
    template <typename Container>
    typename Container::iterator binaryInsert(Container& container, 
                                               typename Container::iterator begin,
                                               typename Container::iterator end,
                                               int value);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Main functionality
    bool parseInput(int argc, char** argv);
    void sortVector();
    void sortDeque();
    void displayResults(double vectorTime, double dequeTime);
    
    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;
};

#endif

