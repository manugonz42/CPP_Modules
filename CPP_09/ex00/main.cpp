#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments\n\t USAGE: ./btc file\n" << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        
        if (!exchange.isDatabaseLoaded()) {
            std::cerr << "Error: Failed to load price database." << std::endl;
            return 1;
        }
        
        exchange.processInputFile(argv[1]);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
