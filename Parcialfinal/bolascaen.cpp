#include "bolascaen.h"


Bolascaen::Bolascaen(): escala(1)
{
    float posx,posy,velx,vely,r,mass,K,e;
    posx = 32;
    posy = 150;
    r = 7;
    mass = 500;
    velx = 0;
    vely = 0;
    K = 0.03;
    e = 0.2;
    esf = new Fisicacaen(posx,posy,velx,vely,mass,r,K,e);
}

Bolascaen::~Bolascaen()
{
    delete esf;
}

QRectF Bolascaen::boundingRect() const
{
    return QRectF(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio());

}

void Bolascaen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void Bolascaen::setEcala(float s)
{
    escala = s;
}

void Bolascaen::actualizar(float v_lim)
{
    esf->actualizar();
    setPos(esf->get_PosX(),(v_lim-esf->get_PosY()));
    increase=coli();
    colistar();

}

Fisicacaen *Bolascaen::getEsf()
{
    return esf;
}

bool Bolascaen::coli()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for(int i = 0, n = colliding_items.size(); i < n; i++){
//        if(typeid(*(colliding_items[i])) == typeid (enemy)){

//            //Increase score

//            //remove
//            colliding_items[i]->setPos(-100,-100);
//            //delete
//            return true;


//        }
//    }
    return false;


}

bool Bolascaen::colistar()
{
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for(int i = 0, n = colliding_items.size(); i < n; i++){
//        if(typeid(*(colliding_items[i])) == typeid (Circular)){

//            //Increase score

//            //remove
//            scene()->removeItem(this);
//            //delete
//        }
//    }
//    for(int i = 0, n = colliding_items.size(); i < n; i++){
//        if(typeid(*(colliding_items[i])) == typeid (Pendulo)){

//            //Increase score

//            //remove
//            scene()->removeItem(this);
//            //delete
//        }
//    }


}
