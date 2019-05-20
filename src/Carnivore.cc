/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Carnivore.h>

#include "Carnivore.h"
#include "CarnivoreActionFactory.h"
#include "CarnivoreHunting.h"
#include "Simulation.h"

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
		Organism(std::move(genes), position, simulation)
{
	this->updateAction();
}

void Carnivore::update()
{
	needs_->update();

	acceleration_ = Vector();
	velocity_ = Vector();

	if(currentAction_)
		currentAction_->act();

	// Move
	// deltaS = v*dt + 1/2*a*dt^2
	// deltaV = a*dt
	// where dt = 1
	position_ += velocity_ + acceleration_*0.5; 
	velocity_ += acceleration_;
}

void Carnivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();

	// TODO check first if there are no other factors that may change suggestedAction

	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = std::make_unique<CarnivoreHunting>(
					CarnivoreActionFactory::getInstance().produceEatingAction(this, simulation_)
					);
			break;

		case LeadingDesire::REPRODUCTION:
			currentAction_ = nullptr;
			break;

		default:
			break;
	}
}

void Carnivore::eatIt(const Vector& position)
{
	auto food = simulation_->getOrganismAt(position);

	if(food)
	{
		food->setHealth(0.0);
		this->needs_->decreaseHungerBy(5.0);
		this->needs_->increaseLonelinessBy(2.0);
	}

}

double Carnivore::getIndividualSpeedValueAfter(unsigned int time) const
{

	double tirednessFactor = genes_-> getTirednessFactor();
	double basicSpeed = genes_-> getBasicSpeed();
	int runDuration = 1000 * tirednessFactor;
	double pseudoNormalisationFactor = 0.000001;

	//if run takes too long
	if(time > 2 * runDuration)
		return basicSpeed - runDuration * pseudoNormalisationFactor;
	else
	{
		double speedDeviation = static_cast<double>(runDuration - static_cast<int>(time)) * pseudoNormalisationFactor;
		return speedDeviation + basicSpeed;
	}
}
