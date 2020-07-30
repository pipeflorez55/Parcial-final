#ifndef BOLASCAEN_H
#define BOLASCAEN_H
#include "QPainter"
#include "QGraphicsItem"
#include "QGraphicsScene"
#include "fisicacaen.h"
#include "planetas.h"


class Bolascaen: public QGraphicsItem
{
public:
    Bolascaen();
    ~Bolascaen();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setEcala(float s);
    void actualizar(float v_lim);
    Fisicacaen *getEsf();
    bool coliplaneta();
    bool increase;
private:
    Fisicacaen *esf;
    //Nivel *nivel;
    float escala;
};
#endif // BOLASCAEN_H
