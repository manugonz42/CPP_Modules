#include "BitcoinExchange.hpp"

unsigned long date_to_int(const std::string& date) {
    std::string formatted_date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
    unsigned long result;
    std::stringstream ss(formatted_date);
    ss >> result; // Convertir a unsigned long
    return result;
}
float string_to_int(const std::string& str) {
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
void    save_base(std::map<unsigned long, float> &map){
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
            unsigned long key = date_to_int(v1); // Convierte el primer valor a unsigned long (ajusta según tu necesidad)
            float value = string_to_float(v2); // Convierte el segundo valor a unsigned int
            map[key] = value;
        } else {
            std::cerr << "Error reading line (getline) " << line << std::endl;
        }
    }
    file.close();
}

int is_valid_date(string date){
    int m, d;
    if (date.size() != 10 || date[4] != '-' || date [7] != '-')
        return 0;
    for (int i = 0; i < 10; i++){
        if (i == 4 || i == 7)
            continue ;
        if (!std::isdigit(date[i]))
            return 0;
    }
    m = string_to_int(date.substr(5, 2));
    d = string_to_int(date.substr(8, 2));
    if (m > 12 || d > 31)
        return 0;
    if (date_to_int(date) < 20090102)
        return 0;
    return 1;
}

int is_valid_value(string value){
    int point_count = 0;
    for (size_t i = 0; i < value.size(); i++){
        if (!std::isdigit(value[i])){
            if (value[i] == '.' && point_count == 0){
                point_count = 1;
                continue ;
            }
            std::cerr << "Error: not a positive number." << endl;
            return 0;
        }
    }
    unsigned long long val = string_to_int(value);
    if (val > 1000){
       std::cerr << "Error: too large a number." << endl;
        return 0;    
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

int parse_line(string line, std::map<unsigned long, float> &base){
    size_t pipe_pos = line.find('|');
    if (pipe_pos == string::npos){
        std::cerr << "Error: bad input => " << line << endl;
        return 0;
    }
    if (line[pipe_pos - 1] != ' ' || line[pipe_pos + 1] != ' '){
        std::cerr << "Error: bad input => " << line << endl;
        return 0;
    }
    string date = line.substr(0, pipe_pos - 1);
    string value = line.substr(pipe_pos + 2);
    if (!is_valid_date(date)){
        std::cerr << "Error: bad input => " << line << endl;
        return 0;    
    }
    else if (!is_valid_value(value))
        return 0;
    float prize = search_value_in_base(date_to_int(date), base);
    float quant = string_to_float(value);
    cout << date << " => " << value << " = " << prize * quant << endl;
    return 1;
}


int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: Invalid arguments\n\t USAGE: btc file\n" << endl;
        return 1;
    }
    std::ifstream db("data.csv");
    std::ifstream file(argv[1]);
    if (!db.is_open() || !file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    //std::cout << std::fixed << std::setprecision(2);
    std::map<unsigned long, float> base;
    save_base(base);
    string line;
    getline(file, line);
    while (std::getline(file, line)) {
        parse_line(line, base);
    }
    file.close();
    
    return 0;
}