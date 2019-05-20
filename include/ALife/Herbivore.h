/**
 * Concrete species of an organism (derives from it)
 */

#ifndef ARTIFICIAL_LIFE_HERBIVORE_H
#define ARTIFICIAL_LIFE_HERBIVORE_H

class Simulation;

#include "Organism.h"


class Herbivore final : public Organism
{
public:
	Herbivore() = delete;
	Herbivore(const Organism&) = delete;
	Herbivore(Organism&&) = delete;
	Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);

	virtual void updateAction();			//after being notified, it uses ActionFactory to update currentAction_
};


#endif //ARTIFICIAL_LIFE_HERBIVORE_H
