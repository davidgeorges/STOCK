#include <iostream>
#include <string>
#include "personnage.h"

using namespace std;


int main()
{
    Personnage joueur1{"David","Eppee zebi",25}, joueur2{"Jean"};


    joueur1.attack(joueur2);
    joueur2.attack(joueur1);
    joueur1.potion(20);
    joueur2.swapsword("Exca", 25);
    joueur1.afficherEtat();

    return 0;
}
