#include "Duree.h"
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
    if (heures >24)
    {
        cout << " Pas encore programmer " << endl;
    }

    else if (minutes > 60)
    {

        cout << heures <<" : " << minutes << endl;
        heures += minutes/60;
        minutes = minutes%60;
        cout << heures <<" : " << minutes << endl;

    }

    else if (secondes>60)
    {
        minutes += secondes/60;
        secondes = secondes%60;
    }

cout << heures <<" : " << minutes << " : " << secondes << endl;

}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool operator==(Duree const& a, Duree const& b)// par réference , donc a =  premier param et b = deuxieme param
{
    return a.estEgal(b);
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool operator!=(Duree const& a, Duree const& b)
{
    if (a==b)
        return false;
    else
        return true;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/

bool operator<(Duree const& a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool operator>(Duree const& a, Duree const& b)
{
    return a.estPlusGrandQue(b);
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool Duree::estPlusGrandQue(Duree const& b) const
{
    if (m_heures > b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes > b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes > b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool Duree::estPlusGrandOuEgal(Duree const& b) const
{
    if (m_heures >= b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures >= b.m_heures && m_minutes > b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures >= b.m_heures && m_minutes >= b.m_minutes && m_secondes >= b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
bool operator>=(Duree const& a, Duree const& b)
{
    return a.estPlusGrandOuEgal(b);
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
Duree& Duree::operator+=(const Duree& a)
{
    //1 : ajout des secondes
    m_secondes += a.m_secondes;
    //Si le nombre de secondes dépasse 60, on rajoute des minutes
    //Et on met un nombre de secondes inférieur à 60
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    //2 : ajout des minutes
    m_minutes += a.m_minutes;
    //Si le nombre de minutes dépasse 60, on rajoute des heures
    //Et on met un nombre de minutes inférieur à 60
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    //3 : ajout des heures
    m_heures += a.m_heures;

    return *this;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
void Duree::afficher() const
{
    cout << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << endl;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
Duree operator+(Duree const& a, Duree const& b) // Duree const& a + Duree const& b
{
    Duree copie(a);
    copie += b;
    return copie;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
ostream &operator<<( ostream &flux, Duree const& duree) // ostream &flux << Duree const& duree
{
    duree.afficher(flux) ;
    return flux;
}
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}
