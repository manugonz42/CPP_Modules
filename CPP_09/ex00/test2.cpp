#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip> // Para std::fixed y std::setprecision

float string_to_float(const std::string& str) {
    std::stringstream ss(str);
    float result;
    ss >> result; // Extraer número
    return result;
}

unsigned long date_to_int(const std::string& date) {
    // Asegúrate de que la fecha tenga el formato correcto
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("Formato de fecha incorrecto");
    }

    // Convierte la fecha en formato YYYY-MM-DD a un entero
    std::string formatted_date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
    unsigned long result;
    std::stringstream ss(formatted_date);
    ss >> result; // Convertir a unsigned long
    return result;
}

int main() {
    std::map<unsigned long, float> map; // Usar float
    std::ifstream file("data.csv");
    
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 0;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string v1, v2;
        
        if (std::getline(ss, v1, ',') && std::getline(ss, v2)) {
            try {
                unsigned long key = date_to_int(v1); // Convierte el primer valor a unsigned long
                
                // Imprimir valores leídos para depuración
                std::cout << "Leyendo: v1 = " << v1 << ", v2 = " << v2 << std::endl;
                
                float value = string_to_float(v2); // Convierte el segundo valor a float
                map[key] = value; // Almacenar en el mapa
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << " en la línea: " << line << std::endl;
            }
        } else {
            std::cerr << "Error reading line (getline): " << line << std::endl;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2); // Establecer el formato de salida
    std::cout << "Imprimiendo mapa..." << std::endl;
    for (std::map<unsigned long, float>::const_iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
    
    file.close();
    return 0;
}
