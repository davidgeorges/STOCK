#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h" //Ne PAS oublier d'inclure Arme.h pour en avoir la d�finition

void getName(std::string name);

class Personnage
{
    // public = on peut modifier les fonctions directement dans le main
    // l'attribut ou la m�thode peut �tre appel� depuis l'ext�rieur de l'objet
    public:
    Personnage();
    Personnage(std::string name);
    Personnage(Personnage const& personnageACopier);
    Personnage(std::string name,std::string nomArme, int degatsArme);
    void receiveDamage(int nbDamage);
    void attack(Personnage &cible);
    void potion(int nbPotion);
    void swapsword(std::string nameNewSword, int newSwordDamage);
    bool estVivant();
    void afficherEtat() const;

    // private = impossible de modifier les fonctions directement dans le main
    // l'attribut ou la m�thode ne peut pas �tre appel� depuis l'ext�rieur de l'objet.

    private:
    int m_vie;
    int m_mana;
    std::string m_nom;
    Arme *m_arme;
};

#endif

