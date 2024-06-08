#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const string& type) : type(type) {}
AMateria::AMateria(const AMateria& other) { type = other.type; }
AMateria& AMateria::operator=(const AMateria& other) { if (this !=&other) type = other.type; return *this; }
AMateria::~AMateria() {}
std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) {
    if (getType() == "ice")
        cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
    if (getType() == "cure")
        cout << "* heals " << target.getName() << "’s wounds *" << endl;
}