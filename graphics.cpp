#include "graphics.h"
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <math.h>
#define _USE_MATH_DEFINES

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    switch(mode){
        case 1:
            vebonghoa(painter);
            break;
        case 2:
            drawStar(painter);
            break;
        case 3:
            vethaicuc(painter);
            break;
        case 4:
            drawRosette(painter);
            break;
        case 5:
            drawVNFlag(painter);
            break;
        case 6:
            tron(painter);
            break;
        case 7:
            tron1(painter);
            break;
        case 8:
            sierpinski(painter);
            break;
    }
}

QPoint graphics::tinhtien(QPoint a, int tx, int ty){
    QPoint n;
    n.setX(a.x()+tx);
    n.setY(a.y()+ty);
    return n;
}

QPoint graphics::tile(QPoint a, QPoint b, int sx, int sy){
    QPoint n;
    n.setX(a.x()*sx+b.x()*(1-sx));
    n.setY(a.y()*sy+b.y()*(1-sy));
    return n;
}

QPoint graphics::quay(QPoint a, QPoint b, double c){
    QPoint d;
    double v = (c*M_PI)/180;
    d.setX(b.x() + (a.x() - b.x())*cos(v) - (a.y() - b.y())*sin(v));
    d.setY(b.y() + (a.x() - b.x())*sin(v) + (a.y() - b.y())*cos(v));
    return d;
}

QPoint graphics::doixungx(QPoint a){
    QPoint n;
    n.setX(a.x());
    n.setY(-a.y());
    return n;
}

QPoint graphics::doixungy(QPoint a){
    QPoint n;
    n.setX(-a.x());
    n.setY(a.y());
    return n;
}

int graphics::random(int x){
    return rand()%x;
}

void graphics::vebonghoa(QPainter &painter){
    painter.setBrush(QColor(random(255), random(255), random(255)));
    painter.setPen(Qt::NoPen);
    int x=random(width());
    int y=random(height());
    int d=100;
    int r=d/3;
    QPoint c(x, y);
    QPoint p(x, y-r);
    QPoint nhi = tinhtien(p, 0, r);
    for(int i=1; i<=5; i++){
        QPoint pn = quay(p, c, i*72);
        painter.drawEllipse(pn, r, r);
    }
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(nhi, r/2, r/2);
}

void graphics::drawStar(QPainter &painter){
    painter.setPen(Qt::red);
    QPolygon polygon;
    int x = width()/2;
    int y = height()/2;
    QPoint p(x, y-100);
    QPoint c(x, y);
    polygon<<QPoint(p.x(), p.y());
    for(int i=1; i<5; i++){
        QPoint pn = quay(p, c, i*72);
        polygon << QPoint(pn.x(), pn.y());
    }
    painter.setPen(QColor(random(255), random(255), random(255)));
    painter.drawPolygon(polygon);
//    painter.setPen(Qt::yellow);
    painter.setPen(QColor(random(255), random(255), random(255)));
    painter.drawLine(polygon.value(0), polygon.value(3));
    painter.drawLine(polygon.value(0), polygon.value(2));
    painter.drawLine(polygon.value(1), polygon.value(3));
    painter.drawLine(polygon.value(2), polygon.value(4));
    painter.drawLine(polygon.value(1), polygon.value(4));
}

void graphics::vethaicuc(QPainter &painter){
//    painter.setPen(Qt::red);
    int x = width()/2;
    int y = height()/2;
    int r = 200;
    int r1 = r/2;
    int xl=x-r;
    int yl=y-r1;
    int xr=x;
    int yr=y-r1;
    QPoint p(x, y);
    painter.setBrush(Qt::black);
    painter.drawChord(xl, (r-yl), 2*r, 2*r, 0, 180*16);
    painter.setBrush(Qt::white);
    painter.drawChord(xl, (r-yl), 2*r, 2*r, 0, -180*16);

    xr=doixungx(QPoint(xl, yl)).x();
    yr=doixungy(QPoint(xl, yl)).y();
    xr=tinhtien(QPoint(xr, yr), r, 0).x();
    painter.setBrush(Qt::black);
    painter.drawChord(xl, yl+r/19, r, r, 0, -180*16);
    painter.setBrush(Qt::white);
    painter.setPen(Qt::white);
    painter.drawChord(xr, yl+r/18, r, r, 0, 180*16);

    QPoint pl(x-r/2, y);
    QPoint pr(x+r/2, y);
    painter.drawEllipse(pl, r/10, r/10);
    painter.setBrush(Qt::black);
    painter.drawEllipse(pr, r/10, r/10);


}

void graphics::drawRosette(QPainter &painter){
    painter.setPen(Qt::red);
    QPolygon polygon;
    int i=0;
    int x = width()/2;
    int y = height()/2;
    QPoint p(x, y-100);
    QPoint c(x, y);
    int g = 10;
    polygon<<QPoint(p.x(), p.y());
    for(int i=1; i<=g; i++){
        QPoint pn = quay(p, c, i*(360/g));
        polygon << QPoint(pn.x(), pn.y());
    }
    painter.setPen(Qt::red);
    painter.drawPolygon(polygon);
    for(i; i<g; i++){
        for(int j=i; j < g; j++){
            if((i+2) > g){
                painter.setPen(QColor(random(255), random(255), random(255)));
                painter.drawLine(polygon.value(i), polygon.value(1));
                painter.drawLine(polygon.value(i), polygon.value(j));}
            else{
                painter.setPen(QColor(random(255), random(255), random(255)));
                painter.drawLine(polygon.value(i), polygon.value(i+2));
                painter.drawLine(polygon.value(i), polygon.value(j));}
        }
    }
}


void graphics::drawVNFlag(QPainter &painter){
    int x = width(), y = height();
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(x/4, y/4, x/2, y/2);
    float alpha = (72*M_PI)/180, beta = (36*M_PI)/180;
    int r = x/8, r1 = x/20;
    float xs = x/2, ys = y/2;
    QPointF star[10] = {
        QPointF(xs, ys - r),
        QPointF(xs + r1*sin(beta), ys - r1*cos(beta)),
        QPointF(xs + r*sin(alpha), ys - r*cos(alpha)),
        QPointF(xs + r1*sin(alpha), ys + r1*cos(alpha)),
        QPointF(xs + r*sin(beta), ys + r*cos(beta)),
        QPointF(xs, ys + r1),
        QPointF(xs - r*sin(beta), ys + r*cos(beta)),
        QPointF(xs - r1*sin(alpha), ys + r1*cos(alpha)),
        QPointF(xs - r*sin(alpha), ys - r*cos(alpha)),
        QPointF(xs - r1*sin(beta), ys - r1*cos(beta))
    };
    painter.setBrush(Qt::yellow);
    painter.drawPolygon(star, 10);
}

void graphics::tron(QPainter &painter){
    QPolygon polygon;
    int x = width()/2;
    int y = height()/2;
    QPoint p(x,y);
    int n = 75;
    int a = 200;
    int b = 80;
    int goc = 5;
    for (int i = 0; i < n; i++) {
        painter.translate(p);
        painter.rotate(goc);
        painter.setPen(QColor(random(255), random(255), random(255)));
        painter.drawEllipse(-a/2,-b/2,a,b);
        painter.translate(-p);
    }
}
void graphics::tron1(QPainter &painter){
    QPolygon polygon;
    int x = width()/2;
    int y = height()/2;
    QPoint p(x+10,y);
    int n = 75;
    int a = 210;
    int b = 80;
    int goc = 5;
    for (int i = 0; i < n; i++) {
        painter.translate(p);
        painter.rotate(goc);
        painter.drawEllipse(0,b/2,a,b);
        painter.translate(-p);
    }
}
void graphics::sierpinski(QPainter & painter){
    int x = width()/2;
    int y = height()/2;
    QPointF p[3] = {
        QPointF(x-20, y-200),
        QPointF(x-200,y+200),
        QPointF(x+200, y+180)
    };
    painter.drawPolygon(p, 3);

}
