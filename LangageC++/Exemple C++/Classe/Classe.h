#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE
#include <string>
#include "Classe2.h"


/* -------------------------------------- David Georges ------------------------------------- */
                        /*Code pris d'OpenClassRooms pour memo exemple*/

class Personnage
{
    public:
    Personnage(); //Constructeur
    ~Personnage();//Destructeur
    Personnage(std::string nomArme, int degatsArme);//Constructeur surcharge
    Personnage(Personnage const& autre);//Constructeur de copie avec passage par reference
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);//Passage par reference
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    //Methode constante qui n'affecte pas, modifie pas l'objet , sert de methode d'affichage...
    void maMethode(int parametre) const;

    private:
    int m_vie;
    int m_mana;
    std::string m_nomArme; //Pas de using namespace std, il faut donc mettrestd:: devant string
    int m_degatsArme;
    Arme m_arme; //Notre Personnage possède une Arme ( c'est une classe et m_arme = objet )

};

#endif