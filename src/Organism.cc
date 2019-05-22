/**
 * Abstract (base) class for both species
 */

#include <include/ALife/Organism.h>

double Organism::radius_ = 0.015;

Organism::Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	health_			(10.0),
	timeAlive_		(0),
	position_		(position),
	velocity_		(Vector()),
	acceleration_	(Vector()),

	genes_ 			(std::move(genes)),
	needs_			(std::make_unique<Needs>(this)),
	currentAction_ 	(nullptr),
	simulation_ 	(simulation),
	suggestedAction_(LeadingDesire::EATING)
{}


void Organism::update()
{
	needs_->update();

	velocity_ = Vector();
	acceleration_ = Vector();

	if(currentAction_)
		currentAction_->act();

	// Move
	// deltaS = v*dt + 1/2*a*dt^2
	// deltaV = a*dt
	// where dt = 1
	position_ += velocity_ + acceleration_*0.5; 
	velocity_ += acceleration_;
}

bool Organism::isAlive() const
{
	return health_ > 0.0;
}

const Vector& Organism::getPosition() const
{
	return position_;
}

float Organism::getHealth() const
{
	return health_;
}

unsigned int Organism::getTimeAlive() const
{
	return timeAlive_;
}

float Organism::getAlertness() const
{
	return genes_->getAlertness();
}

float Organism::getSightRange() const
{
	return genes_->getSightRange();
}

float Organism::getStamina() const
{
	return genes_->getStamina();
}

float Organism::getSpeed() const
{
	return genes_->getSpeed();
}

float Organism::getLifespan() const
{
	return genes_->getLifespan();
}

float Organism::getHunger() const
{
	return needs_->getHunger();
}

float Organism::getTiredness() const
{
	return needs_->getTiredness();
}

float Organism::getLoneliness() const
{
	return needs_->getLoneliness();
}

void Organism::setAcceleration(const Vector& acceleration)
{
	acceleration_ = acceleration;
}

void Organism::setVelocity(const Vector& velocity)
{
	velocity_ = velocity;
}

double Organism::getRadius()
{
	return radius_;
}

void Organism::setHealth(float health)
{
	health_ = health;
}

void Organism::setSimulation(Simulation* const simulation)
{
	simulation_ = simulation;
}

LeadingDesire Organism::getSuggestedAction() const
{
	return suggestedAction_;
}
