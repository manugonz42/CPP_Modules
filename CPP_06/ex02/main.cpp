#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate() {
    int i = rand() % 3;
    switch (i) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL; 
}
void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Object type: A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Object type: B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Object type: C" << std::endl;
}

void identify(Base& p){
    try {
        dynamic_cast<A&>(p);
        std::cout << "Object type: A" << std::endl;
    } catch (std::exception& e) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "Object type: B" << std::endl;
    } catch (std::exception& e) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "Object type: C" << std::endl;
    } catch (std::exception& e) {}
}

int main(void){
    Base* array[6];
    cout << endl << "---------GENERATING RANDOM OBJECTS------------" << endl<< endl<< endl;
    for (int i = 0; i < 6; i++)
        array[i] = generate();
    cout << "-------PRINTING OBJECTS BY REFERENCE----------" << endl;
    for (int i = 0; i < 6; i++)
        identify(array[i]);
    cout << "--------PRINTING OBJECTS BY POINTER-----------" << endl;
    for (int i = 0; i < 6; i++)
        identify(*array[i]);
}