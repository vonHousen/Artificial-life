/*
 * Needs TODO
 */

#ifndef ARTIFICIAL_LIFE_NEEDS_H
#define ARTIFICIAL_LIFE_NEEDS_H

#include "Organism.h"
#include <memory>

class Needs
{
public:
	Needs(std::shared_ptr<Organism> owner): owner_(owner) {}

	void update();
	void notify() const //INFO (KP): will notify owner when leading desire will change
	{
		//auto bhv = ...
		//owner_.changeBehavior(bhv);
	}
private:
	enum class LeadingDesire { EATING, REPRODUCTION, SLEEPING };
	std::shared_ptr<Organism> owner_;
	float hunger_;
	float fatigue_;//NOTE (KP): how should we call it?
	float reproductionDesire_;//NOTE (KP): hmm...
	LeadingDesire leadingDesire_;
};


#endif //ARTIFICIAL_LIFE_NEEDS_H
