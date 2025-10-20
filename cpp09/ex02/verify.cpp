#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe sorter;
    
    if (!sorter.parseInput(argc, argv)) {
        return 1;
    }
    
    sorter.sortVector();
    
    const std::vector<int>& result = sorter.getVector();
    
    std::cout << "Full sorted output: ";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    // Verify it's sorted
    bool sorted = true;
    for (size_t i = 1; i < result.size(); ++i) {
        if (result[i] < result[i-1]) {
            sorted = false;
            break;
        }
    }
    
    std::cout << "Is sorted: " << (sorted ? "YES" : "NO") << std::endl;
    
    return 0;
}

