#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe sorter;
        
        // Parse and validate input
        sorter.parseInput(argc, argv);
        
        // Display results with timing
        sorter.displayResults();
        
    } catch (const PmergeMe::InvalidArgumentException& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
