#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>


class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void drawStar(QPainter& painter);
    int h=height();
    int w=width();
    QPoint tinhtien(QPoint a, int tx, int ty);
    QPoint quay(QPoint a, QPoint b, double c);
    QPoint tile(QPoint a, QPoint b, int sx, int sy);
    QPoint doixungx(QPoint a);
    QPoint doixungy(QPoint a);
    void vethaicuc(QPainter &painter);
    void vebonghoa(QPainter &painter);
    int random(int x);
    void drawRosette(QPainter &painter);
    void drawVNFlag(QPainter &painter);
//    void drawMultiEllipse(QPainter &painter);
    void tron(QPainter &painter);
    void tron1(QPainter &painter);
    void sierpinski(QPainter &painter);
    int mode = 0;

signals:

public slots:

};

#endif // GRAPHICS_H
