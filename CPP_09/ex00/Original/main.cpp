#include "BitcoinExchange.hpp"

unsigned long date_to_ulong(const std::string& date) {
    std::string formatted_date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
    unsigned long result;
    std::stringstream ss(formatted_date);
    ss >> result; // Convertir a unsigned long
    return result;
}
int string_to_int(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result; // Extract number
    return result;
}
float string_to_float(const std::string& str) {
    std::stringstream ss(str);
    float result;
    ss >> result; // Extract number
    return result;
}
void    save_price_db(std::map<unsigned long, float> &map){
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return ;
    }
    string line;
    getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        string v1, v2;
        if (std::getline(ss, v1, ',') && std::getline(ss, v2)) {
            unsigned long key = date_to_ulong(v1); // Convierte el primer valor a unsigned long 
            float value = string_to_float(v2); // Convierte el segundo valor a float
            map[key] = value;
        } else {
            std::cerr << "Error reading line (getline) " << line << std::endl;
        }
    }
    file.close();
}

int is_valid_date(string date){
    int m, d, y;
    if (date.size() != 10 || date[4] != '-' || date [7] != '-')
        return 0;
    for (int i = 0; i < 10; i++){
        if (i == 4 || i == 7)
            continue ;
        if (!std::isdigit(date[i]))
            return 0;
    }
    y = string_to_int(date.substr(0, 4));
    m = string_to_int(date.substr(5, 2));
    d = string_to_int(date.substr(8, 2));
    
    // Basic range checks
    if (m > 12 || d > 31 || d < 1 || m < 1)
        return 0;
        
    // Days per month validation
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year check
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        days_in_month[1] = 29;
    }
    
    if (d > days_in_month[m - 1])
        return 0;
        
    if (date_to_ulong(date) < 20090102 || date_to_ulong(date) > 20250901)
        return 0;
    return 1;
}

int is_valid_value(string value){
    int point_count = 0;
    if (value.empty()){
        std::cerr << "Error: not a positive number." << endl;
        return 0;
    }
    for (size_t i = 0; i < value.size(); i++){
        if (!std::isdigit(value[i])){
            if (i == 0){
                std::cerr << "Error: not a positive number." << endl;
                return 0;
            }
            if (value[i] == '.' && point_count == 0){
                point_count = 1;
                continue ;
            }
            std::cerr << "Error: not a positive number." << endl;
            return 0;
        }
    }
    
    // Check if number is greater than 1000 by string comparison
    size_t dot_pos = value.find('.');
    string integer_part;
    if (dot_pos != string::npos) {
        integer_part = value.substr(0, dot_pos);
    } else {
        integer_part = value;
    }
    
    // If integer part has more than 4 digits, it's definitely > 1000
    if (integer_part.length() > 4) {
        std::cerr << "Error: too large a number." << endl;
        return 0;
    }
    
    // If integer part has exactly 4 digits, compare with "1000"
    if (integer_part.length() == 4) {
        if (integer_part > "1000") {
            std::cerr << "Error: too large a number." << endl;
            return 0;
        }
        // If it's exactly "1000", check if there are any non-zero decimal digits
        if (integer_part == "1000" && dot_pos != string::npos) {
            string decimal_part = value.substr(dot_pos + 1);
            for (size_t i = 0; i < decimal_part.length(); i++) {
                if (decimal_part[i] != '0') {
                    std::cerr << "Error: too large a number." << endl;
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

float   search_value_in_base(unsigned long date, std::map<unsigned long, float> &base){
    std::map<unsigned long, float>::iterator it;
    for (it = base.begin(); it != base.end(); it++){
        if (it->first >= date)
            break;
    }
    if (it != base.end() && date == it->first)
        return it->second;
    it--;
    return it->second;
}

void parse_line(int &start, string line, std::map<unsigned long, float> &base){
    size_t pipe_pos = line.find('|');
    if (start == 0){
        if (line == "date | value")
            return ;
        start = 1;
    }
    if (pipe_pos == string::npos){
        std::cerr << "Error: bad input => " << line << endl;
        return ;
    }
    if (pipe_pos == 0 || pipe_pos + 1 >= line.size()){

            std::cerr << "Error: bad input => " << line << endl;
        return ;
    }
    if (line[pipe_pos - 1] != ' ' || line[pipe_pos + 1] != ' '){
        std::cerr << "Error: bad input => " << line << endl;
        return ;
    }
    string date = line.substr(0, pipe_pos - 1);
    string value = line.substr(pipe_pos + 2);
    if (!is_valid_date(date)){
        std::cerr << "Error: bad input => " << line << endl;
        return ;    
    }
    else if (!is_valid_value(value))
        return ;
    float prize = search_value_in_base(date_to_ulong(date), base);
    double quant = 0;
    std::stringstream ss(value);
    ss >> quant;
    
    // For display, use the original value but remove leading zeros for integers
    string display_value = value;
    if (quant == (int)quant) {
        // It's a whole number, convert to int to remove leading zeros and .0
        std::ostringstream int_stream;
        int_stream << (int)quant;
        display_value = int_stream.str();
    }
    // For decimals, keep the original string to preserve precision
    
    cout << date << " => " << display_value << " = " << std::fixed << std::setprecision(2) << prize * quant << endl;
    return ;
}

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: Invalid arguments\n\t USAGE: ./btc file\n" << endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    //std::cout << std::fixed << std::setprecision(2);
    std::map<unsigned long, float> base;
    save_price_db(base);
    
    if (base.empty()) {
        std::cerr << "Error: Empty price database." << std::endl;
        return 1;
    }
    
    string line;
    int start = 0;
    while (std::getline(file, line)) {
        parse_line(start, line, base);
    }
    file.close();
    
    return 0;
}