/**
 * Needs represents all organism's physical and psychological needs. It implicitly impacts organism's actions.
 */

#include <include/ALife/Needs.h>
#include <include/ALife/Organism.h>


Needs::Needs(Organism* const owner) :
	owner_(owner),
	leadingDesire_(LeadingDesire::EATING),

	hunger_(5.0),
	tiredness_(0.0),
	loneliness_(0.0)
{}

void Needs::decreaseHungerBy(float value)
{
	hunger_ -= value;
	if(hunger_ < 0.0)
		hunger_ = 0.0;
}

void Needs::increaseHungerBy(float value)
{
	hunger_ += value;
	if(hunger_ < 10.0)
		hunger_ = 10.0;
}

void Needs::decreaseLonelinessBy(float value)
{
	loneliness_ -= value;
	if(loneliness_ < 0.0)
		loneliness_ = 0.0;
}

void Needs::increaseLonelinessBy(float value)
{
	loneliness_ += value;
	if(loneliness_ > 10.0)
		loneliness_ = 10.0;
}

void Needs::decreaseTirednessBy(float value)
{
	tiredness_ -= value;
	if(tiredness_ < 0.0)
		tiredness_ = 0.0;
}

void Needs::increaseTirednessBy(float value)
{
	tiredness_ += value;
	if(tiredness_ > 10.0)
		tiredness_ = 10.0;
}

void Needs::update()
{
	LeadingDesire updatedDesire;

	if(hunger_ >= tiredness_ and hunger_ >= loneliness_)
		updatedDesire = LeadingDesire::EATING;

	else if(tiredness_ >= hunger_ and tiredness_ >= loneliness_)
		updatedDesire = LeadingDesire::SLEEPING;

	else //if(loneliness_ >= hunger_ and loneliness_ >= tiredness_)
		updatedDesire = LeadingDesire::REPRODUCTION;

	if(updatedDesire != leadingDesire_)
	{
		leadingDesire_ = updatedDesire;
		notify();
	}

}

void Needs::notify() const
{
	owner_->updateAction();
}

LeadingDesire Needs::getLeadingDesire() const
{
	return leadingDesire_;
}
