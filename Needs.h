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
	explicit Needs(std::shared_ptr<Organism> owner): owner_(owner) {}

	void update();

private:
	enum class LeadingDesire { EATING, REPRODUCTION, SLEEPING };
	LeadingDesire leadingDesire_;
	std::shared_ptr<Organism> owner_;				//TODO eliminate shared_ptr here

	float hunger_;
	float tiredness_;
	float loneliness_;

	void notify() const; 							//notify owner when leading desire changes

};


#endif //ARTIFICIAL_LIFE_NEEDS_H
