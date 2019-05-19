/**
 * Concrete species of an organism (derives from it)
 */

#ifndef ARTIFICIAL_LIFE_CARNIVORE_H
#define ARTIFICIAL_LIFE_CARNIVORE_H

class Simulation;

#include "Organism.h"


class Carnivore : public Organism
{
public:
	Carnivore() = delete;
	Carnivore(const Organism&) = delete;
	Carnivore(Organism&&) = delete;
	Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);

	virtual void updateAction();			//after being notified, it uses ActionFactory to update currentAction_
	virtual void update();					//flow of the information upside down
	virtual void eatIt(const Vector&);

};


#endif //ARTIFICIAL_LIFE_CARNIVORE_H
