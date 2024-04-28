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
    private:
        int velocidad;
    public:
        B(std::string n) : A(n), velocidad(10) {std::cout << "B const called"<<std::endl;
        this->velocidad = 10;
        setVelocidad(this->velocidad);
        };
        ~B() {std::cout << "B desst called"<<std::endl;};
        void    attack(void){std::cout << "ataca el B" << std::endl;};
        int     getVelocidad(void) {return this->velocidad;};
};
class C : virtual public A {
    private:
        int velocidad;
    public:
        C(std::string n) : A(n) {
            std::cout << "C const called"<<std::endl;
            this->velocidad = 20;
            setVelocidad(this->velocidad);
        };
        ~C() {std::cout << "C desst called"<<std::endl;};
        void    leer(void) {std::cout << "C leeyendo" << std::endl;};
        int     getVelocidad(void) {return this->velocidad;};
};
class D : public B, public C {
    private:
        std::string name;
    public:
        D(std::string n) : C(n + "_Cname"), B(n + "_bname"), A(n + "_aname") {
            std::cout <<  "D cons called" << std::endl;
            this->name = n;
            setVelocidad(B::getVelocidad());
            std::cout << "B:: " << B::getVelocidad() << " C:: " << C::getVelocidad() << std::endl;
        };
        ~D() {std::cout << "D desst called "<<std::endl;};
        std::string getName(void) {return this->name;};
        int     getVelocidad(void) {return A::getVelocidad();};
};

int main(int argc, char const *argv[])
{
    D a("pepe");
    std::cout << "a.getname: " << a.A::getName() << " this.name: "<< a.getName() << "velocidad " << a.getVelocidad() << std::endl;
    std::cout << "a.B::velocidad  " << a.B::getVelocidad() << " C.get " << a.C::getVelocidad() << std::endl;
    a.attack();
    a.leer();

    return 0;
}
