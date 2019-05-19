/*
 * Organism - abstract (super) class for both species
 */

#ifndef ARTIFICIAL_LIFE_ORGANISM_H
#define ARTIFICIAL_LIFE_ORGANISM_H

class Simulation;

#include <memory>
#include "Action.h"
#include "Needs.h"
#include "Genotype.h"
#include "Vector.h"
#include "LeadingDesire.h"


class Organism
{
public:
	Organism() = delete;
	Organism(const Organism&) = delete;
	Organism& operator=(const Organism&) = delete;
	Organism(Organism&&) = delete;
	Organism& operator=(Organism&&) = delete;
  	Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation);
  	virtual ~Organism() = default;

	virtual void updateAction() = 0;			//after being notified, it uses ActionFactory to update currentAction_
	virtual void update() = 0;					//flow of the information upside down
	virtual void eatIt(const Vector&) = 0;		//polymorphism decides whether to eat grass or another organism

	void setAcceleration(const Vector&);
	void setVelocity(const Vector&);
	void setHealth(float);
	void setSimulation(Simulation* const);

	bool isAlive() const;
	const Vector& getPosition() const;
	static double getRadius();
	LeadingDesire getSuggestedAction() const;

protected:
	//basic traits of the organism
	float 	health_;
	int 	timeAlive_;
	Vector 	position_;
	Vector 	velocity_;
	Vector 	acceleration_;
	static double radius_;

	//complex traits of the organism, ready for polymorphism
	std::unique_ptr<Genotype> 		genes_;
	std::unique_ptr<Needs> 			needs_;
	std::unique_ptr<Action> 		currentAction_;

	//pointer for simulation the organism takes part in
	Simulation*						simulation_;

	LeadingDesire suggestedAction_;


};




#endif //ARTIFICIAL_LIFE_ORGANISM_H
