#include <iostream>
#include <string>

class   Rectangulo{
    private:
        int ancho;
        int largo;
    public:
        Rectangulo(int, int);
        void perimetro();
        void area();
};

Rectangulo::Rectangulo(int _ancho, int _largo){
    ancho = _ancho;
    largo = _largo;
}

void Rectangulo::perimetro(){
    std::cout << "El perimetro es: " << ( ancho * 2 + largo * 2 ) << "cm2." << std::endl;
}

void Rectangulo::area(){
    std::cout << "El perimetro es: " << (ancho * largo) << "cm2." << std::endl;
}

int main(int argc, char const *argv[])
{
    Rectangulo r1(2, 4);
    r1.perimetro();
    r1.area();
    return 0;
}
