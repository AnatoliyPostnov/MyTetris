#ifndef FIGURE3_H
#define FIGURE3_H
#include <rect.h>
#include <QPaintEvent>
#include <QVector>

class Figure3:public Rect
{
    Q_OBJECT
public:
    Figure3();
    int get_figure1_x();
    int get_figure1_y();
    void set_figure1_x(int a);
    void set_figure1_y(int a);
    void set_length(int a);
    void set_width(int a);
    void rotation_figure1();
    QVector <QPoint > vector_points_figure1();
    bool Count_rotation1();
    bool Count_rotation2();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int count_rotation1,count_rotation2;
};
#endif // FIGURE3_H
