/*
 * Needs TODO
 */

#ifndef ARTIFICIAL_LIFE_NEEDS_H
#define ARTIFICIAL_LIFE_NEEDS_H

#include <memory>

class Organism;

class Needs
{
public:
	Needs(std::shared_ptr<Organism> owner): owner_(owner) {}

	void update();
	void notify() const; //INFO (KP): will notify owner when leading desire will change
private:
	enum class LeadingDesire { EATING, REPRODUCTION, SLEEPING };
	std::shared_ptr<Organism> owner_;
	float hunger_;
	float tiredness_;
	float loneliness_;
	LeadingDesire leadingDesire_;
};


#endif //ARTIFICIAL_LIFE_NEEDS_H
