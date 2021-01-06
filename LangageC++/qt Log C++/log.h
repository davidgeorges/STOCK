#ifndef __LOG__H__
#define __LOG__H__

// include
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <QtWidgets>
using namespace std;


//classe
class FenGenerer :  public QDialog
{

    Q_OBJECT
    private slots:
    void cree();

    public:
    FenGenerer()//construceur
    {

        //Creation Qline edit
        nom1 = new QLineEdit();
        mot1 = new QLineEdit();
        mot11 = new QLineEdit();
        //resize la taille
        nom1->setFixedSize(200,20);
        mot1->setFixedSize(200,20);
        mot11->setFixedSize(200,20);


        send = new QPushButton("Send");
        fermer = new QPushButton("Fermer");

        QVBoxLayout *layoutPrincipal = new QVBoxLayout; // layout vertical
        layoutPrincipal->addWidget(nom1);
        layoutPrincipal->addWidget(mot1);
        layoutPrincipal->addWidget(mot11);
        layoutPrincipal->addWidget(send);
        layoutPrincipal->addWidget(fermer); // et on met le bouton  fermer

        resize(405, 209);// resize la fenetre
        this->setLayout(layoutPrincipal);// on dit a la fenetre d'utiliser le layout
        connect(send, SIGNAL(clicked()), this, SLOT(cree()));
        connect(fermer,SIGNAL(clicked()),qApp,SLOT(quit()));
    }
    ~FenGenerer()
    {
        delete this;
    }


    private:
    QLineEdit *nom1;
    QLineEdit *mot1;
    QLineEdit *mot11;
    QPushButton *fermer;
    QPushButton *send;
    QString nom2;
    QString mot2;
    QString mot22;
    std::string nom3;
    std::string mot3;
    std::string mot33;
};




//Prototype fonction
void log(string &chaine1,string &chaine2);
void cre(string &chaine1,string &chaine2,string &conf);




#endif
