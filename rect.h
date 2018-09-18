#ifndef RECT_H
#define RECT_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Rect: public QObject, public QGraphicsItem{
Q_OBJECT
public:
    explicit Rect(QObject *parent = 0);
    ~Rect();
protected:
    QRectF boundingRect() const;
    int length, width;
};
#endif

