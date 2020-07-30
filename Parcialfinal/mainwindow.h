#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "QPixmap"
#include <QWidget>
#include "QBrush"
#include "bolascaen.h"
#include "fisicacaen.h"
#include "QTimer"
#include<stdlib.h>
#include<time.h>
#include"planetas.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void actualizar();
    void on_cae_clicked();

private:
    QGraphicsScene *scene;
    QTimer *timer;
    float dt;
    int h_limit;
    int v_limit;
    planetas *planeta1;
    Ui::MainWindow *ui;
    void bordercollision(Fisicacaen *b);
    QList<Bolascaen*>bars;
};
#endif // MAINWINDOW_H
