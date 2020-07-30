#ifndef PLANETAS_H
#define PLANETAS_H
#include "QPainter"
#include "QGraphicsItem"
#include "QGraphicsScene"

class planetas: public QGraphicsItem
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setEcala(float s);
     void actualizar(float v_lim);
    QRectF boundingRect() const;
     bool coliplaneta();
    planetas();
private:
   float radio=5,escala,x=100,y=100;
};

#endif // PLANETAS_H
