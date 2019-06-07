/**
 * Abstract (base) class for both species
 */

#include <include/ALife/Organism.h>

double Organism::radius_ = 0.015;

Organism::Organism(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation, LeadingDesire desire) :
	health_			(10.0),
	timeAlive_		(1),
	position_		(position),
	velocity_		(Vector()),
	acceleration_	(Vector()),

	genes_ 			(std::move(genes)),
	currentAction_ 	(nullptr),
	simulation_ 	(simulation),
	suggestedAction_(desire),
	needs_			(std::make_unique<Needs>(this, desire))
{}

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

void Organism::decreaseHealthByValue(float value)
{
	health_ -= value;

	if(health_ < 0.0)
		health_ = 0.0;
}

void Organism::setSimulation(Simulation* const simulation)
{
	simulation_ = simulation;
}

LeadingDesire Organism::getSuggestedAction() const
{
	return suggestedAction_;
}

void Organism::move()
{
	// Move
	// deltaS = v*dt + 1/2*a*dt^2
	// deltaV = a*dt
	// where dt = 1
	position_ += velocity_ + acceleration_*0.5;
	velocity_ += acceleration_;
}

void Organism::newIteration()
{
	++timeAlive_;
	needs_->update();

	velocity_ = Vector();
	acceleration_ = Vector();
}

void Organism::checkAge()
{
	constexpr unsigned long int BASIC_LIFESPAN = 10000;
	constexpr unsigned long int NORMALIZATION_FACTOR = 2000;
	const unsigned long int PREDICTED_LIFESPAN = BASIC_LIFESPAN + genes_->getLifespan() * NORMALIZATION_FACTOR;

	if(timeAlive_ >= PREDICTED_LIFESPAN)
		this->decreaseHealthByValue(10.0);
}


void Organism::sleepWell()
{
	needs_->decreaseTirednessBy(10.0);
	needs_->increaseHungerBy(1.0);
	needs_->update();
}

void Organism::finishParenting()
{
	needs_->decreaseLonelinessBy(10);
	needs_->increaseTirednessBy(1);
	needs_->update();
}
