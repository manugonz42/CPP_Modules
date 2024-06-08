#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
	    AMateria	*learned[4];
    public:
    	MateriaSource();
    	MateriaSource(MateriaSource const &);
    	MateriaSource &operator=(MateriaSource const &);
    	~MateriaSource();

    	void		learnMateria(AMateria*);
    	AMateria	*createMateria(std::string const & type);

};