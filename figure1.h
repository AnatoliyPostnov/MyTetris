#ifndef FIGURE1_H
#define FIGURE1_H
#include <rect.h>
#include <QPaintEvent>
#include <QVector>

class Figure1:public Rect
{
    Q_OBJECT
public:
    Figure1();
    int get_figure1_x();
    int get_figure1_y();
    void set_figure1_x(int a);
    void set_figure1_y(int a);
    void set_length(int a);
    void set_width(int a);
    void rotation_figure1();
    QVector <QPoint > vector_points_figure1();
    bool Count_rotation1();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int count_rotation;
};

#endif // FIGURE1_H
