#include "BitcoinExchange.hpp"

// Orthodox Canonical Form implementation
BitcoinExchange::BitcoinExchange() {
    _loadPriceDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    _loadPriceDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _priceDatabase = other._priceDatabase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _priceDatabase = other._priceDatabase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    // No dynamic memory allocation, so nothing to clean up
}

// Private helper methods implementation
void BitcoinExchange::_loadPriceDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dateStr, valueStr;
        
        if (std::getline(ss, dateStr, ',') && std::getline(ss, valueStr)) {
            unsigned long key = _dateToUlong(dateStr);
            float value = _stringToFloat(valueStr);
            _priceDatabase[key] = value;
        } else {
            std::cerr << "Error: bad line in database => " << line << std::endl;
        }
    }
    file.close();
}

unsigned long BitcoinExchange::_dateToUlong(const std::string& date) const {
    std::string formatted_date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
    unsigned long result;
    std::stringstream ss(formatted_date);
    ss >> result;
    return result;
}

int BitcoinExchange::_stringToInt(const std::string& str) const {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return result;
}

float BitcoinExchange::_stringToFloat(const std::string& str) const {
    std::stringstream ss(str);
    float result;
    ss >> result;
    return result;
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
        
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int y = _stringToInt(date.substr(0, 4));
    int m = _stringToInt(date.substr(5, 2));
    int d = _stringToInt(date.substr(8, 2));
    
    // Basic range checks
    if (m > 12 || d > 31 || d < 1 || m < 1)
        return false;
        
    // Days per month validation
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year check
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        days_in_month[1] = 29;
    }
    
    if (d > days_in_month[m - 1])
        return false;
        
    if (_dateToUlong(date) < 20090102 || _dateToUlong(date) > 20250901)
        return false;
        
    return true;
}

bool BitcoinExchange::_isValidValue(const std::string& value) const {
    int point_count = 0;
    if (value.empty()) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    
    for (size_t i = 0; i < value.size(); i++) {
        if (!std::isdigit(value[i])) {
            if (i == 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                return false;
            }
            if (value[i] == '.' && point_count == 0) {
                point_count = 1;
                continue;
            }
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
    }
    
    // Check if number is greater than 1000 by string comparison
    size_t dot_pos = value.find('.');
    std::string integer_part;
    if (dot_pos != std::string::npos) {
        integer_part = value.substr(0, dot_pos);
    } else {
        integer_part = value;
    }
    
    // If integer part has more than 4 digits, it's definitely > 1000
    if (integer_part.length() > 4) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    // If integer part has exactly 4 digits, compare with "1000"
    if (integer_part.length() == 4) {
        if (integer_part > "1000") {
            std::cerr << "Error: too large a number." << std::endl;
            return false;
        }
        // If it's exactly "1000", check if there are any non-zero decimal digits
        if (integer_part == "1000" && dot_pos != std::string::npos) {
            std::string decimal_part = value.substr(dot_pos + 1);
            for (size_t i = 0; i < decimal_part.length(); i++) {
                if (decimal_part[i] != '0') {
                    std::cerr << "Error: too large a number." << std::endl;
                    return false;
                }
            }
        }
    }
    
    return true;
}

float BitcoinExchange::_searchValueInDatabase(unsigned long date) const {
    std::map<unsigned long, float>::const_iterator it;
    for (it = _priceDatabase.begin(); it != _priceDatabase.end(); ++it) {
        if (it->first >= date)
            break;
    }
    if (it != _priceDatabase.end() && date == it->first)
        return it->second;
    --it;
    return it->second;
}

void BitcoinExchange::_parseLine(const std::string& line, bool& headerProcessed) const {
    size_t pipe_pos = line.find('|');
    
    if (!headerProcessed) {
        if (line == "date | value")
            return;
        headerProcessed = true;
    }
    
    if (pipe_pos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    
    if (pipe_pos == 0 || pipe_pos + 1 >= line.size()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    
    if (line[pipe_pos - 1] != ' ' || line[pipe_pos + 1] != ' ') {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    
    std::string date = line.substr(0, pipe_pos - 1);
    std::string value = line.substr(pipe_pos + 2);
    
    if (!_isValidDate(date)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    } else if (!_isValidValue(value)) {
        return;
    }
    
    float price = _searchValueInDatabase(_dateToUlong(date));
    double quantity = 0;
    std::stringstream ss(value);
    ss >> quantity;
    
    // For display, use the original value but remove leading zeros for integers
    std::string display_value = value;
    if (quantity == (int)quantity) {
        // It's a whole number, convert to int to remove leading zeros and .0
        std::ostringstream int_stream;
        int_stream << (int)quantity;
        display_value = int_stream.str();
    }
    // For decimals, keep the original string to preserve precision
    
    std::cout << date << " => " << display_value << " = " 
              << std::fixed << std::setprecision(2) << price * quantity << std::endl;
}

// Public interface implementation
void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    if (_priceDatabase.empty()) {
        std::cerr << "Error: Empty price database." << std::endl;
        return;
    }
    
    std::string line;
    bool headerProcessed = false;
    while (std::getline(file, line)) {
        _parseLine(line, headerProcessed);
    }
    file.close();
}

bool BitcoinExchange::isDatabaseLoaded() const {
    return !_priceDatabase.empty();
}