#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,1000);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(420,720);    // Фиксируем размеры виджета
    QWidget *base=new QWidget;      // Создание виджета base
    body=new QVBoxLayout(base);     // Cоздания вертикального ряда из выравниваемых объектов
    this->setCentralWidget(base);   // Расположить ряд по центру

    //Создание виджета для отображения содержимого сценты
    QGraphicsView *graphicsView = new QGraphicsView();
    graphicsView->setEnabled(false);

    //Вывести окно, где будет располагаться сцента на центр экрана
    body->addWidget(graphicsView);

    // установка графической сцены в graphicsView
    scene=new QGraphicsScene();
    graphicsView->setScene(scene);

    //scene->setSceneRect(0,0,300,600);
    scene->addLine(0,600,300,600,QPen(Qt::black));
    scene->addLine(0,0,0,600,QPen(Qt::black));
    scene->addLine(300,0,300,600,QPen(Qt::black));
    scene->addLine(0,0,300,0,QPen(Qt::black));

    //установка кнопки старта
    pb=new QPushButton("START",this);
    body->addWidget(pb);

    connect(pb, SIGNAL(clicked()), this, SLOT(removeitem_figure()));
    connect(pb, SIGNAL(clicked()), this, SLOT(timer_start()));


}

QVector <QPoint> MainWindow::creat_map()
{
    QVector <QPoint> Map;
    for(int j=0;j<300;j+=30){
        for(int i=0;i<600;i+=30){
            QPoint point;
            point.setX(j);
            point.setY(i);
            Map.push_back(point);
        }
    }
    return Map;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::point_search_figure_two_positions(int a, int b,int c, int d)
{
     switch(type_figure){
     case 1:
         foreach (QPoint p, map)
            if(figure1->Count_rotation1()&&
               figure1->get_figure1_x()+a==p.x()&&
               figure1->get_figure1_y()+b==p.y())
                    return false;
         foreach (QPoint p, map)
            if(figure1->Count_rotation1()==false&&
               figure1->get_figure1_x()+c==p.x()&&
               figure1->get_figure1_y()+d==p.y())
                    return false;
         return true;
         break;
     case 2:
         foreach (QPoint p, map)
            if(figure2->Count_rotation1()&&
               figure2->get_figure1_x()+a==p.x()&&
               figure2->get_figure1_y()+b==p.y())
                    return false;
         foreach (QPoint p, map)
            if(figure2->Count_rotation1()==false&&
               figure2->get_figure1_x()+c==p.x()&&
               figure2->get_figure1_y()+d==p.y())
                    return false;
         return true;
         break;
     }
}
bool MainWindow::point_search_figure_four_positions(int a,int b,int c,int d,int e,int g,int l, int s)
{
    switch(type_figure){
    case 3:
        foreach (QPoint p, map)
           if(figure3->Count_rotation1()&&
              figure3->Count_rotation2()&&
              figure3->get_figure1_x()+a==p.x()&&
              figure3->get_figure1_y()+b==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure3->Count_rotation1()&&
              figure3->Count_rotation2()==false&&
              figure3->get_figure1_x()+c==p.x()&&
              figure3->get_figure1_y()+d==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure3->Count_rotation1()==false&&
              figure3->Count_rotation2()&&
              figure3->get_figure1_x()+e==p.x()&&
              figure3->get_figure1_y()+g==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure3->Count_rotation1()==false&&
              figure3->Count_rotation2()==false&&
              figure3->get_figure1_x()+l==p.x()&&
              figure3->get_figure1_y()+s==p.y())
                   return false;
        return true;
        break;
    case 4:
        foreach (QPoint p, map)
           if(figure4->Count_rotation1()&&
              figure4->Count_rotation2()&&
              figure4->get_figure1_x()+a==p.x()&&
              figure4->get_figure1_y()+b==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure4->Count_rotation1()&&
              figure4->Count_rotation2()==false&&
              figure4->get_figure1_x()+c==p.x()&&
              figure4->get_figure1_y()+d==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure4->Count_rotation1()==false&&
              figure4->Count_rotation2()&&
              figure4->get_figure1_x()+e==p.x()&&
              figure4->get_figure1_y()+g==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure4->Count_rotation1()==false&&
              figure4->Count_rotation2()==false&&
              figure4->get_figure1_x()+l==p.x()&&
              figure4->get_figure1_y()+s==p.y())
                   return false;
        return true;
        break;
    case 5:
        foreach (QPoint p, map)
           if(figure5->Count_rotation1()&&
              figure5->Count_rotation2()&&
              figure5->get_figure1_x()+a==p.x()&&
              figure5->get_figure1_y()+b==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure5->Count_rotation1()&&
              figure5->Count_rotation2()==false&&
              figure5->get_figure1_x()+c==p.x()&&
              figure5->get_figure1_y()+d==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure5->Count_rotation1()==false&&
              figure5->Count_rotation2()&&
              figure5->get_figure1_x()+e==p.x()&&
              figure5->get_figure1_y()+g==p.y())
                   return false;
        foreach (QPoint p, map)
           if(figure5->Count_rotation1()==false&&
              figure5->Count_rotation2()==false&&
              figure5->get_figure1_x()+l==p.x()&&
              figure5->get_figure1_y()+s==p.y())
                   return false;
        return true;
        break;
    }
}
void MainWindow::keyPressEvent(QKeyEvent *ke){
    switch(ke->key()){
    case Qt::Key_A:
        //figure1->moveBy(-30, 0);
        switch(type_figure){
        case 1:
            // перемещение влево
            figure1->moveBy(-30, 0);
            // ограничение по бортам
            if(figure1->Count_rotation1()&&figure1->get_figure1_x()==-30)
                figure1->set_figure1_x(figure1->x()+30);
            if(figure1->Count_rotation1()==false&&figure1->get_figure1_x()==-60)
                figure1->set_figure1_x(figure1->x()+30);
            // ограничение по строению
            if(point_search_figure_two_positions(0,30,30,0))
                figure1->set_figure1_x(figure1->x()+30);
            if(point_search_figure_two_positions(0,30,30,30))
                figure1->set_figure1_x(figure1->x()+30);
            if(point_search_figure_two_positions(0,30,60,60))
                figure1->set_figure1_x(figure1->x()+30);
            break;
        case 2:
            // перемещение влево
            figure2->moveBy(-30, 0);
            // ограничение по бортам
            if(figure2->Count_rotation1()&&figure2->get_figure1_x()==-30)
                figure2->set_figure1_x(figure2->x()+30);
            if(figure2->Count_rotation1()==false&&figure2->get_figure1_x()==-60)
                figure2->set_figure1_x(figure2->x()+30);
            // ограничение по строению
            if(point_search_figure_two_positions(0,0,60,0))
                figure2->set_figure1_x(figure2->x()+30);
            if(point_search_figure_two_positions(30,30,30,30))
                figure2->set_figure1_x(figure2->x()+30);
            if(point_search_figure_two_positions(0,0,30,60))
                figure2->set_figure1_x(figure2->x()+30);
            break;
        case 3:
            // перемещение влево
            figure3->moveBy(-30, 0);
            // ограничение по бортам
            if(figure3->Count_rotation1()&&
                    figure3->Count_rotation2()&&
                    figure3->get_figure1_x()==-30)
                figure3->set_figure1_x(figure3->x()+30);
            if(figure3->Count_rotation1()==false&&
                    figure3->Count_rotation2()&&
                    figure3->get_figure1_x()==-30)
                figure3->set_figure1_x(figure3->x()+30);
            if(figure3->Count_rotation1()==false&&
                    figure3->Count_rotation2()==false&&
                    figure3->get_figure1_x()==-60)
                figure3->set_figure1_x(figure3->x()+30);
            if(figure3->Count_rotation1()&&
                    figure3->Count_rotation2()==false&&
                    figure3->get_figure1_x()==-60)
                figure3->set_figure1_x(figure3->x()+30);
            // ограничение по строению
            if(point_search_figure_four_positions(0,0,30,0,30,0,60,0))
                figure3->set_figure1_x(figure3->x()+30);
            if(point_search_figure_four_positions(30,30,30,30,0,30,30,30))
                figure3->set_figure1_x(figure3->x()+30);
            if(point_search_figure_four_positions(0,0,30,60,0,0,60,60))
                figure3->set_figure1_x(figure3->x()+30);
            break;
        case 4:
            // перемещение влево
            figure4->moveBy(-30, 0);
            // ограничение по бортам
            if(figure4->Count_rotation1()&&
                    figure4->Count_rotation2()&&
                    figure4->get_figure1_x()==-30)
                figure4->set_figure1_x(figure4->x()+30);
            if(figure4->Count_rotation1()==false&&
                    figure4->Count_rotation2()&&
                    figure4->get_figure1_x()==-30)
                figure4->set_figure1_x(figure4->x()+30);
            if(figure4->Count_rotation1()==false&&
                    figure4->Count_rotation2()==false&&
                    figure4->get_figure1_x()==-60)
                figure4->set_figure1_x(figure4->x()+30);
            if(figure4->Count_rotation1()&&
                    figure4->Count_rotation2()==false&&
                    figure4->get_figure1_x()==-60)
                figure4->set_figure1_x(figure4->x()+30);
            // ограничение по строению
            if(point_search_figure_four_positions(0,0,30,0,0,0,60,0))
                figure4->set_figure1_x(figure4->x()+30);
            if(point_search_figure_four_positions(60,30,30,30,0,30,60,30))
                figure4->set_figure1_x(figure4->x()+30);
            if(point_search_figure_four_positions(0,0,30,60,0,0,30,60))
                figure4->set_figure1_x(figure4->x()+30);
            break;
            case 5:
                // перемещение влево
                figure5->moveBy(-30, 0);
                // ограничение по бортам
                if(figure5->Count_rotation1()&&
                        figure5->Count_rotation2()&&
                        figure5->get_figure1_x()==-30)
                    figure5->set_figure1_x(figure5->x()+30);
                if(figure5->Count_rotation1()==false&&
                        figure5->Count_rotation2()&&
                        figure5->get_figure1_x()==-30)
                    figure5->set_figure1_x(figure5->x()+30);
                if(figure5->Count_rotation1()==false&&
                        figure5->Count_rotation2()==false&&
                        figure5->get_figure1_x()==-60)
                    figure5->set_figure1_x(figure5->x()+30);
                if(figure5->Count_rotation1()&&
                        figure5->Count_rotation2()==false&&
                        figure5->get_figure1_x()==-60)
                    figure5->set_figure1_x(figure5->x()+30);
                // ограничение по строению
                if(point_search_figure_four_positions(0,0,30,0,60,0,30,0))
                    figure5->set_figure1_x(figure5->x()+30);
                if(point_search_figure_four_positions(0,30,30,30,0,30,60,30))
                    figure5->set_figure1_x(figure5->x()+30);
                if(point_search_figure_four_positions(0,0,30,60,0,30,60,60))
                    figure5->set_figure1_x(figure5->x()+30);
                break;
       }
        break;
    case Qt::Key_D:
        switch(type_figure){
        case 1:
            //перемещение вправо
            figure1->moveBy(30, 0);
            //ограничение по бортам
            if(figure1->get_figure1_x()==240)
                figure1->set_figure1_x(figure1->x()-30);
            //ограничение по строению
            if(point_search_figure_two_positions(60,0,60,30))
                figure1->set_figure1_x(figure1->x()-30);
            if(point_search_figure_two_positions(30,30,60,30))
                figure1->set_figure1_x(figure1->x()-30);
            if(point_search_figure_two_positions(60,0,60,60))
                figure1->set_figure1_x(figure1->x()-30);
            break;
        case 2:
            //перемещение вправо
            figure2->moveBy(30, 0);
            //ограничение по бортам
            if(figure2->get_figure1_x()==240)
                figure2->set_figure1_x(figure2->x()-30);
            //ограничение по строению
            if(point_search_figure_two_positions(30,0,60,0))
                figure2->set_figure1_x(figure2->x()-30);
            if(point_search_figure_two_positions(60,30,60,30))
                figure2->set_figure1_x(figure2->x()-30);
            if(point_search_figure_two_positions(60,0,30,60))
                figure2->set_figure1_x(figure2->x()-30);
            break;
        case 3:
            //перемещение вправо
            figure3->moveBy(30, 0);
            //ограничение по бортам
            if(figure3->get_figure1_x()==240)
                figure3->set_figure1_x(figure3->x()-30);
            //ограничение по строению
            if(point_search_figure_four_positions(60,0,30,0,30,0,60,0))
                figure3->set_figure1_x(figure3->x()-30);
            if(point_search_figure_four_positions(30,30,60,30,60,30,60,30))
                figure3->set_figure1_x(figure3->x()-30);
            if(point_search_figure_four_positions(60,0,30,60,30,0,60,60))
                figure3->set_figure1_x(figure3->x()-30);
            break;
        case 4:
            //перемещение вправо
            figure4->moveBy(30, 0);
            //ограничение по бортам
            if(figure4->get_figure1_x()==240)
                figure4->set_figure1_x(figure4->x()-30);
            //ограничение по строению
            if(point_search_figure_four_positions(60,0,60,0,0,0,60,0))
                figure4->set_figure1_x(figure4->x()-30);
            if(point_search_figure_four_positions(60,30,30,30,60,30,60,30))
                figure4->set_figure1_x(figure4->x()-30);
            if(point_search_figure_four_positions(60,0,30,60,60,30,60,60))
                figure4->set_figure1_x(figure4->x()-30);
            break;
        case 5:
            //перемещение вправо
            figure5->moveBy(30, 0);
            //ограничение по бортам
            if(figure5->get_figure1_x()==240)
                figure5->set_figure1_x(figure5->x()-30);
            //ограничение по строению
            if(point_search_figure_four_positions(60,0,30,0,60,0,60,0))
                figure5->set_figure1_x(figure5->x()-30);
            if(point_search_figure_four_positions(0,30,30,30,60,30,60,30))
                figure5->set_figure1_x(figure5->x()-30);
            if(point_search_figure_four_positions(60,0,60,60,60,30,60,60))
                figure5->set_figure1_x(figure5->x()-30);
            break;
        }
        break;
    case Qt::Key_S:
        switch(type_figure){
        case 1:
            if(figure1->get_figure1_x()==-30){
                figure1->set_figure1_x(figure1->x()+30);
                figure1->rotation_figure1();
            }
            else
            figure1->rotation_figure1();
            break;
        case 2:
            if(figure2->get_figure1_x()==-30){
                figure2->set_figure1_x(figure2->x()+30);
                figure2->rotation_figure1();
            }
            else
            figure2->rotation_figure1();
            break;
        case 3:
            if(figure3->get_figure1_x()==-30){
                figure3->set_figure1_x(figure3->x()+30);
                figure3->rotation_figure1();
            }
            else
            figure3->rotation_figure1();
            break;
        case 4:
            if(figure4->get_figure1_x()==-30){
                figure4->set_figure1_x(figure4->x()+30);
                figure4->rotation_figure1();
            }
            else
            figure4->rotation_figure1();
            break;
         case 5:
            if(figure5->get_figure1_x()==-30){
                figure5->set_figure1_x(figure5->x()+30);
                figure5->rotation_figure1();
            }
            else
            figure5->rotation_figure1();
            break;
        }
        break;
    }
}

void MainWindow::timer_start(){
    type_figure=1+rand()%6;
    switch(type_figure=4){
        case 1:
            figure1=new Figure1();
            figure1->setPos(120, 0);
            timer= new QTimer;
            if(removeItem_figure){
                scene->addItem(figure1);
                connect(timer, SIGNAL(timeout()),SLOT(START_figure()));
                timer->start(200);
            }
            else timer->stop();
            break;
        case 2:
            figure2=new Figure2();
            figure2->setPos(120, 0);
            timer= new QTimer;
            if(removeItem_figure){
                scene->addItem(figure2);
                connect(timer, SIGNAL(timeout()),SLOT(START_figure()));
                timer->start(200);
            }
            else timer->stop();
            break;
        case 3:
            figure3=new Figure3();
            figure3->setPos(120, 0);
            timer= new QTimer;
            if(removeItem_figure){
                scene->addItem(figure3);
                connect(timer, SIGNAL(timeout()),SLOT(START_figure()));
                timer->start(200);
            }
            else timer->stop();
            break;
        case 4:
            figure4=new Figure4();
            figure4->setPos(120, 0);
            timer= new QTimer;
            if(removeItem_figure){
                scene->addItem(figure4);
                connect(timer, SIGNAL(timeout()),SLOT(START_figure()));
                timer->start(200);
            }
            else timer->stop();
            break;
        case 5:
            figure5=new Figure5();
            figure5->setPos(120, 0);
            timer= new QTimer;
            if(removeItem_figure){
                scene->addItem(figure5);
                connect(timer, SIGNAL(timeout()),SLOT(START_figure()));
                timer->start(200);
            }
            else timer->stop();
            break;
    }
}

void MainWindow::removeitem_figure()
{
    if(removeItem_figure==0)
        label->clear();
    removeItem_figure=1;
    map=creat_map();
}

void MainWindow::START_figure(){
    switch(type_figure){
        case 1:
            points_figure1=figure1->vector_points_figure1();
            break;
        case 2:
            points_figure1=figure2->vector_points_figure1();
            break;
        case 3:
            points_figure1=figure3->vector_points_figure1();
            break;
        case 4:
            points_figure1=figure4->vector_points_figure1();
            break;
        case 5:
            points_figure1=figure5->vector_points_figure1();
            break;
    }
    foreach (QPoint p, map)
        for(int i=0;i<4;i++)
             if(points_figure1[i].x()==p.x()&&points_figure1[i].y()+30==p.y())
                 count_map++;
     if(count_map==4)
        count_map=0;
     else {
         timer->stop();
         switch(type_figure){
             case 1:
                 scene->removeItem(figure1);
                 break;
             case 2:
                 scene->removeItem(figure2);
                 break;
             case 3:
                 scene->removeItem(figure3);
                 break;
             case 4:
                 scene->removeItem(figure4);
                 break;
             case 5:
                 scene->removeItem(figure5);
                 break;
         }
         delete_figure();
         count_timer=1;         
     }
     count_map=0;
     foreach (QPoint point, points_figure1){
         if (point.y()==570){
             timer->stop();
             switch(type_figure){
                 case 1:
                     scene->removeItem(figure1);
                     break;
                 case 2:
                     scene->removeItem(figure2);
                     break;
                 case 3:
                     scene->removeItem(figure3);
                     break;
                 case 4:
                     scene->removeItem(figure4);
                     break;
                 case 5:
                     scene->removeItem(figure5);
                     break;
             }
             delete_figure();
             count_timer=1;
         }
     }
     if(count_timer){
         count_timer=0;
         timer_start();
     }
     switch(type_figure){
         case 1:
             figure1->moveBy(X,Y);
             break;
         case 2:
             figure2->moveBy(X,Y);
             break;
         case 3:
             figure3->moveBy(X,Y);
             break;
         case 4:
             figure4->moveBy(X,Y);
             break;
         case 5:
             figure5->moveBy(X,Y);
             break;
     }
}

void MainWindow::delete_figure(){
    for(int i=0;i<4;i++)
        for(int i=0;i<4;i++)
            if(points_figure1[i].y()==30)
                Game_over();
    for(int i=0;i<4;i++){
        foreach (QPoint p, map){
            if(points_figure1[i].x()==p.x()&&points_figure1[i].y()==p.y()){
                map.erase(map.begin()+k);
                rect=new  Rect_figure();
                rect->set_figure1_x(points_figure1[i].x());
                rect->set_figure1_y(points_figure1[i].y());
                if(removeItem_figure)
                scene->addItem(rect);
                rects.push_back(rect);
                int l=0;
                for( it=map_remove.begin();it!=map_remove.end();it++){
                    QPoint point;
                    point=*it;
                    if(point.y()==points_figure1[i].y()){
                        map_remove.insert(it,points_figure1[i]);
                        break;
                    }
                    l++;
                }
                if(map_remove.size()==l)
                    map_remove.push_back(points_figure1[i]);
            }
            k++;
        }
    k=0;
    }
    if(line_search())
        line_delite();
}


void MainWindow::line_delite()
{
    int k=0;
    foreach(QPoint p,map_remove){
        if(p.y()==line)
             map_remove.erase(map_remove.begin()+k);
        else k++;
    }
    k=0;
    it=map_remove.begin();
    foreach(QPoint p,map_remove){
        if(p.y()<line)
            p.setY(p.y()+30);
        (*it)=p;
        it++;
    }
    iter=map.begin();
    foreach (QPoint p, map){
        if(p.y()<line)
            p.setY(p.y()+30);
        (*iter)=p;
        iter++;
    }
    for(int i=0;i<300;i+=30){
        QPoint point;
        point.setX(i);
        point.setY(0);
        map.push_back(point);
    }
    foreach(Rect_figure *r,rects){
        if(r->get_figure1_y()==line){
            QPoint point;
            point.setX(r->get_figure1_x());
            point.setY(r->get_figure1_y());
            scene->removeItem(r);
            rects.erase(rects.begin()+k);
        }
        else k++;
        if(r->get_figure1_y()<line){
            r->set_figure1_y(r->get_figure1_y()+30);
        }
    }
    k=0;
}

void MainWindow::Game_over()
{
    foreach(Rect_figure *r,rects){
         scene->removeItem(r);
         rects.erase(rects.begin());
    }
    foreach(QPoint p,map)
        map.erase(map.begin());
    foreach(QPoint p,map_remove)
        map_remove.erase(map_remove.begin());
    removeItem_figure=0;
    label=new QLabel("<H1>Game over</H1>");
    label->move(70,270);
    scene->addWidget(label);
    timer->stop();
}

bool MainWindow::line_search()
{
    int i=0;
    for( it=map_remove.begin();it!=map_remove.end();it++){
        QPoint p1=*it;
        QPoint p2=*(it+1);
        if(p1.y()==p2.y()){
            i++;
            if(i==9){
                line=p1.y();
                return true;
            }
        }
        else i=0;
    }
    return false;
}
