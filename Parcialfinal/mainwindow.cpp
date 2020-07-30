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
    scene->addItem(planeta1);

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
    planeta1->actualizar(v_limit);
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
