#include "Guerrier.h"

/* --------------------------------------------------------------------------------------------------------------------------- */
Guerrier::Guerrier(int viee)
{
    vie = viee;
    name = "Lothbrok";
    compteur++;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Guerrier::Guerrier(string nom) : Personnage(nom)
{
    vie = 100;
    compteur++;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Guerrier::~Guerrier()
{
    compteur--;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
//méthode de masquage cette fonction a le même nom que celle de la classe personnage mais n'affiche pas la même chose
void Guerrier::sePresenter(){

    //Demasquage, cette ligne appel la methodede de la classe personnage qui a la même nom que la methode de la classe guerrier
    Personnage::sePresenter();
    cout << "Je suis un guerrier !" << std::endl;
}

int Guerrier::nbrDamis() const
{

    return 4;
}


/*
string Guerrier::getName(){

    return name;//on retourne le nom comme il est en privé
}*/