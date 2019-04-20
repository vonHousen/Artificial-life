/*
 * Organism TODO
 */

#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

#include "Vector.h"
#include "Simulation.h"
#include "Genotype.h"
#include "Action.h"
#include "Needs.h"

class Needs;
class Behaviour;

class Organism
{
public:
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
	std::shared_ptr<Needs> 			needs_;			//TODO eliminate shared_ptr here
	std::shared_ptr<Action> 		currentAction_;

	//pointer for simulation the organism takes part in
	std::shared_ptr<Simulation> 	simulation_;	//TODO eliminate shared_ptr here


};


#endif //ARTIFICIAL_LIFE_ORGANISM_H
