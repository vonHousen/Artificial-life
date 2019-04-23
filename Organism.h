/*
 * Organism - abstract (super) class for both species
 */

#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

#include "Vector.h"
#include "Simulation.h"
#include "Genotype.h"
#include "Action.h"
#include "Needs.h"

class Needs;


class Organism
{
public:
	Organism() = delete;
	Organism(const Organism&) = delete;
	Organism(Organism&&) = delete;
	Organism(std::shared_ptr<Genotype> genes, const Vector& position, std::weak_ptr<Simulation> simulation);

	void updateAction();						//after being notified, it uses ActionFactory to update currentAction_
	void update();								//flow of the information upside down

	bool isAlive() const;

protected:
	//basic traits of the organism
	float 	health_;
	int 	timeAlive_;
	Vector 	position_;
	Vector 	velocity_;
	Vector 	acceleration_;

	//complex traits of the organism, ready for polymorphism
	std::shared_ptr<Genotype> 		genes_;
	std::shared_ptr<Needs> 			needs_;
	std::shared_ptr<Action> 		currentAction_;

	//pointer for simulation the organism takes part in
	std::weak_ptr<Simulation> 	simulation_;


};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
