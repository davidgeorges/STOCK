#include <iostream>
#include "PersonnagePointeur.h"
#include "Guerrier.h"
#include "vector"
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
    /*-------------- Héritage --------------*/
    Personnage p1(84,"Perso1");
    Guerrier p3(53);

    /*Creation d'un objet en pointeur
    Personnage *p3(0);
    p3 = new Guerrier(53);
    p3->sePresenter();
    Si on utilise cela il faudrait mettre le destructeur en virtual sinon lors de la destructuction il appel le destructeur de personnage et non guerrier*/

    /*
    cout << p1.getName()<< std::endl;
    cout << p1.getMana()<< std::endl;
    cout << p3.getVie()<< std::endl;
    cout << p3.getMana()<< std::endl;
    */

   /*-------------- Polymorphisme --------------*/
    affiche(p1);//Polymorphisme, la methode a deux comportement différent selon le parametre, (résolution dynamique des liens, utilisation de methode virtuelle et de pointeur ou référence)
    affiche(p3);//
   /*-------------- Collection hétérogène --------------*/

   /*Au lieu de faire ce code 
    vector<Personnage> listePersonnage;
    vector<Guerrier> listeGuerrier;
    On fait le code qui suit*/

    vector<Personnage*> listePersonnage;//liste de pointeur de type personnage

    listePersonnage.push_back(new Guerrier("David"));
    listePersonnage.push_back(new Guerrier("Goliath"));
    listePersonnage.push_back(new Guerrier("Louis"));

    listePersonnage[0]->sePresenter();
    listePersonnage[1]->sePresenter();
    listePersonnage[2]->sePresenter();
   
    for(int i(0); i<listePersonnage.size(); ++i)
    {
        delete listePersonnage[i];  //On libère la i-ème case mémoire allouée
        listePersonnage[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    /*fonctions virtuelles pures*/

    /*Classes abstraites, une classe qui possède au moins une méthode virtuelle pure est une classe abstraite, on ne peut pas créer d'objet à partir d'une classe abstraite*/



    return 0;
}



