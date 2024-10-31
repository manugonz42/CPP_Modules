#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

class BitcoinExchange {
private:
    std::map<unsigned long, unsigned int> base;

    unsigned long fecha_a_entero(const std::string& fecha) {
        int year, month, day;
        char separator1, separator2;

        std::stringstream ss(fecha);
        ss >> year >> separator1 >> month >> separator2 >> day;

        return year * 10000 + month * 100 + day;
    }

    // Función para eliminar espacios en blanco al principio y al final
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return (first == std::string::npos) ? "" : str.substr(first, (last - first + 1));
    }

public:
    BitcoinExchange() {}

    void saveBase(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string fecha;
            std::string valueStr;

            if (std::getline(ss, fecha, ',') && std::getline(ss, valueStr)) {
                fecha = trim(fecha);
                valueStr = trim(valueStr);

                try {
                    unsigned long fechaInt = fecha_a_entero(fecha);
                    unsigned int value = std::stoul(valueStr); // Convertir el valor a unsigned int

                    base[fechaInt] = value; // Guardar en el mapa
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Valor no válido en la línea: " << line << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Valor fuera de rango en la línea: " << line << std::endl;
                }
            }
        }

        file.close();
    }

    void printBase() const {
        for (const auto& pair : base) {
            std::cout << "Fecha: " << pair.first << ", Valor: " << pair.second << std::endl;
        }
    }
};

int main() {
    BitcoinExchange exchange;
    exchange.saveBase("data.csv"); // Asegúrate de que el archivo data.csv esté en el directorio correcto
    exchange.printBase(); // Imprimir los valores guardados

    return 0;
}
