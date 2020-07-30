#include "planetas.h"
#include<stdlib.h>
#include<time.h>
#include"bolascaen.h"
#include <math.h>

planetas::planetas(): escala(1)
{
        srand(time(NULL));
}
void planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int num=0+rand()%(10-0);
       if(num==0) painter->setBrush(Qt::blue);
       if(num==1) painter->setBrush(Qt::gray);
       if(num==2) painter->setBrush(Qt::green);
       if(num==3) painter->setBrush(Qt::yellow);
       if(num==4) painter->setBrush(Qt::red);
       if(num==5) painter->setBrush(Qt::black);
       if(num==6) painter->setBrush(Qt::lightGray);
       if(num==7) painter->setBrush(Qt::darkMagenta);
       if(num==8) painter->setBrush(Qt::cyan);
       if(num==9) painter->setBrush(Qt::magenta);
       if(num==10) painter->setBrush(Qt::darkBlue);

    painter->drawEllipse(boundingRect());
}

void planetas::setEcala(float s)
{
    escala = s;
}

float planetas::push_x()
{
    return x;
}

float planetas::push_y()
{
    return y;
}

void planetas::get_posiciones( float xotro2, float yotro2, float xotro3, float yotro3, float xotro4, float yotro4, float xotro5, float yotro5)
{
    x2=xotro2;
    y2=yotro2;
    x3=xotro3;
    y3=yotro3;
    x4=xotro4;
    y4=yotro4;
    x5=xotro5;
    y5=yotro5;



}

void planetas::actualizar(float v_lim)
{
    ra=sqrt(pow((x2-x),2)+ pow((y2-y),2));
    r3=sqrt(pow((x3-x),2)+ pow((y3-y),2));
    r4=sqrt(pow((x4-x),2)+ pow((y4-y),2));
    r5=sqrt(pow((x5-x),2)+ pow((y5-y),2));
    ay=((G*masai)*(y2-y))/pow(ra,3)+((G*masai)*(y3-y))/pow(r3,3)+((G*masai)*(y4-y))/pow(r4,3)+((G*masai)*(y5-y))/pow(r5,3);
    ax=((G*masai)*(x2-x))/pow(ra,3)+((G*masai)*(x3-x))/pow(r3,3)+((G*masai)*(x4-x))/pow(r4,3)+((G*masai)*(x5-x))/pow(r5,3);
    vy+=(ay*T);
    vx+=(ax*T);
    x+=(vx*T);
    y+=vy*T;
    setPos(xbase+(x/40),ybase+(y/40));
    coliplaneta();
}
QRectF planetas::boundingRect() const
{
    return QRectF(-1*escala*radio,-1*escala*radio,2*escala*radio,2*escala*radio);
}

bool planetas::coliplaneta()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
       for(int i = 0, n = colliding_items.size(); i < n; i++){
          if(typeid(*(colliding_items[i])) == typeid (Bolascaen)){
            QPainter *painter;
            int num=0+rand()%(10-0);
               if(num==0) painter->setBrush(Qt::blue);
               if(num==1) painter->setBrush(Qt::gray);
               if(num==2) painter->setBrush(Qt::green);
               if(num==3) painter->setBrush(Qt::yellow);
               if(num==4) painter->setBrush(Qt::red);
               if(num==5) painter->setBrush(Qt::black);
               if(num==6) painter->setBrush(Qt::lightGray);
               if(num==7) painter->setBrush(Qt::darkMagenta);
               if(num==8) painter->setBrush(Qt::cyan);
               if(num==9) painter->setBrush(Qt::magenta);
               if(num==10) painter->setBrush(Qt::darkBlue);
           }
       }
}

void planetas::set_valores(float xi, float yi, float vxi, float vyi, float masa, float radioi)
{
    x=xi;
    y=yi;
    vx=vxi;
    vy=vyi;
    radio=radioi/10;
}
