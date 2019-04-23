/*
 * Herbivore - deriving from Organism
 */

#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

#include "Organism.h"
#include "HerbivoreAction.h"
#include "HerbivoreActionFactory.h"



class Herbivore final : public Organism
{
public:
	Herbivore() = delete;
	Herbivore(const Organism&) = delete;
	Herbivore(Organism&&) = delete;
	Herbivore(std::shared_ptr<Genotype> genes, const Vector& position, std::weak_ptr<Simulation> simulation);

	virtual void updateAction();			//after being notified, it uses ActionFactory to update currentAction_
	virtual void update();					//flow of the information upside down

	//TODO what about destructors?
};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
