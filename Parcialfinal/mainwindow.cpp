#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<time.h>

int flag=0, vely=0, velx=0,cont=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    srand(time(NULL));
    ui->setupUi(this);
    v_limit=481;
    h_limit=681;
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);//crea escena
    scene->setSceneRect(0,0,h_limit,v_limit);//limites de la escena
    planeta1= new planetas;
    planeta1->set_valores(0,0,0,0,50000,200);
    scene->addItem(planeta1);
    planeta2= new planetas;
    planeta2->set_valores(-5000,0,0,-2,70,70);
    scene->addItem(planeta2);
    planeta3= new planetas;
    planeta3->set_valores(5000,0,0,2,70,70);
    scene->addItem(planeta3);
    planeta4= new planetas;
    planeta4->set_valores(0,-5000,2,0,70,70);
    scene->addItem(planeta4);
    planeta5= new planetas;
    planeta5->set_valores(0,5000,-2,0,70,70);
    scene->addItem(planeta5);

    ui->graphicsView->setScene(scene);//añade la escena al graphicsview
    //ui->centralwidget->adjustSize();//se ajusta al tamaño
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width()+7,scene->height()+7);//el graphicsview se acomoda al tamaño de la escena
    this->resize(ui->graphicsView->width()+50,ui->graphicsView->height()+50);//aumenta el tamañño
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{

    planeta1->get_posiciones(planeta2->push_x(),planeta2->push_y(),planeta3->push_x(),planeta3->push_y(),planeta4->push_x(),planeta4->push_y(),planeta5->push_x(),planeta5->push_y());
    planeta2->get_posiciones(planeta1->push_x(),planeta1->push_y(),planeta3->push_x(),planeta3->push_y(),planeta4->push_x(),planeta4->push_y(),planeta5->push_x(),planeta5->push_y());
    planeta3->get_posiciones(planeta2->push_x(),planeta2->push_y(),planeta1->push_x(),planeta1->push_y(),planeta4->push_x(),planeta4->push_y(),planeta5->push_x(),planeta5->push_y());
    planeta4->get_posiciones(planeta2->push_x(),planeta2->push_y(),planeta3->push_x(),planeta3->push_y(),planeta1->push_x(),planeta1->push_y(),planeta5->push_x(),planeta5->push_y());
    planeta5->get_posiciones(planeta2->push_x(),planeta2->push_y(),planeta3->push_x(),planeta3->push_y(),planeta4->push_x(),planeta4->push_y(),planeta1->push_x(),planeta1->push_y());
    planeta1->actualizar(v_limit);
    planeta2->actualizar(v_limit);
    planeta3->actualizar(v_limit);
    planeta4->actualizar(v_limit);
    planeta5->actualizar(v_limit);

    for (int i=0;i<bars.size();i++) {
    bars.at(i)->actualizar(v_limit);
    bordercollision(bars.at(i)->getEsf());
    }
}


void MainWindow::on_cae_clicked()
{
    int Posix=0+rand()%(670-0);
    float gravi=1+rand()%(10-1);
    bars.push_back(new Bolascaen);
    bars.back()->actualizar(v_limit);
    scene->addItem(bars.back());  // añadir bala a la escena
    Fisicacaen *b = bars.at(cont)->getEsf(); // crear las fisicas de la bala
    b->set_vel(velx,vely,Posix,481);
    b->Newgra(gravi);
    cont++;
}

void MainWindow::bordercollision(Fisicacaen *b)
{

        if(b->get_PosX()< b->get_Radio()){
            b->set_vel(-1*b->get_VelX()*b->get_e(),b->get_VelY(),b->get_Radio(),b->get_PosY());

        }
        if(b->get_PosX()> h_limit-b->get_Radio()){
            b->set_vel(-1*b->get_VelX()*b->get_e(),b->get_VelY(),h_limit-b->get_Radio(),b->get_PosY());

        }
        if(b->get_PosY()< b->get_Radio()){
            b->set_vel(b->get_VelX(),-1*b->get_e()*b->get_VelY(),b->get_PosX(),b->get_Radio());

        }
        if(b->get_PosY()>v_limit-b->get_Radio()){
            b->set_vel(b->get_VelX(),-1*b->get_e()*b->get_VelY(),b->get_PosX(),v_limit-b->get_Radio());

        }

}
