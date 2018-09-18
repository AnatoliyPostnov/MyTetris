#include "rect_figure.h"

Rect_figure::Rect_figure()
{
    length=30;
    width=30;
}

int Rect_figure::get_figure1_x()
{
    return x();
}

int Rect_figure::get_figure1_y()
{
    return y();
}

void Rect_figure::set_figure1_x(int a)
{
      setPos(a,y());
}

void Rect_figure::set_figure1_y(int a)
{
      setPos(x(),a);
}
QRectF Rect_figure::boundingRect() const
{
    return QRectF(0,0, length, width);
}

void Rect_figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPoint point;
    point.setX(0);
    point.setY(-90);
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(0,30) << QPoint(30,30)
            << QPoint(30, 0);
    /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter->setBrush(Qt::green);
    /// Рисуем полигон
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
