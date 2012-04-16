#include <QBoxLayout>
#include "drawarea.h"
#include "dragscene.h"
#include "dragview.h"
#include "icon.h"

DrawArea::DrawArea(QWidget *parent, int newHeight, int newWidth)
{
    parent = 0;
    scene = new DragScene(0, newHeight, newWidth);
    view = new DragView();
    layout = new QHBoxLayout();
    view->setAcceptDrops(true);
    view->setScene(scene);
    layout->addWidget(view);
//    type = Class;
    this->setLayout(layout);

}
