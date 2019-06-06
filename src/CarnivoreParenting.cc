
#include <include/ALife/CarnivoreParenting.h>
#include <include/ALife/Simulation.h>
#include <include/ALife/RandomGenerator.h>
#include <include/ALife/Carnivore.h>

CarnivoreParenting::CarnivoreParenting(Carnivore *const owner, Simulation *const simulation, Carnivore* partner):
    CarnivoreAction(owner, simulation),
    partner_(partner)
{
    //Choose random point on the left side of the map
    double locationX = -RandomGenerator::getInstance()->getSampleUniform();
    
    //Rescale from [0.0, 1.0] to [-1.0, 1.0]
    double locationY = 2.0 * (RandomGenerator::getInstance()->getSampleUniform() - 0.5);

    birthLocation_ = Vector(locationX, locationY);
}

void CarnivoreParenting::act()
{
    Vector organismPosition = owner_->getPosition();
    Vector partnerPosition = partner_->getPosition();

    Vector toBirthLocation = Vector::getShortestVectorBetweenPositions(organismPosition, 
                                                                       birthLocation_);

    constexpr double EPS = 0.00001;

    //Check if organism reached the destination
    if(toBirthLocation.getLength() < EPS)
    {
        //...and if his partner have done it too
        Vector toPartner = Vector::getShortestVectorBetweenPositions(organismPosition, 
                                                                     partnerPosition);
        if(toPartner.getLength() < EPS)
        {
            //Give birth to a child!
            //And unpair with partner
            simulation_->produceBabies(concreteOwner_, partner_);
            partner_->finishParenting();
            owner_->finishParenting();
        }
        //in other case, wait for the partner to arrive
    }
    else
    {
        double speed = concreteOwner_->getIndividualSpeedValueAfter(0);
        Vector organismVelocity = toBirthLocation.getUnitVector() * speed;

        //Prevent from overshooting
        if(organismVelocity.getLength() > toBirthLocation.getLength())
        {
            organismVelocity = toBirthLocation;
        }

        owner_->setVelocity(organismVelocity);
    }
}