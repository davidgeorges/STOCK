#include <vector>
#include<deque>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> tableau(5,4);     //Un tableau de 5 entiers valant 4
    vector<int>::iterator it;     //Un itérateur sur un vector d'entiers
    map<string, int>::iterator it1; //Un itérateur sur les tables associatives string-int
    deque<char>::iterator it2; //Un itérateur sur une deque de caractères 
    list<double>::iterator it3; //Un itérateur sur une liste de nombres à virgule

    //Et on itère sur la deque
    for(it = tableau.begin(); it!=tableau.end(); ++it)//en gros it est un pointeur sur le premier element tu tableau donc sur les prochain element aussi
    {
        std::cout << *it << std::endl;    //On accède à l'élément pointé 
    }

    /*
    //si on a un iterateur sur un element on peut le supprimer via erase(), ou ajouter avec insert()
    Les random acess iterator
    vector<int>::iterator it = tab.begin() + 7; //Un itérateur sur le 8ème élément */

    return 0;
}
