#include "figure5.h"
Figure5::Figure5()
{
    count_rotation1=1;
    count_rotation2=1;
    length=90;
    width=90;
}

void Figure5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(90,0) << QPoint(90,30)
            << QPoint(30, 30) << QPoint(30, 60) << QPoint(0, 60);
    /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter->setBrush(Qt::green);
    /// Рисуем полигон
    if(count_rotation1&&count_rotation2)
        painter->drawPolygon(polygon);
    if(count_rotation1&&count_rotation2==0){
        QPoint point;
        point.setX(-90);
        point.setY(30);
        painter->rotate(270);
        painter->translate(point);
        painter->drawPolygon(polygon);
    }
    if(count_rotation1==0&&count_rotation2){
        QPoint point;
        point.setX(-90);
        point.setY(-60);
        painter->rotate(180);
        painter->translate(point);
        painter->drawPolygon(polygon);
    }
    if(count_rotation1==0&&count_rotation2==0){
        QPoint point;
        point.setX(0);
        point.setY(-90);
        painter->rotate(90);
        painter->translate(point);
        painter->drawPolygon(polygon);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Figure5::rotation_figure1()
{
    if(count_rotation1&&count_rotation2)
        count_rotation2=0;
    else{
        if(count_rotation1&&count_rotation2==0){
            count_rotation1=0;
            count_rotation2=1;
        }
        else{
            if(count_rotation1==0&&count_rotation2)
                count_rotation2=0;
            else {
                count_rotation1=1;
                count_rotation2=1;
            }
        }
    }
  update();
}

QVector<QPoint> Figure5::vector_points_figure1()
{
    QPoint point;
    QVector<QPoint> fig, figure;
    int a=60,b=60;
    if(count_rotation1==0&&count_rotation2==0){
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==60&&b==0)
                a=30;
            if(a==60&&b==30)
                b=0;
            if(a==60&&b==60)
                b=30;
        }
    }
    if(count_rotation1==0&&count_rotation2){
        a=30;
        b=30;
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==0&&b==30){
                a=60;
                b=0;
            }
            if(a==60&&b==30)
                a=0;
            if(a==30&&b==30)
                a=60;
        }
    }
    if(count_rotation1&&count_rotation2==0){
        a=30;
        b=30;
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==30&&b==0){
                a=60;
                b=60;
            }
            if(a==30&&b==60)
                b=0;
            if(a==30&&b==30)
                b=60;
        }
    }
    if(count_rotation1&&count_rotation2){
        a=0;
        b=0;
        for(int i=0;i<4;i++){
            point.setX(x()+a);
            point.setY(y()+b);
            fig.push_back(point);
            if(a==60&&b==0){
                a=0;
                b=30;
            }
            if(a==30&&b==0)
                a=60;
            if(a==0&&b==0)
                a=30;
        }
    }
    return fig;
}

bool Figure5::Count_rotation1()
{
    if(count_rotation1)
        return true;
    else
        return false;
}
bool Figure5::Count_rotation2()
{
    if(count_rotation2)
        return true;
    else
        return false;
}


int Figure5::get_figure1_x()
{
   return x();
}

int Figure5::get_figure1_y()
{
   return y();
}
void Figure5::set_figure1_x(int a)
{
    setPos(a,y());
}

void Figure5::set_figure1_y(int a)
{
    setPos(x(),a);
}

void Figure5::set_length(int a)
{
    length=a;
}

void Figure5::set_width(int a)
{
    width=a;
}
