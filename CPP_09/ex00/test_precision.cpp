#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string value = "1000.00000000000000000000000000000000000000001";
    double val = 0;
    std::stringstream ss(value);
    ss >> val;
    std::cout << "val = " << std::fixed << std::setprecision(20) << val << std::endl;
    std::cout << "val > 1000? " << (val > 1000) << std::endl;
    return 0;
}
