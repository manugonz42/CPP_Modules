#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <exception>
#include <iterator>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange {
    private:
        std::map<unsigned long, float> _priceDatabase;
        
        // Private helper methods
        void _loadPriceDatabase(const std::string& filename);
        unsigned long _dateToUlong(const std::string& date) const;
        int _stringToInt(const std::string& str) const;
        float _stringToFloat(const std::string& str) const;
        bool _isValidDate(const std::string& date) const;
        bool _isValidValue(const std::string& value) const;
        float _searchValueInDatabase(unsigned long date) const;
        void _parseLine(const std::string& line, bool& headerProcessed) const;
        
        // Orthodox Canonical Form - private to prevent copying
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

    public:
        // Orthodox Canonical Form
        BitcoinExchange();
        BitcoinExchange(const std::string& databaseFile);
        ~BitcoinExchange();
        
        // Public interface
        void processInputFile(const std::string& inputFile) const;
        bool isDatabaseLoaded() const;
};

#endif