#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
  //Déclaration d'un flux permettant d'écrire dans le fichier
  
  //Autre façon avec le nom du fichier dans une chaine de caracteres
  string const nomFichier("C:/Users/S/Desktop/STOCK/LangageC++/Exemple C++/Test.txt");
  ofstream monFluxW(nomFichier.c_str());

  /* On test si il n'y a pas d'erreur */
  if(monFluxW)  //On teste si tout est OK
  {
    //Tout est OK, on peut utiliser le fichier
    monFluxW << "Je suis une phrase dans le fichier" << endl;// on écrit dans le fichier
    monFluxW << 42.1337 << endl;// on écrit dans le fichier
    int age(23);
    monFluxW << "J'ai " << age << " ans." << endl; // on écrit la valeur de la varible dans le fichier
  }
  else
  {
  cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
  }
  /* Il y a différents type d'ouverture */
  int position1 = monFluxW.tellp();//connaitre la position actuel dans le fichier
  monFluxW.seekp(0, ios::beg);//On se déplace au debut du fichier
  monFluxW.close();//Fermeture du fichier

  ifstream monFluxR("C:/Nanoc/C++/data.txt");  //Ouverture d'un fichier en lecture
  //on fait les mêmes test qu'en haut pour voir si il y a des erreurs...
  /* Pour lire ligne par ligne on utilise getline(); */
  string ligne;
  getline(monFluxR, ligne);// on lit une ligne et on la stock dans ligne

  //Lire mot par mot
  double nombre;
  monFluxR >> nombre; //Lit un nombre à virgule depuis le fichier
  string mot;
  monFluxR >> mot;    //Lit un mot depuis le fichier

  monFluxR.ignore();        //Il faut changer de mode des qu'on passe de lecture de ligne a lecture de mot comme avec cin

  //Lire caractère par caractère 
  char a;
  monFluxR.get(a);//Cette méthode lit réellement tous les caractères. Les espaces, retours à la ligne et tabulations, elle seront stockes dans la variable...

  /* Lire un fichier en entier */
  if(monFluxR)
  {
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

    while(getline(monFluxR, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {
        cout << ligne << endl;
        //Et on l'affiche dans la console
        //Ou alors on fait quelque chose avec cette ligne
        //À vous de voir
    }
  }
  else
  {
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
  }

  /* Le curseur dans le fichier */
  int position2 = monFluxR.tellg();//connaitre la position actuel dans le fichier

  monFluxR.seekg(0, ios::end);//On se déplace à la fin du fichier
  int taille;
  taille = monFluxR.tellg();// on s'est positioner just avant a la fin du fichier
  //On récupère donc la position qui correspond a la taille du fichier !
  monFluxR.close();//Fermeture du fichier
  return 0;

}