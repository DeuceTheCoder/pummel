#include "tabmanager.h"
#include "global.h"
#include "mainwindow.h"
extern MainWindow window;

TabManager::TabManager(QWidget *parent) : QTabWidget(parent)
{
    connect(this , SIGNAL(currentChanged(int)),this,SLOT(currentChangedSlot(int)));
}


void TabManager::currentChangedSlot(int index)
{

}

