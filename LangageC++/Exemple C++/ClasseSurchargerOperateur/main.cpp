#include <iostream>
#include "Duree.h"

using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

/* Exemple sur la surcharge d'opérateur , avec un petit d'exemple de l'amitié */

int main()
{
    Duree duree1(0, 10, 42), duree2(0, 53, 27);
    Duree duree3(5, 2, 2), duree4(4, 31, 31);
    Duree resultat,resultat2,resultat3,resultat4;

    duree1.afficher();
    cout << "+" << endl;
    duree2.afficher();

    resultat = duree1 + duree2;

    cout << "=" << endl;
    resultat.afficher();

    cout << "-" << endl;
    resultat2 = duree1 - duree2;
    resultat2.afficher();

    cout << "Ici *" << endl;
    resultat3 = duree3 * duree4;
    resultat3.afficher();

    return 0;
}



