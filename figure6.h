#ifndef FIGURE6_H
#define FIGURE6_H
#include <rect.h>
#include <QPaintEvent>
#include <QVector>

class Figure6:public Rect
{
    Q_OBJECT
public:
    Figure6();
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

#endif // FIGURE6_H
