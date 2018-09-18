#ifndef RECT_FIGURE_H
#define RECT_FIGURE_H
#include <rect.h>
#include <QPaintEvent>
#include <QVector>

class Rect_figure:public Rect
{
    Q_OBJECT
public:
    Rect_figure();
    int get_figure1_x();
    int get_figure1_y();
    void set_figure1_x(int a);
    void set_figure1_y(int a);
    QVector <QPoint > vector_points_figure1();
    bool Count_rotation();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECT_FIGURE_H

