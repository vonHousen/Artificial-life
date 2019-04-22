/*
 * Needs TODO
 */

#include "Needs.h"

Needs::Needs(std::weak_ptr<Organism> owner) :
	owner_(owner),
	leadingDesire_(LeadingDesire::EATING),

	hunger_(5.0),
	tiredness_(5.0),
	loneliness_(5.0)
{}
