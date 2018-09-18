#include "figure6.h"
Figure6::Figure6()
{
    count_rotation=1;
    length=120;
    width=120;
}

void Figure6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPoint point;
    point.setX(0);
    point.setY(-30);
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(120,0) << QPoint(120,30)
            << QPoint(0, 30);
    /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter->setBrush(Qt::green);
    /// Рисуем полигон
    if(count_rotation){
        painter->drawPolygon(polygon);
    }
    else{
        painter->rotate(90);
        painter->translate(point);
        painter->drawPolygon(polygon);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Figure6::rotation_figure1()
{
    if(count_rotation)
    count_rotation=0;
    else count_rotation=1;
    update();
}

QVector<QPoint> Figure6::vector_points_figure1()
{
    QPoint point;
    QVector<QPoint> fig, figure;
    int a=0,b=0;
    if(count_rotation)
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==60&&b==0)
                a=90;
            if(a==30&&b==0)
                a=60;
            if(a==0&&b==0)
            a=30;
        }
    else{
        a=0;
        b=0;
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==0&&b==60)
                b=90;
            if(a==0&&b==30)
                b=60;
            if(a==0&&b==0)
            b=30;
        }
    }
    return fig;
}

bool Figure6::Count_rotation1()
{
    if(count_rotation)
        return true;
    else
        return false;
}


int Figure6::get_figure1_x()
{
   return x();
}

int Figure6::get_figure1_y()
{
   return y();
}
void Figure6::set_figure1_x(int a)
{
    setPos(a,y());
}

void Figure6::set_figure1_y(int a)
{
    setPos(x(),a);
}

void Figure6::set_length(int a)
{
    length=a;
}

void Figure6::set_width(int a)
{
    width=a;
}
