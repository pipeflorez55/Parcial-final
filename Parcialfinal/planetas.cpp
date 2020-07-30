#include "planetas.h"
#include<stdlib.h>
#include<time.h>
#include"bolascaen.h"
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

void planetas::actualizar(float v_lim)
{
    setPos(x,(v_lim-y));
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
