#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_nom("Jack") // constructeur par defaut qui prend 100 de vie et Jack comme prenom
{

}

Personnage::~Personnage() // desctucteur
{
 // si on a des pointeurs a détruire si le personnage est mort par exemple ( Désallocation de mémoire pour l'objet )

}

void Personnage::recevoirDegats(int degats) // methode recevoir des degats
{
    m_vie -= degats; // vie - degats
}

void Personnage::affiche() const // methode virtual pour que qu'on appelle ça prend la bonne version
{

    cout << "Ceci est un Personnage avec  " << m_vie << " hp " << endl;

}

