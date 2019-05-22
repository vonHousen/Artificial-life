/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Herbivore.h>
#include <include/ALife/Carnivore.h>
#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Action.h>


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
	{}

void Herbivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();

	switch(suggestedAction_)
	{
		case LeadingDesire::EATING:
			currentAction_ = nullptr;
			break;

		case LeadingDesire::REPRODUCTION:
			currentAction_ = nullptr;
			break;

		default:
			break;
	}

}

void Herbivore::eatIt(const Vector &) // TODO
{

}

double Herbivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	return genes_->getBasicSpeed();		// TODO
}

void Herbivore::runAwayFrom(Carnivore* danger)
{
	if(not danger)
		return;

	auto velocity = this->getIndividualSpeedValueAfter(0);


	auto direction = (danger->getPosition() - this->getPosition()).getUnitVector();
	auto intendedVelocity = direction * velocity;

	this->setVelocity(intendedVelocity);
}

void Herbivore::update()
{
	++timeAlive_;
	needs_->update();

	velocity_ = Vector();
	acceleration_ = Vector();

	// determine the greatest danger
	Carnivore* danger = simulation_->getNearestPredator(this, this->getSightRange());

	// do actions only if not chased by predator
	if(danger)
	{
		this->runAwayFrom(danger);

	} else
	{
		if (currentAction_)
			currentAction_->act();
	}

	// Move
	// deltaS = v*dt + 1/2*a*dt^2
	// deltaV = a*dt
	// where dt = 1
	position_ += velocity_ + acceleration_*0.5;
	velocity_ += acceleration_;
}