#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <cerrno>
#include <climits>

class PmergeMe {
private:
    std::vector<int>    _vectorData;
    std::deque<int>     _dequeData;
    
    // Timing variables
    struct timeval _start;
    struct timeval _end;
    
    // Ford-Johnson algorithm for vector
    void _fordJohnsonVector(std::vector<int>& container);
    void _insertionSortVector(std::vector<int>& container, int value);
    
    // Ford-Johnson algorithm for deque
    void _fordJohnsonDeque(std::deque<int>& container);
    void _insertionSortDeque(std::deque<int>& container, int value);
    
    // Utility functions
    std::vector<int> _generateJacobsthalSequence(int n);
    bool _isValidInteger(const std::string& str);
    void _printSequence(const std::string& prefix, const std::vector<int>& sequence);
    //void _printVector(const std::string& label, const std::vector<int>& vec);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Main functionality
    bool parseInput(int argc, char** argv);
    void sortWithVector();
    void sortWithDeque();
    void displayResults();
    
    // Exception classes
    class InvalidArgumentException : public std::exception {
    public:
        const char* what() const throw() { return "Error: Invalid argument"; }
    };
};

#endif
