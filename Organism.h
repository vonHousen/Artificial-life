/*
 * Organism TODO
 */

#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

#include "Vector.h"
#include "Simulation.h"
#include "Genotype.h"
#include "Behaviour.h"
#include "Needs.h"

class Needs;
class Behaviour;

class Organism
{
public:
	void update(float dt); //INFO (KP): will call bhv.act(this, simulation)
	void changeBehavior(const Behaviour&); //INFO (KP): called by needs

	bool isAlive() const;
private:
	float health_;
	float timeAlive_;
	Genotype genes_;
	Vector position_;
	Vector velocity_;
	Vector acceleration_;
	Needs needs_;
	Behaviour behavior_;
	std::shared_ptr<Simulation> simulation_;
};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
