#include "PmergeMe.hpp"

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

int main(int argc, char** argv) {
    PmergeMe sorter;
    
    // Parse input
    if (!sorter.parseInput(argc, argv)) {
        return 1;
    }
    
    // Display "Before"
    std::cout << "Before: ";
    const std::vector<int>& original = sorter.getVector();
    for (size_t i = 0; i < original.size() && i < 10; ++i) {
        std::cout << original[i];
        if (i < original.size() - 1 && i < 9) std::cout << " ";
    }
    if (original.size() > 10) {
        std::cout << " [...]";
    }
    std::cout << std::endl;
    
    // Sort with vector and measure time
    double startVector = getTime();
    sorter.sortVector();
    double endVector = getTime();
    double vectorTime = endVector - startVector;
    
    // Re-parse for deque (since we need fresh data)
    PmergeMe sorter2;
    sorter2.parseInput(argc, argv);
    
    // Sort with deque and measure time
    double startDeque = getTime();
    sorter2.sortDeque();
    double endDeque = getTime();
    double dequeTime = endDeque - startDeque;
    
    // Display results
    sorter.displayResults(vectorTime, dequeTime);
    
    return 0;
}

