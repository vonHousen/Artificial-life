/*
 * Carnivore - deriving from organism
 */

#ifndef ARTIFICIAL_LIFE_CARNIVORE_H
#define ARTIFICIAL_LIFE_CARNIVORE_H

#include "Organism.h"
#include "CarnivoreAction.h"
#include "CarnivoreActionFactory.h"


class Carnivore : public Organism
{
public:
	Carnivore() = delete;
	Carnivore(const Organism&) = delete;
	Carnivore(Organism&&) = delete;
	Carnivore(std::unique_ptr<Genotype> genes, const Vector &position, Simulation* const simulation);

	virtual void updateAction();			//after being notified, it uses ActionFactory to update currentAction_
	virtual void update();					//flow of the information upside down

};


#endif //ARTIFICIAL_LIFE_CARNIVORE_H
