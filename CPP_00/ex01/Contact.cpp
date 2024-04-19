#include "Contact.hpp"

Contact::Contact(void) : _setted(false){
}
Contact::~Contact(void){
}

void    Contact::add_field(std::string field, std::string content){
    if (content == "EXIT"){
        std::cout << "You have closed succesfully the best PhoneBook of the history." << std::endl;
        exit(0);
    }
    while(content.length() <= 0){
        std::cout << "Fields in the Phonebook cannot be empty." << std::endl << "> " << std::flush;
        std::getline(std::cin, content);
        while(!std::cin.good()){
            std::cin.clear();
            std::cout << "Error reading, try again." << std::endl << "> " << std::flush;
            std::cin >> content;
        }
    }
    if (field == "fname")
        add_fname(content);
    else if (field == "lname")
        add_lname(content);
    else if (field == "phnum")
        add_phnum(content);
    else if (field == "nick")
        add_nick(content);
    else if (field == "secret")
        add_secret(content);
}
std::string intToString(int num) {
    std::string result;
    bool isNegative = false;

    // Manejar el caso especial de 0
    if (num == 0) {
        return "0";
    }

    // Manejar números negativos
    if (num < 0) {
        isNegative = true;
        num = -num; // Convertir el número a positivo para facilitar la conversión
    }

    // Convertir dígitos a caracteres y construir la cadena de derecha a izquierda
    while (num > 0) {
        char digit = '0' + (num % 10); // Convertir dígito a carácter
        result = digit + result; // Agregar dígito al principio de la cadena
        num /= 10; // Eliminar el dígito que ya hemos manejado
    }

    // Agregar el signo negativo si es necesario
    if (isNegative) {
        result = '-' + result;
    }

    return result;
}
void    Contact::add_index(int index){
    _index = intToString(index);// cambiar a std::to_string
}
void    Contact::add_fname(std::string fname){
    _first_name = fname;
}
void    Contact::add_lname(std::string lname){
    _last_name = lname;
}
void    Contact::add_phnum(std::string number){
    _phone_number = number;
}
void    Contact::add_nick(std::string nick){
    _nickname = nick;
}
void    Contact::add_secret(std::string secret){
    _darkest_secret = secret;
}
void    Contact::setted(bool set){
    _setted = set;
}
bool    Contact::is_setted(void) const{
    return _setted;
}
std::string Contact::filter(std::string content) const{
    std::string filtered;
    if (content.length() == 10)
        filtered = content;
    else if (content.length() > 10)
        filtered = content.substr(0, 9) + '.';
    else{
        filtered.assign(10 - content.length(), ' ');
        filtered.append(content);
    }
    return (filtered);
}

void    Contact::print_search_contact(void) const{
    std::cout << "|" << filter(_index) << "|" << filter(_first_name) << "|" << filter(_last_name) << "|" << filter(_nickname) << "|" << std::endl;
}
void    Contact::print_contact(void) const{
    std::cout << "First name:     " << _first_name << std::endl;
    std::cout << "Last name:      " << _last_name << std::endl;
    std::cout << "Nickname:       " << _nickname << std::endl;
    std::cout << "Phone number:   " << _phone_number << std::endl;
    std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}