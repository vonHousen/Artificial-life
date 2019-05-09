/*
 * OrganismView TODO
 */

#ifndef ARTIFICIAL_LIFE_ORGANISMVIEW_H
#define ARTIFICIAL_LIFE_ORGANISMVIEW_H

class Organism;

#include <QtWidgets>

class OrganismView : public QGraphicsEllipseItem
{
public:
    OrganismView(Organism* const model);

    void update();

private:
    Organism* const model_;
};

#endif //ARTIFICIAL_LIFE_ORGANISMVIEW_H