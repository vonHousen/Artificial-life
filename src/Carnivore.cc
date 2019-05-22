/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Carnivore.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/CarnivoreActionFactory.h>
#include <include/ALife/CarnivoreHunting.h>
#include <include/ALife/Simulation.h>

Carnivore::Carnivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
		Organism(std::move(genes), position, simulation)
{
	this->updateAction();
}

void Carnivore::updateAction()
{
	suggestedAction_ = needs_->getLeadingDesire();

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

void Carnivore::eatPray(Herbivore* pray)
{
	if(pray)
	{
		pray->setHealth(0.0);
		this->needs_->decreaseHungerBy(5.0);
		this->needs_->increaseLonelinessBy(2.0);
	}

}

double Carnivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	const double TIREDNESS_FACTOR = genes_-> getTirednessFactor();
	const double BASIC_SPEED = genes_-> getBasicSpeed();

	const int INTENDED_RUN_DURATION = 1000 * TIREDNESS_FACTOR;
	constexpr double PSEUDO_NORMALISATION_FACTOR = 0.000002;
	const double speedDeviation =
			static_cast<double>(INTENDED_RUN_DURATION - static_cast<int>(time)) * PSEUDO_NORMALISATION_FACTOR;

	//if run takes too long, organism is tired, but is not stopping!
	if(speedDeviation < -0.5*speedDeviation)
		return 0.5* BASIC_SPEED;
	else
		return speedDeviation + BASIC_SPEED;
}

void Carnivore::update()
{
	this->newIteration();

	if(currentAction_)
		currentAction_->act();

	this->move();
	this->checkAge();
}

