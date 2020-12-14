#include <iostream>
#include "personnage.h"
#include "guerrier.h"
#include "vector"

using namespace std;

void presenter(Personnage const& p)  //Pr�sente le v�hicule pass� en argument
{
    p.affiche();
}

int main()
{

    vector<Personnage*> listePersonnage; // tableau de type personnage

    listePersonnage.push_back(new Personnage()); // un joueur
    listePersonnage.push_back(new Guerrier()); // guerrier

    listePersonnage[0]->affiche(); // r�solution dynamique des liens.
    listePersonnage[1]->affiche(); // r�solution dynamique des liens. on appel la bonne version des m�thodes ,il sait si l'objet est de type m�re ou fille ( personnage ou guerrier )

    return 0;
}
