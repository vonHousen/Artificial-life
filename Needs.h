/*
 * Needs TODO
 */

#ifndef ARTIFICIAL_LIFE_NEEDS_H
#define ARTIFICIAL_LIFE_NEEDS_H

#include <memory>

class Organism;


class Needs final
{
public:
	explicit Needs(std::weak_ptr<Organism> owner);

	void update();

private:
	enum class LeadingDesire { EATING, REPRODUCTION, SLEEPING };
	LeadingDesire leadingDesire_;
	std::weak_ptr<Organism> owner_;

	float hunger_;
	float tiredness_;
	float loneliness_;

	void notify() const; 							//notify owner when leading desire changes

};


#endif //ARTIFICIAL_LIFE_NEEDS_H
