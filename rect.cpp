#include "rect.h"
#include <iostream>


Rect::Rect(QObject *parent) :
    QObject(parent), QGraphicsItem() {
    length=30;
    width=30;
}

Rect::~Rect(){}

QRectF Rect::boundingRect() const
{
    return QRectF(0,0, length, width);
}
