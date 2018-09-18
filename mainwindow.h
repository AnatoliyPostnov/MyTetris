#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <rect.h>
#include <figure1.h>
#include <figure2.h>
#include <figure3.h>
#include <figure4.h>
#include <figure5.h>
#include <figure6.h>
#include <rect_figure.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void keyPressEvent(QKeyEvent *ke);
    void START_figure();
    void timer_start();
    void removeitem_figure();
//public signals:
//    void remove_line();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *body;
    QGraphicsScene *scene;
    QLabel *label;
    QPushButton *pb;
    QVector <QPoint> map;
    QVector <QPoint>::iterator iter;
    QLinkedList <QPoint> map_remove;
    QLinkedList <QPoint>::iterator it;
    Figure1 *figure1;
    Figure2 *figure2;
    Figure3 *figure3;
    Figure4 *figure4;
    Figure5 *figure5;
    Figure6 *figure6;
    QTimer *timer;
    QVector <QPoint> creat_map();
    Rect_figure *rect;
    QVector<Rect_figure *> rects;
    QVector<QPoint> points_figure1;
    int type_figure=0;
    int X=0;
    int Y=30;
    int k=0,removeItem_figure=1;
    int line=0;
    int count_map=0,count=1;
    int count_timer=0;       
    void delete_figure();
    void line_delite();
    void Game_over();
    bool point_search_figure_two_positions(int a,int b,int c,int d);
    bool point_search_figure_four_positions(int a,int b,int c,int d,int e,int g,int l, int s);
    bool line_search();
    bool constraint_by_structure_figure6_1(int a);
    bool constraint_by_structure_figure6_2(int a);
    bool constraint_by_structure_figure6_3(int a);
};

#endif // MAINWINDOW_H
