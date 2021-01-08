#include "Arme.h"

using namespace std;
//-----------------------------------------------------------------------------------------------
Arme::Arme() : m_nom("�p�e rouill�e"), m_degats(10)
{

}
//-----------------------------------------------------------------------------------------------
Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}
//-----------------------------------------------------------------------------------------------
void Arme:: swapS(std::string nameNewSword, int newSwordDamage)
{
    m_nom = nameNewSword;
    m_degats = newSwordDamage;
}
//-----------------------------------------------------------------------------------------------
void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " Degats : " << m_degats << endl;
}
//-----------------------------------------------------------------------------------------------
int Arme::getDegats() const
{
    return m_degats;
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------