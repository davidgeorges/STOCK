#include <iostream>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
  int ageUtilisateur(16);
  //Une variable de type int
  int *ptr(0);
  //Un pointeur pouvant contenir l'adresse d'un nombre entier
  ptr = &ageUtilisateur;
  //On met l'adresse de 'ageUtilisateur' dans le pointeur 'ptr'
  cout << *ptr; // Affiche la valeur qui est a l'adresse pointée ( donc la valeur de ageUtilisateur )

  /* Allocation dynamique */
  int *pointeur(0);
  pointeur = new int; // on demande manuelleemnt une case dans la mémoire et on renvoie un pointeur vers cette case
  *pointeur = 2;  //On accède à la case mémoire pour en modifier la valeur
  delete pointeur;  //!!!!!!!!!!!!!!!! Il ne faut pas oublier de libèrer la case mémoire des qu'on a plus besoin de la variable !!!!!!!!!!!!!!!!
  pointeur = 0; // Et indiquer que le pointeur ne pointe plus vers rien

  /* Quand utiliser des pointeurs 

  -- 1 gérer soi-même le moment de la création et de la destruction des cases mémoire ;

  -- 2 partager une variable dans plusieurs morceaux du code ;

  -- 3 sélectionner une valeur parmi plusieurs options.
  
  Si vous n'êtes dans aucun de ces trois cas, c'est très certainement que vous n'avez pas besoin des pointeurs.
  */

  return 0;
}



/* Exemple  pour la 3

    string reponseA, reponseB, reponseC;
    reponseA = "La peur des jeux de loterie";
    reponseB = "La peur du noir";
    reponseC = "La peur des vendredis treize";

    cout << "Qu'est-ce que la 'kenophobie' ? " << endl; //On pose la question
    cout << "A) " << reponseA << endl; //Et on affiche les trois propositions
    cout << "B) " << reponseB << endl;
    cout << "C) " << reponseC << endl;

    char reponse;
    cout << "Votre reponse (A,B ou C) : ";
    cin >> reponse; //On récupère la réponse de l'utilisateur

    string *reponseUtilisateur(0); //Un pointeur qui pointera sur la réponse choisie
    switch(reponse)
    {
    case 'A':
        reponseUtilisateur = &reponseA; //On déplace le pointeur sur la réponse choisie
        break;
    case 'B':
        reponseUtilisateur = &reponseB;
        break;
    case 'C':
        reponseUtilisateur = &reponseC;
        break;
    }

    //On peut alors utiliser le pointeur pour afficher la réponse choisie
    cout << "Vous avez choisi la reponse : " << *reponseUtilisateur << endl;

    return 0;
    
*/