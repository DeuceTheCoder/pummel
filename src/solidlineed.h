#ifndef SOLIDLINEED_H
#define SOLIDLINEED_H
#include "linebody.h"

class solidlineed : public lineBody
{
public:
    solidlineed(Icon *, Icon *, QGraphicsItem *, QGraphicsScene *);
private:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // SOLIDLINEED_H
