#include <iostream>
#include "personnage.h"

using namespace std;
//-----------------------------------------------------------------------------------------------
void Personnage::receiveDamage(int nbDamage)
{
    m_vie -= nbDamage;

    if(m_vie <0)
    {
        m_vie =0;
        cout << " Dead :/ " << endl;
    }
}
//-----------------------------------------------------------------------------------------------
void Personnage::attack(Personnage &cible)
{
    cible.receiveDamage(m_arme->getDegats());
    cout << m_nom << " receive " << m_arme->getDegats() << " damage  ouch !" << endl;
}
//-----------------------------------------------------------------------------------------------
void Personnage::potion(int nbPotion)
{
    m_vie += nbPotion;
    cout << m_nom << " + " << nbPotion << " HP " << endl;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}
//-----------------------------------------------------------------------------------------------
void Personnage::swapsword(std::string nameNewSword, int newSwordDamage)
{
    m_arme->swapS(nameNewSword,newSwordDamage);
    cout << m_nom << " swap sword... New sword :" << nameNewSword << " dealing " << newSwordDamage << " damage " << endl;
}
//-----------------------------------------------------------------------------------------------
bool Personnage::estVivant()
{
    return m_vie > 0;
}
//-----------------------------------------------------------------------------------------------
void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana: " << m_mana << endl;
    m_arme->afficher();

}
//-----------------------------------------------------------------------------------------------
Personnage::Personnage() : m_vie(100), m_mana(100), m_arme(0)
{
    //Rien à mettre dans le corps du constructeur, tout a déjà été fait !
    m_arme = new Arme("Epee first",10);
}
//-----------------------------------------------------------------------------------------------
Personnage::Personnage(std::string name)
{
    m_nom = name;
}
//-----------------------------------------------------------------------------------------------
Personnage::Personnage(std::string name,string nomArme, int degatsArme) :  m_nom(name),m_arme(0), m_vie(100), m_mana(100)
{
    m_arme = new Arme(nomArme,degatsArme);
}
