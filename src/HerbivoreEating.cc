/**
 * Herbivore's (concrete) Action - eating
 */

#include <include/ALife/HerbivoreEating.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/MapTile.h>

HerbivoreEating::HerbivoreEating(Herbivore *const owner, Simulation *const simulation) :
	HerbivoreAction(owner, simulation)
{}

void HerbivoreEating::act() //TODO
{
	//Organism is hungry, it needs to find the nearest food
	MapTile* grass = simulation_->getNearestGrass(concreteOwner_);
	
	if(!grass) return;

	Vector toGrass = grass->getPosition() - owner_->getPosition();

	auto speed = owner_->getIndividualSpeedValueAfter(0);
	auto direction = toGrass.getUnitVector();
	auto intendedVelocity = direction * speed;

	if(toGrass.getLength() < grass->getSize()*0.5)
	{
		concreteOwner_->eatIt(grass);
	}
	else
	{
		if(intendedVelocity.getLength() > toGrass.getLength())
		{
			intendedVelocity = toGrass;
		} 
		owner_->setVelocity(intendedVelocity);
	}
}