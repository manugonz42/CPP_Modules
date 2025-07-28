#include "PmergeMe.hpp"

// ═══════════════════════════════════════════════════════════════════════════════
// ORTHODOX CANONICAL FORM
// ═══════════════════════════════════════════════════════════════════════════════

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ═══════════════════════════════════════════════════════════════════════════════
// INPUT PARSING AND VALIDATION
// ═══════════════════════════════════════════════════════════════════════════════

bool PmergeMe::_isValidInteger(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    // check negative number
    if (str[0] == '-')
        return false; 
    if (str[0] == '+')
        start = 1;
    
    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    // Check for overflow and within int range
    char* endptr;
    long num = std::strtol(str.c_str(), &endptr, 10);
    
    // Check for strtol errors (overflow/underflow)
    if (errno == ERANGE)
        return false;

    if (*endptr != '\0' || num > 2147483647 || num < 0) {
        return false;
    }
    
    return true;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        throw InvalidArgumentException();
    }
    
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        
        // Check if argument is empty or contains only whitespace
        if (arg.empty()) {
            throw InvalidArgumentException();
        }
        
        // Check if argument contains only whitespace characters
        bool hasNonWhitespace = false;
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!std::isspace(arg[j])) {
                hasNonWhitespace = true;
                break;
            }
        }
        if (!hasNonWhitespace) {
            throw InvalidArgumentException();
        }
        
        std::istringstream iss(arg);
        std::string token;
        bool foundAnyToken = false;
        
        // Split by whitespace and process each token
        while (iss >> token) {
            foundAnyToken = true;
            if (!_isValidInteger(token)) {
                throw InvalidArgumentException();
            }
            
            // Use same conversion method as validation for consistency
            char* endptr;
            long longValue = std::strtol(token.c_str(), &endptr, 10);
            int value = static_cast<int>(longValue);
            _vectorData.push_back(value);
            _dequeData.push_back(value);
        }
        
        // If no tokens were found after processing, it means the argument was invalid
        if (!foundAnyToken) {
            throw InvalidArgumentException();
        }
    }
    
    return true;
}

// ═══════════════════════════════════════════════════════════════════════════════
// JACOBSTHAL SEQUENCE GENERATION
// ═══════════════════════════════════════════════════════════════════════════════

std::vector<int> PmergeMe::_generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

// ═══════════════════════════════════════════════════════════════════════════════
// FORD-JOHNSON ALGORITHM FOR VECTOR
// ═══════════════════════════════════════════════════════════════════════════════

/*void PmergeMe::_printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}*/

void PmergeMe::_insertionSortVector(std::vector<int>& container, int value) {
    // Binary search for optimal insertion position
    std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

void PmergeMe::_fordJohnsonVector(std::vector<int>& container) {
    if (container.size() <= 1) return;
    
    // For small arrays, use simple insertion sort instead of Ford-Johnson
    if (container.size() <= 16) {
        std::sort(container.begin(), container.end());
        return;
    }
    
    // Step 1: Pair elements and sort pairs
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (container.size() % 2 == 1);
    
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }
    
    // Create pairs and ensure first <= second
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = container[i + 1];
        if (first > second) std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    // Step 2: Create main sequence with larger elements and pending with lo
    std::vector<int> mainSequence;
    std::vector<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainSequence.push_back(pairs[i].second);
        pendingElements.push_back(pairs[i].first);
    }

    // Step 3: Recursively sort main sequence
    _fordJohnsonVector(mainSequence);

    // Step 4: Insert pending elements using Jacobsthal order
    std::vector<int> jacobsthal = _generateJacobsthalSequence(pendingElements.size());
    std::vector<bool> inserted(pendingElements.size(), false);
    
    // Insert first element directly
    if (!pendingElements.empty()) {
        _insertionSortVector(mainSequence, pendingElements[0]);
        inserted[0] = true;
    }
    
    // Insert remaining elements in Jacobsthal order
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= (int)pendingElements.size(); ++i) {
        int jacobsthalIndex = jacobsthal[i] - 1;
        if (jacobsthalIndex >= 0 && jacobsthalIndex < (int)pendingElements.size() && !inserted[jacobsthalIndex]) {
            _insertionSortVector(mainSequence, pendingElements[jacobsthalIndex]);
            inserted[jacobsthalIndex] = true;
        }
        
        // Insert elements between previous and current Jacobsthal number in reverse order
        for (int j = jacobsthalIndex - 1; j >= jacobsthal[i-1] && j >= 0; --j) {
            if (!inserted[j]) {
                _insertionSortVector(mainSequence, pendingElements[j]);
                inserted[j] = true;
            }
        }
    }
    
    // Insert any remaining elements
    for (size_t i = 0; i < inserted.size(); ++i) {
        if (!inserted[i]) {
            _insertionSortVector(mainSequence, pendingElements[i]);
        }
    }
    
    // Insert straggler if exists
    if (hasStraggler) {
        _insertionSortVector(mainSequence, straggler);
    }
    
    container = mainSequence;
}

// ═══════════════════════════════════════════════════════════════════════════════
// FORD-JOHNSON ALGORITHM FOR DEQUE
// ═══════════════════════════════════════════════════════════════════════════════

void PmergeMe::_insertionSortDeque(std::deque<int>& container, int value) {
    // Optimized insertion for deque - check ends first for better performance
    if (container.empty()) {
        container.push_back(value);
        return;
    }
    
    // Check front first (most common case for small values)
    if (value <= container.front()) {
        container.push_front(value);  // O(1) for deque vs O(n) for vector
        return;
    }
    
    // Check back (common case for large values)
    if (value >= container.back()) {
        container.push_back(value);   // O(1) for both, but avoids search
        return;
    }
    
    // For middle insertions, use optimized strategy
    size_t size = container.size();
    
    // For small containers, check if closer to front or back
    if (size <= 32) {
        // Check if value is closer to front (first quarter)
        if (value <= container[size / 4]) {
            // Search from front - potentially better for deque
            std::deque<int>::iterator pos = std::lower_bound(container.begin(), 
                                                           container.begin() + size/2, value);
            container.insert(pos, value);
            return;
        }
        // Check if value is closer to back (last quarter)
        else if (value >= container[3 * size / 4]) {
            // Search from back portion
            std::deque<int>::iterator pos = std::lower_bound(container.begin() + size/2, 
                                                           container.end(), value);
            container.insert(pos, value);
            return;
        }
    }
    
    // Standard binary search for optimal insertion position
    std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

void PmergeMe::_fordJohnsonDeque(std::deque<int>& container) {
    if (container.size() <= 1) return;
    
    // For small arrays, use simple insertion sort instead of Ford-Johnson
    if (container.size() <= 16) {
        std::sort(container.begin(), container.end());
        return;
    }
    
    // Step 1: Pair elements and sort pairs
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (container.size() % 2 == 1);
    
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }
    
    // Create pairs and ensure first <= second
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = container[i + 1];
        if (first > second) std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    // Step 2: Create main sequence with larger elements - optimized for deque
    std::deque<int> mainSequence;
    std::vector<int> pendingElements;
    
    // Build sequences efficiently for deque
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainSequence.push_back(pairs[i].second);
        pendingElements.push_back(pairs[i].first);
    }
    
    // Step 3: Recursively sort main sequence
    _fordJohnsonDeque(mainSequence);
    
    // Step 4: Insert pending elements using Jacobsthal order
    std::vector<int> jacobsthal = _generateJacobsthalSequence(pendingElements.size());
    std::vector<bool> inserted(pendingElements.size(), false);
    
    // Insert first element directly - optimized for deque
    if (!pendingElements.empty()) {
        // First pending element is often smallest, try front insertion first
        if (mainSequence.empty() || pendingElements[0] <= mainSequence.front()) {
            mainSequence.push_front(pendingElements[0]);
        } else {
            _insertionSortDeque(mainSequence, pendingElements[0]);
        }
        inserted[0] = true;
    }
    
    // Insert remaining elements in Jacobsthal order
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= (int)pendingElements.size(); ++i) {
        int jacobsthalIndex = jacobsthal[i] - 1;
        if (jacobsthalIndex >= 0 && jacobsthalIndex < (int)pendingElements.size() && !inserted[jacobsthalIndex]) {
            _insertionSortDeque(mainSequence, pendingElements[jacobsthalIndex]);
            inserted[jacobsthalIndex] = true;
        }
        
        // Insert elements between previous and current Jacobsthal number in reverse order
        for (int j = jacobsthalIndex - 1; j >= jacobsthal[i-1] && j >= 0; --j) {
            if (!inserted[j]) {
                _insertionSortDeque(mainSequence, pendingElements[j]);
                inserted[j] = true;
            }
        }
    }
    
    // Insert any remaining elements
    for (size_t i = 0; i < inserted.size(); ++i) {
        if (!inserted[i]) {
            _insertionSortDeque(mainSequence, pendingElements[i]);
        }
    }
    
    // Insert straggler if exists - optimized for deque
    if (hasStraggler) {
        // Straggler is often largest or smallest, check ends first
        if (mainSequence.empty() || straggler <= mainSequence.front()) {
            mainSequence.push_front(straggler);
        } else if (straggler >= mainSequence.back()) {
            mainSequence.push_back(straggler);
        } else {
            _insertionSortDeque(mainSequence, straggler);
        }
    }
    
    container = mainSequence;
}

// ═══════════════════════════════════════════════════════════════════════════════
// SORTING METHODS WITH TIMING
// ═══════════════════════════════════════════════════════════════════════════════

void PmergeMe::sortWithVector() {
    gettimeofday(&_start, NULL);
    _fordJohnsonVector(_vectorData);
    gettimeofday(&_end, NULL);
}

void PmergeMe::sortWithDeque() {
    gettimeofday(&_start, NULL);
    _fordJohnsonDeque(_dequeData);
    gettimeofday(&_end, NULL);
}

// ═══════════════════════════════════════════════════════════════════════════════
// DISPLAY METHODS
// ═══════════════════════════════════════════════════════════════════════════════

void PmergeMe::_printSequence(const std::string& prefix, const std::vector<int>& sequence) {
    std::cout << prefix;
    for (size_t i = 0; i < sequence.size() && i < 5; ++i) {
        std::cout << sequence[i];
        if (i < sequence.size() - 1 && i < 4) std::cout << " ";
    }
    if (sequence.size() > 5) {
        std::cout << " [...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayResults() {
    // Store original for "Before" display
    std::vector<int> original = _vectorData;
    
    // Display before sorting
    _printSequence("Before: ", original);
    
    // Sort with vector and measure time
    struct timeval vectorStart, vectorEnd;
    gettimeofday(&vectorStart, NULL);
    _fordJohnsonVector(_vectorData);
    gettimeofday(&vectorEnd, NULL);
    
    // Sort with deque and measure time
    struct timeval dequeStart, dequeEnd;
    gettimeofday(&dequeStart, NULL);
    _fordJohnsonDeque(_dequeData);
    gettimeofday(&dequeEnd, NULL);
    
    // Display after sorting
    _printSequence("After:  ", _vectorData);
    
    // Calculate and display timing
    double vectorDuration = (vectorEnd.tv_sec - vectorStart.tv_sec) * 1000000.0 + 
                           (vectorEnd.tv_usec - vectorStart.tv_usec);
    double dequeDuration = (dequeEnd.tv_sec - dequeStart.tv_sec) * 1000000.0 + 
                          (dequeEnd.tv_usec - dequeStart.tv_usec);
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorDuration << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << dequeDuration << " us" << std::endl;
}
