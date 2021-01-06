#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log.h"
#include "crypt.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix("C:/Users/S/Documents/qt/wp4325401.jpg");
    //ui->label_pic->setPixmap(pix);
    //setFixedSize(400,220);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // on recupere les ligne
    nom1 = ui->lineEdit->text();
    mot1 = ui->lineEdit_2->text();
    //si une des deux ligne est vide
    if( nom1.isEmpty() || mot1.isEmpty() )
    {
        QMessageBox error;
        error.setText("Un des champs est vide");
        error.exec();



    }
    else
    {
        //on converti Qstring en string
        nom = nom1.toStdString();
        mot = mot1.toStdString();
        //appel fonction log ( connexion)
        log(nom,mot);
    }


}


void MainWindow::on_pushButton_2_clicked()
{

    //Creation nouvelle fenetre pour s'inscrire
    FenGenerer *fenetreCode = new FenGenerer();
    // execute fenetre avec son premier et seul constructeur qui contient le code ou la fonction cre() (inscription) est utiliser
    fenetreCode->exec();


}

