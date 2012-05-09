#ifndef DOTTEDLINEBAH_H
#define DOTTEDLINEBAH_H
#include "linebody.h"

class dottedlinebah : public lineBody
{
public:
    //Constructors
    dottedlinebah(Icon *, Icon *, QGraphicsItem *, QGraphicsScene *);
    dottedlinebah(Icon *, Icon *, int,  int, QGraphicsItem *, QGraphicsScene *);
    dottedlinebah(int id_start, int id_end);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // DOTTEDLINEBAH_H
