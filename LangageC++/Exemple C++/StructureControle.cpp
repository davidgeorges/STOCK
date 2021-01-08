#include <iostream>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
    int nbFruit(0);

    /* Structure de controle */
    if (nbFruit > 0)
    {
      cout << "Vous avez des fruits dans votre panier." << endl;
    }
    else if(nbFruit == 0)
    {
      cout << "Vous avez 0 fruits dans votre panier. " << endl;
    }
    else
    {
      cout << "Vous avez des  fruits manquants dans votre panier. " << endl;
    }
    
    /* Nous avons aussi le switch pour ne pas repeter de nombre if,else if... */

     switch (nbFruit)
    {
        case 0:
            cout << "Vous avez 0 fruits dans votre panier. " << endl;
            break;

        case 1:
            cout << "Vous avez 1 fruit dans votre panier." << endl;
            break;

        case 2:
            cout << "Vous avez 2 fruit dans votre panier." << endl;
            break;

        default:
            cout << "Desoler aucune condition programmer pour votre réponse" << endl;
            break;
    }
    cout << "Fin." << endl;

    /* Condition plus complexe avec les && (ET) , || (OU), ! (NON) */

    /* Les boucles */
    while (nbFruit !=0)
  {
    /* Instructions à répéter tant que la condition est vrai*/
    /* A utiliser quand on ne connait pas le nombre d'ittération a faire */
  }

  do
  {
    /* Instructions à répéter tant que la condition est vrai*/
    /* A utiliser quand on ne connait pas le nombre d'ittération a faire */

  } while (nbFruit);
  
  for (size_t i = 0; i <nbFruit; i++)
  {
    /* Instructions à répéter tant que la condition est vrai*/
    /* A utiliser quand on connait  le nombre d'ittération a faire */
  }
  
    return 0;
}