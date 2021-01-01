#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    /* Vector on peut ajouter des valeur seulement en fin */
    vector<int> tab(5,4); //Un tableau contenant 5 entiers dont la valeur est 4
    tab.pop_back();      //On supprime la dernière case du tableau.
    tab.push_back(6);    //On ajoute un 6 à la fin du tableau.
     
    for(int i(0); i<tab.size(); ++i){ //On utilise size() pour connaître le nombre d'éléments dans le vector
        cout << tab[i] << endl;      //On utilise les crochets [] pour accéder  aux éléments
    }

    /* D'autre exemple : a.swap(b); //On échange le contenu des deux tableaux. 
    //b a maintenant une taille de 8 et a une taille de 5. */

    /* List ,ne se parcourt qu'avec des itérateurs, list chainees, les elements ne sont pas ranger a coter dans la memoir chaque element contien un pointeur sur l'element suivant*/
    list<int> a; //Une liste de double
    if(a.empty())
        cout << "La liste est vide." << endl;
    else
        cout << "La liste n'est pas vide." << endl;

    liste.push_back(7);    //on ajoute 7 a la fin
    
    //On itère sur la liste
    for(list<int>::iterator it = liste.begin(); it!=liste.end(); ++it)
    {
        cout << *it << endl;
    }

    /* Pair */
    pair<int, double> p(2, 3.14);    //Une paire contenant un entier valant 2 et un nombre à virgule valant 3.14
    cout << "La paire vaut (" << p.first << ", " << p.second << ")" << endl;//On ne peut rien faire d'autre avec une paire. Elles servent juste à contenir deux valeur.


    /* Set */
    set<string> a; //Un ensemble de chaînes de caractères
    //Quelques actions…
    a.clear();  //Et on vide le tout !

    /* Deque on peut ajouter des element au deux extremiter*/
    deque<int> d(4,5); //Une deque de 4 entiers valant 5
    d.push_front(2);   //On ajoute le nombre 2 au début
    d.push_back(8);    //Et le nombre 8 à la fin

    /* Stack Last in firs out , le dernier element ajouter est celui en haut et le premier element et celui tout en bas des autres */
    stack<int> pile;    //Une pile vide
    pile.push(3);       //On ajoute le nombre 3 à la pile
    pile.pop();        //On supprime le dernier élément ajouté (

    /* Queue premier a rentrer , premier a sortir*/
    

    /* Priotiry_queue c'est un queue qui ordonnent leur elements , la plus grosse valeur est au dessus(en premier) */
    priority_queue<int> file;
    file.push(5);
    file.top()//affiche le plus grand element inserer

    /* Table associatives */
    /* Map, ne se parcourt qu'avec des itérateurs, les éléments sont triés selon leur clé,on parcourt les clés de la plus petite à la plus grande */
    map<string, double> poids; //Une table qui associe le nom d'un animal à son poids
    //On ajoute les poids de quelques animaux
    poids["souris"] = 0.05;//la case souris vaut 0.05
    poids["tigre"] = 200;
    poids["chat"] = 3;
    poids["elephant"] = 10000;// la case elephant vaut 10000

    map<string, double>::iterator trouve = poids.find("chien");//on a un iterateur sur le tableau et la case "chien"

    if(trouve == poids.end())
    {
        cout << "Le poids du chien n'est pas dans la table" << endl;
    }
    else
    {
        cout << "Le chien pese " << trouve->second << " kg." << endl; // trouve->second ( la case a coter de chien donc le poids)
    }


    /* Set,ne se parcourt qu'avec des itérateurs, Les setsont utilisés pour représenter les ensembles. On peut insérer des objets dans l'ensemble et y accéder via une méthode de recherche.
    Par contre, il n'est pas possible d'y accéder via les crochets. En fait, c'est comme si on avait unemapoù les clés et les éléments étaient confondus.*/

    /* Multiset Multimap */
    /* Les multiset et multimap sont des copies des setet mapoù chaque clé peut exister en plusieurs exemplaires */

    return 0;
}
