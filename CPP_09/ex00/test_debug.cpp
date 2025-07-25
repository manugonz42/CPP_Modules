#include <iostream>
#include <string>
using namespace std;

int main() {
    // Caso 1: pipe en posición 0
    string line1 = "|";
    size_t pos1 = line1.find('|');
    cout << "Línea: '" << line1 << "'" << endl;
    cout << "  size(): " << line1.size() << endl;
    cout << "  pipe_pos: " << pos1 << endl;
    cout << "  pipe_pos == 0? " << (pos1 == 0) << endl;
    
    // Caso 2: sin pipe
    string line2 = "sin pipe";
    size_t pos2 = line2.find('|');
    cout << "\nLínea: '" << line2 << "'" << endl;
    cout << "  pipe_pos: " << pos2 << endl;
    cout << "  string::npos: " << string::npos << endl;
    cout << "  pipe_pos == npos? " << (pos2 == string::npos) << endl;
    
    return 0;
}
