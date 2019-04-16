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
	void updateBehaviour(); 						//INFO (KP): called by needs

	bool isAlive() const;

private:
	//basic traits of the organism
	float health_;
	float timeAlive_;
	Vector position_;
	Vector velocity_;
	Vector acceleration_;

	//complex traits of the organism
	Genotype genes_;
	Needs needs_;
	Behaviour behaviour_;

	//pointer for simulation the organism takes part in
	std::shared_ptr<Simulation> simulation_;

	//KP: will call bhv.act(this, simulation)
	void update(float dt);
};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
