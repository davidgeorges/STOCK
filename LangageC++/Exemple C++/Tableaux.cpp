#include <iostream>
#include <vector>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
  /* Tableau statique */  
  int meilleurScore[3];       //Déclare un tableau de 5 int 

  /* Tableau avec delclaration de la taille au préalable */
  int const tailleTableau(20);   //La taille du tableau
  double num[tailleTableau];

  /* Accédez aux éléments d'un tableau */
  meilleurScore[0] = 118;  //Remplissage de la première case
  meilleurScore[1] = 102;  //Remplissage de la deuxième case 
  meilleurScore[2] = 177;   //Remplissage de la troisième case 

  /* Parcourir un tableau */
  for(int i(0); i<3; ++i)
  { 
    cout << meilleurScore[i] << endl;
  }

  /* Tableau et Fonction */
  void fonction(double tableau[]);//Prototype de fonction avec un tableau en parametre
  /* Appel de la fonction dans une autre = fonction(nomDuTableau) */

/*--------------------------------------- Les tableaux dynamiques ---------------------------------------*/
                                  /* La taille des tableau peut varier */

  /* si un tableau est suspectible de varuer crée un tableau dynamique de type vector */
  vector<int> tableau1(3);  /* Tableau de  3 eniters non initialiser */
  vector<int> tableau2(5,3);  //Crée un tableau de 5 entiers valant tous 3
  vector<string> listeNoms(6, "Sans nom"); //Crée un tableau de 6 strings valant toutes « Sans nom »            
  vector<double> tableau; //Crée un tableau de 0 nombre à virgule

  /* Accédez aux éléments d'un tableau */
  tableau2[0] = 845; /* maintenant la première case de ce tableau vaut 845 */

  /*Changez la taille */
  tableau2.push_back(8);/* on rajoute une 6éme case sachant que ce tableau a une taille de 5 au debut, 
  on y ajoute la valeur 8 a la fin */
  tableau2.pop_back(); // on supprime la derniere case du tableau 

/*--------------------------------------- Les tableaux multi-dimensionnels ---------------------------------------*/
  int tableau3[5][4];//tableau a deux dimensions (ligne,cologne) (tableau de 20 entier 5*4)
  tableau3[0][0];//première ligne et cologne du tableau 
  tableau3[0][1];//première ligne et deuxieme cologne du tableau
  tableau3[1][0];//deuxieme ligne etpremiere cologne du tableau
  /*on peut avoir des tableaux a 3,4,5 dimensions...*/
  /* Possible d'en avoir avec des vector */

/*Rappel les strings sont des tableaux de caracteres */
string nom("Dav");
// chaine3 = chaine1 + chaine2; // 3... 2... 1... Concaténatioooooon
// cout << chaine3 << endl; ( chaine 3 = le texte de la chaine 1 + le texte de la chaine 2)
// c_str() = pointeur  vers tableau de char vous permet de récupérer l'adresse du tableau de char qui se trouve à l'intérieur de l'objet string

nom[0]; // = D
nom[2]; // = v

  return 0;
}