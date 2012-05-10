/* icon.cpp -contains the functions to store default properties in the shape structs
               and contains the creation function for each shape
               Made by Theora Rice
  */
#include "icon.h"
#include <QPolygonF>
#include <QtGui>

//#include <QPointF>

int Icon::m_next_id = 1;

Icon::Icon(QPointF location, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_width = 100;
    m_height = 100;
    m_state = 0;
    m_xPos = location.x();
    m_yPos = location.y();

    m_labelBox = new QGraphicsTextItem;
    m_labelBox->setPos(this->pos());
    m_id = m_next_id;
    m_next_id++;

    // selection boxes configuration
    for(int i = 0; i < 4; i++)
    {
        m_markers[i] = new MarkerBox();
        m_markers[i]->setParentItem(this);
        m_markers[i]->setVisible(false);
        m_markers[i]->setId(i);
    }
}

Icon::~Icon()
{
    //delete marker boxes
    for (int i = 0; i<4; i++)
    {
        delete m_markers[i];
    }

    delete m_labelBox;
}

int Icon::getWidth()
{
    return m_width;
}

int Icon::getHeight()
{
    return m_height;
}

QString Icon::getLabel()
{
    return m_label;
}

void Icon::setSize(int newWidth, int newHeight)
{
    m_width = newWidth;
    m_height = newHeight;
    update();
}

QString Icon::reportShapetype()
{
    return m_shapetype;
}

void Icon::setShapetype(QString shapename)
{
    m_shapetype = shapename;
}

int Icon::getID()
{
    return m_id;
}

void Icon::paintMarkerBoxes()
{
    if(this->isSelected())
    {
        // properly sets the marker boxes around selected objects
        m_markers[0]->setVisible(true);
        m_markers[1]->setVisible(true);
        m_markers[2]->setVisible(true);
        m_markers[3]->setVisible(true);
        // this next section grabs the scenePos of the object and offsets its markerboxes 3 pixels away from the corners of the objects
        // boundingRect
        QPointF pos = this->scenePos(); // sets position to the upper left pixel
        pos.rx() = -8;
        pos.ry() = -8;
        m_markers[0]->setPos(pos); // upper left markerbox

        pos = this->scenePos();
        pos.rx() = m_width+3;
        pos.ry() = -8;
        m_markers[1]->setPos(pos); // upper right

        pos = this->scenePos();
        pos.rx() = -8;
        pos.ry() = m_height+3;
        m_markers[2]->setPos(pos); // lower left

        pos = this->scenePos();
        pos.rx() = m_width+3;
        pos.ry() = m_height+3;
        m_markers[3]->setPos(pos); // lower right
    }
    else
    {
        // if not selected, make the boxes invisible
        m_markers[0]->setVisible(false);
        m_markers[1]->setVisible(false);
        m_markers[2]->setVisible(false);
        m_markers[3]->setVisible(false);
    }
    update();
}

void Icon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_state = 2;
    //not needed.  This causes the icon to become "sticky"
//    this->grabMouse();  // icon will take all mouse actions
}

void Icon::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Centers the cursor while dragging, as opposed to dragging by the top-left most pixel
    QPointF pos = event->scenePos();
    pos.rx() -= 0.5 * m_width;
    pos.ry() -= 0.5 * m_height;
    update();
    this->setPos(pos);
    this->set_Pos((int)pos.rx(), (int)pos.ry());
}

void Icon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /*
     * This resets the object's coordinates to the cursor's coordinates when the
     * mouse is released, as opposed to creating a new object and then deleting the old one.
     * Also puts opacity back to normal.
     */

    // Centers the cursor while dragging, as opposed to dragging by the top-left most pixel
    this->ungrabMouse();  // release mouse back to DragScene
}

QPolygonF Icon::getType()
{
    return m_bound;
}

void Icon::setPolygon()
{
    m_bound = QPolygonF(boundingRect());
}

int Icon::getState()
{
    return m_state;
}

MarkerBox* Icon::getMarkerBox(int i)
{
    return m_markers[i];
}

void Icon::setState(int x)
{
    m_state = x;
}

void Icon::setMarkers(MarkerBox* a, MarkerBox* b, MarkerBox* c, MarkerBox* d)
{
    m_markers[0] = a;
    m_markers[1] = b;
    m_markers[2] = c;
    m_markers[3] = d;

}

QString Icon::get_all()
{
    return m_label;
}

QStringList Icon::split_all(QString value)
{
    QString delim = XML_DELIM;
    
    return value.split(delim);
}

