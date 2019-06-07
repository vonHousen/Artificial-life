/**
 * Concrete species of an organism (derives from it)
 */

#include <include/ALife/Herbivore.h>
#include <include/ALife/HerbivoreActionFactory.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/Action.h>
#include <include/ALife/StatisticsVisitor.h>


Herbivore::Herbivore(std::unique_ptr<Genotype> genes, const Vector& position, Simulation* const simulation) :
	Organism(std::move(genes), position, simulation)
{}

void Herbivore::accept(StatisticsVisitor& visitor) const
{
	visitor.visit(*this);
}

void Herbivore::updateAction() // TODO
{

}

void Herbivore::eatIt(const Vector &) // TODO
{

}

double Herbivore::getIndividualSpeedValueAfter(unsigned int time) const
{
	return genes_->getBasicSpeed();		// TODO
}

