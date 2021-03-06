
#ifndef ARTIFICIAL_LIFE_NEEDS_H
#define ARTIFICIAL_LIFE_NEEDS_H

#include "LeadingDesire.h"

class Organism;

/**
 * Represents all Organism's physical and psychological Needs - it implicitly impacts Organism's Actions.
 */

class Needs
{
public:

	Needs(const Needs&) = delete;					///< Deleted copying constructor.
	Needs& operator=(const Needs&) = delete;		///< Deleted assignment operator
	Needs(Needs&&) = delete;						///< Deleted moving constructor.
	Needs& operator=(Needs&&) = delete;				///< Deleted moving assignment operator.

	/**
	 * A one parameter constructor.
	 * @param owner - Organism "owning" this Needs.
	 * @param born_desire - desire Organism is born with.
	 */
	Needs(Organism* owner, LeadingDesire born_desire);

	void update();									///< flow of the information upside down.

	void decreaseHungerBy(float value);				///< Organism is less hungry after eating something.
	void increaseHungerBy(float value);				///< Organism is hungry after sleeping.
	void decreaseLonelinessBy(float value);			///< Organism is less lonely after reproduction.
	void increaseLonelinessBy(float value);			///< Organism is feeling lonely after eating something.
	void decreaseTirednessBy(float value);			///< Organism is less tired after sleeping.
	void increaseTirednessBy(float value);			///< Organism is tired after reproduction.

	float getHunger() const;						///< Getter for value representing how hungry the organism is
	float getTiredness() const;						///< Getter for value representing how tired the organism is
	float getLoneliness() const;					///< Getter for value representing how lonely the organism is

	/**
	 * Getter for LeadingDesire
	 * @return LeadingDesire
	 */
	LeadingDesire getLeadingDesire() const;

private:

	LeadingDesire leadingDesire_;					///< The most desired Action by particular Organism.
	Organism* owner_;								///< Organism "owning" this Needs.

	float hunger_;									///< A need for eating, value in range [0; 10].
	float tiredness_;								///< A need for sleeping, value in range [0; 10].
	float loneliness_;								///< A need for reproduction, value in range [0; 10].

	void notify() const; 							///< Notifies owner when leading desire is changed.

};


#endif //ARTIFICIAL_LIFE_NEEDS_H
