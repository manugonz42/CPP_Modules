#include <iostream>
#include <string.h>

class A{
    private:
        std::string name;
        int         velocidad;
        int         daño;
        int         vida;
    public:
        A(){};
        A(std::string n){std::cout << "A const called"<<std::endl; this->name = n;};
        ~A(){std::cout << "A desst called"<<std::endl;};
        void setName(std::string newName){this->name = newName;};
        std::string getName(void){return this->name;};
        void    attack(void){std::cout << "ataca el padre" << std::endl;};
        void    setVelocidad(int velocidad) {this->velocidad = velocidad; std::cout << "setting velocidad: "<< this->velocidad << std::endl;};
        int     getVelocidad(void) {return this->velocidad;};
};
class B : virtual public A {
    public:
        B(std::string n) : A(n) {std::cout << "B const called"<<std::endl; setVelocidad(10);};
        ~B() {std::cout << "B desst called"<<std::endl;};
        void    attack(void){std::cout << "ataca el B" << std::endl;};
};
class C : virtual public A {
    public:
        C(std::string n) : A(n) {std::cout << "C const called"<<std::endl;setVelocidad(20);};
        ~C() {std::cout << "C desst called"<<std::endl;};
        void    leer(void) {std::cout << "C leeyendo" << std::endl;};
};
class D : public B, public C {
    private:
        std::string name;
    public:
        D(std::string n) : C(n + "_Cname"), B(n + "_bname"), A(n + "_aname") {std::cout <<  "D cons called" << std::endl; this->name = n;setVelocidad(B::getVelocidad());};
        ~D() {std::cout << "D desst called"<<std::endl;};
        std::string getName(void) {return this->name;};
};

int main(int argc, char const *argv[])
{
    D a("pepe");
    std::cout << "a.getname: " << a.A::getName() << " this.name: "<< a.getName() << "velocidad " << a.getVelocidad() << std::endl;
    std::cout << "a.B::velocidad  " << a.B::getVelocidad() << std::endl;
    a.A::attack();
    a.leer();

    return 0;
}
