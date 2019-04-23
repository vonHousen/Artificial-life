/*
 * Needs represents all organism's physical and psychological needs. It implicitly impacts organism's actions.
 */

#include "Needs.h"

Needs::Needs(std::weak_ptr<Organism> owner) :
	owner_(owner),
	leadingDesire_(LeadingDesire::EATING),

	hunger_(5.0),
	tiredness_(0.0),
	loneliness_(0.0)
{}
