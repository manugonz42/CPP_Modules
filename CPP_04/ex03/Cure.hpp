#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{
    public:
    	Cure();
    	Cure(Cure const &);
    	Cure &operator=(Cure const &);
    	~Cure();
    
    	AMateria* clone() const;
};