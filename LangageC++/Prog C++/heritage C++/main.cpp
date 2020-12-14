#include <iostream>
#include "personnage.h"
#include "guerrier.h"
#include "vector"

using namespace std;

void presenter(Personnage const& p)  //Présente le véhicule passé en argument
{
    p.affiche();
}

int main()
{

    vector<Personnage*> listePersonnage; // tableau de type personnage

    listePersonnage.push_back(new Personnage()); // un joueur
    listePersonnage.push_back(new Guerrier()); // guerrier

    listePersonnage[0]->affiche(); // résolution dynamique des liens.
    listePersonnage[1]->affiche(); // résolution dynamique des liens. on appel la bonne version des méthodes ,il sait si l'objet est de type mère ou fille ( personnage ou guerrier )

    return 0;
}
