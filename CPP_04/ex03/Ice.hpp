#pragma once

#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice(Ice const &);
	Ice &operator=(Ice const &);
	~Ice();

	AMateria* clone() const;
};