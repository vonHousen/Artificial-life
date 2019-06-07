/**
 * Needs represents all organism's physical and psychological needs. It implicitly impacts organism's actions.
 */

#include <include/ALife/Needs.h>
#include <include/ALife/Organism.h>
#include <algorithm>


Needs::Needs(Organism* const owner, LeadingDesire born_desire) :
	owner_(owner),
	leadingDesire_(born_desire),
	hunger_(0.0),
	tiredness_(0.0),
	loneliness_(0.0)
{
	if(born_desire == LeadingDesire::EATING)
		hunger_ = 5.0;

	else if (born_desire == LeadingDesire::REPRODUCTION)
		loneliness_ = 5.0;

	else //if (born_desire == LeadingDesire::SLEEPING)
		tiredness_ = 5.0;
}

void Needs::decreaseHungerBy(float value)
{
	hunger_ -= value;
	if(hunger_ < 0.0)
		hunger_ = 0.0;
}

void Needs::increaseHungerBy(float value)
{
	hunger_ += value;
	if(hunger_ > 10.0)
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

float Needs::getHunger() const
{
	return hunger_;
}

float Needs::getTiredness() const
{
	return tiredness_;
}

float Needs::getLoneliness() const
{
	return loneliness_;
}

void Needs::update()
{
	LeadingDesire updatedDesire;

	// periodically increase needs' values
	constexpr int NORMALIZATION_FACTOR = 200;
	const unsigned int timeAlive = owner_->getTimeAlive();
	const unsigned int interval = static_cast<int>(owner_->getStamina() * NORMALIZATION_FACTOR);
	const bool isTimeForHigherNeeds = timeAlive % interval == 0;
	const bool isTimeForIllness = timeAlive % (interval/2)== 0;

	if(isTimeForHigherNeeds)
	{
		increaseLonelinessBy(1);
		increaseTirednessBy(1);
		increaseHungerBy(1);
	}

	// periodically decrease Health if needs are too neglected
	if (isTimeForIllness and (tiredness_ + loneliness_ + hunger_) > 25)
		owner_->decreaseHealthByValue(2.0);
	else if(isTimeForIllness and (tiredness_ > 7.5 or loneliness_ > 7.5 or hunger_ > 7.5))
		owner_->decreaseHealthByValue(1.0);


	// determine the greatest need and set leadingDesire
	if(std::max({loneliness_, hunger_, tiredness_}) == tiredness_)
		updatedDesire = LeadingDesire::SLEEPING;

	else if(std::max({loneliness_, hunger_, tiredness_}) == loneliness_)
		updatedDesire = LeadingDesire::REPRODUCTION;

	else //if(std::max({loneliness_, hunger_, tiredness_}) == hunger_)
		updatedDesire = LeadingDesire::EATING;

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
