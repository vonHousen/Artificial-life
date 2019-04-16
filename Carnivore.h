/*
 * Carnivore - deriving from organism
 */

#ifndef ARTIFICIAL_LIFE_CARNIVORE_H
#define ARTIFICIAL_LIFE_CARNIVORE_H

#include "Organism.h"
#include "CarnivoreBehaviour.h"


class Carnivore : public Organism
{
public:
	Carnivore() {
		behaviour_ = std::shared_ptr<Behaviour>(new CarnivoreBehaviour());	//TODO get rid of shared_ptr
	}
};


#endif //ARTIFICIAL_LIFE_CARNIVORE_H
