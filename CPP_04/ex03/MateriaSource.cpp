#include "MateriaSource.hpp"
#include "Character.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++){
		learned[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other){
    for (int i = 0; i < 4; i++){
        learned[i] = other.learned[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if(this != &other){
        for (int i = 0; i < 4; i++){
            if (learned[i])
                delete learned[i];
            learned[i] = other.learned[i];
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
	bool    check;
    for (int i = 0; i < 4; i++){
        check = false;
        if (learned[i]){
            if (i > 0){
                for (int j = 0; j < i; j++)
                    if (learned[i] == learned[j]){
                        check = true;
                        break ;
                    }
            }
            if (check)
                continue;
            delete learned[i];
        }
    }
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++){
        if (!learned[i]){
            learned[i] = m;
            return ;
        }
    }
    cout << "Memory full" << endl;
}

AMateria * MateriaSource::createMateria(const string& type)
{
	size_t i;
	for (i = 0; i < 4; i++){
		if (learned[i] && learned[i]->getType() == type)
			break ;
	}
	if (i == 4){
		std::cout << type << " is unknown." << std::endl;
		return NULL;
	}
	return (learned[i]->clone());
}