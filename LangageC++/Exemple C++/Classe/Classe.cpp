#include <iostream>
#include <string>
#include "Classe.h"
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */
                        /*Code pris d'OpenClassRooms pour memo exemple*/

                        /* Quelque code de classe utilisant une autre classe (code pour exemple) */
                        

Personnage::Personnage()//Lors de la création d'un objet on appel cette sorte de "fonction"  ( constructeur ) qui initialise les attributs (variable de classe) 
{
    m_vie = 100;
    m_mana = 100;
    m_nomArme = "Épée rouillée";
    m_degatsArme = 10;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_nomArme(nomArme), m_degatsArme(degatsArme)//Constructeur surcharge
{
 
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(Personnage const& autre): m_vie(autre.m_vie), m_mana(autre.m_mana), m_nomArme(autre.m_nomArme), m_degatsArme(autre.m_degatsArme)//Constructeur de copie
{

}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::~Personnage()//Destructeur
{
    /* Rien à mettre ici car on ne fait pas d'allocation dynamique
    dans la classe Personnage. Le destructeur est donc inutile mais
    je le mets pour montrer à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques
    autres vérifications si nécessaire avant la destruction de l'objet. */
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage
    
    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());//Utilisateur de notre fichier Classe2 avec la classe Arme
    //On inflige à la cible les dégâts que cause notre arme
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_nomArme = nomNouvelleArme;
    m_degatsArme = degatsNouvelleArme;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
bool Personnage::estVivant()
{
    return m_vie > 0; //Renvoie true si m_vie > 0 et false sinon.
}


/* --------------------------------------------------------------------------------------------------------------------------- */
//Déclaration de la méthode (dans le .cpp) :
void Personnage::maMethode(int parametre) const
{
    cout << " Je suis un personnage ! ";
}

