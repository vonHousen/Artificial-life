/**
 * Herbivore's (concrete) Action - eating
 */

#include <include/ALife/HerbivoreEating.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Herbivore.h>
#include <include/ALife/MapTile.h>

HerbivoreEating::HerbivoreEating(Herbivore *const owner, Simulation *const simulation) :
	HerbivoreAction(owner, simulation),
	eatenTile_(nullptr)
{}

HerbivoreEating::~HerbivoreEating()
{
	if(eatenTile_) eatenTile_->setEater(nullptr);
}

void HerbivoreEating::act()
{
	//Find nearest, grassy map tile
	MapTile* grass = simulation_->getNearestGrass(concreteOwner_);
	if(!grass) return;

	//If organism left previously eaten grass, mark it as free so that
	//other organisms can eat it
	if(eatenTile_ && eatenTile_ != grass)
	{
		eatenTile_->setEater(nullptr);
	}

	Vector toGrass = grass->getPosition() - owner_->getPosition();

	auto speed = owner_->getIndividualSpeedValueAfter(0);
	auto direction = toGrass.getUnitVector();
	auto intendedVelocity = direction * speed;

	if(toGrass.getLength() < 0.00001)
	{
		concreteOwner_->eatIt(grass);
		eatenTile_ = grass;
	}
	else
	{
		//Prevents from passing over grass
		if(intendedVelocity.getLength() > toGrass.getLength())
		{
			intendedVelocity = toGrass;
		} 
		owner_->setVelocity(intendedVelocity);
	}
}