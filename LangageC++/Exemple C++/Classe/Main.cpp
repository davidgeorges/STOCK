#include <iostream>
#include "Classe.h" //Ne pas oublier
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */
                        /*Code pris d'OpenClassRooms pour memo exemple*/

int main()
{
    Personnage david, goliath;
    //Création de 2 objets de type Personnage : david et goliath ( on appel le constructeur qui initialise les attributs de la classe (variable))

    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath réattaque david
    david.attaquer(goliath); //david cattaque goliath
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);//on change arme qui met plus de degats
    goliath.attaquer(david);

    return 0;
}