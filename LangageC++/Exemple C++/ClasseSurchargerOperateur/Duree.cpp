#include <iostream>
#include "Duree.h"
using namespace std;
/* --------------------------------------------------------------------------------------------------------------------------- */
Duree::Duree(int heures, int minutes, int secondes): m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{

}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree& Duree::operator+=(const Duree &duree2)
{
    // 1 : ajout des secondes
    m_secondes += duree2.m_secondes; // Exceptionnellement autorise car meme classe
    // Si le nombre de secondes depasse 60, on rajoute des minutes et on met un nombre de secondes inferieur a 60
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    // 2 : ajout des minutes
    m_minutes += duree2.m_minutes;
    // Si le nombre de minutes depasse 60, on rajoute des heures et on met un nombre de minutes inferieur a 60
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    // 3 : ajout des heures
    m_heures += duree2.m_heures;

    return *this;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree& Duree::operator-=(const Duree &duree2)
{
    // 1 : retrait des secondes
    m_secondes -= duree2.m_secondes; // Exceptionnellement autorise car meme classe
    // Si le nombre de secondes depasse 60, on renleve des minutes et on met un nombre de secondes inferieur a 60
    m_minutes -= m_secondes / 60;
    m_secondes %= 60;

    // 2 : retrait des minutes
    m_minutes -= duree2.m_minutes;
    // Si le nombre de minutes depasse 60, on enleve des heures et on met un nombre de minutes inferieur a 60
    m_heures -= m_minutes / 60;
    m_minutes %= 60;

    // 3 : retrait des heures
    m_heures -= duree2.m_heures;

    return *this;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree& Duree::operator*=(const Duree &duree2)
{
    // 1 : multiplie des secondes
    m_secondes *= duree2.m_secondes;
    if (m_secondes >=60)
    {
       m_secondes %= 60;
       m_minutes++;
    }

    m_minutes *= duree2.m_minutes;
    if (m_minutes>=60)
    {
        m_minutes %= 60;
        m_heures++;
    }

    m_heures *= duree2.m_heures;
    
    cout <<"Heure : "  << m_heures << std::endl;
    cout <<"Minute : "  << m_minutes << std::endl;
    cout <<"Seconde: "  << m_secondes << std::endl;
    

    return *this;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
// NON FONCTIONEL // NON FONCTIONEL // NON FONCTIONEL // NON FONCTIONEL
Duree& Duree::operator/=(const Duree &duree2)
{
    // 1 : divise des secondes
    m_secondes /= duree2.m_secondes;
    if (m_secondes >=60)
    {
       m_secondes %= 60;
    }

    m_minutes /= duree2.m_minutes;
    if (m_minutes>=60)
    {
        m_minutes %= 60;
    }

    m_heures /= duree2.m_heures;

    return *this;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool Duree::estEgal(Duree const& b) const
{
    //Teste si a.m_heure == b.m_heure etc.  
    if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes)
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
        return true;
    else
        return false;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Duree::afficher() const
{
    cout << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << endl;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree operator+(Duree const& a, Duree const& b) 
{
    Duree copie(a);
    copie += b;
    return copie;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie -= b;
    return copie;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree operator*(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie *= b;
    return copie;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Duree operator/(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie /= b;
    return copie;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool operator!=(Duree const& a, Duree const& b)
{
    if(a == b)         //On utilise l'opérateur == qu'on a défini précédemment !
        return false;  //Si ils sont égaux, alors ils ne sont pas différents
    else
        return true;   //Et si ils ne sont pas égaux, c'est qu'ils sont différents ;-)
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool operator<(Duree const &a, Duree const& b)
{
    if(a.estPlusPetitQue(b))
        return true;
    else
        return false;
}