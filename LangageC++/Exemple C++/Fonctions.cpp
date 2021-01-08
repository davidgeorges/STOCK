#include <iostream>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

/* double = valeur a retourner , carre = nom de la fonction , (double x ) = parametre a donner lors de l'appel a la fonction */
/* Le calcul sera effectuer avec la valeur passer en parametre , on peut avoir X parametre ! */
/* On peut appeler des fonctions dans une fonctions... */
/* On peut passer en paramatre des reference , pointeurs... */
double carre(double x); /*Ceci est le prototype de la fonction */




int main()
{
    double nombre, carreNombre;
    cout << "Entrez un nombre : ";
    cin >> nombre;

    carreNombre = carre(nombre); // on appel la fonction carre avec un parametre nombre
    /* a partir du nombre donner la fonction va caculer le carre de ce nombre et le renvoyer*/
    /* tout ça sera stocker dans la variable carreNombre (doit être du même type) */

    cout << "Le carre de " << nombre << " est " << carreNombre << endl;
    return 0;
}


double carre(double x)
{
  double resultat;
  resultat = x*x;
  return resultat;
}
