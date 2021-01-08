#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* Foncteur : la version objet des fonctions */

//Foncteur 1
class Pair{
public:
    
    int operator()(int a)   //La surcharge de l'opérateur ()
    {
        if(a%2 == 0){
            cout << "Valeur pair" << std::endl;
            return 1;
        }
        else{
            cout << "Valeur impair" << std::endl;
            return 0;
        }
    
    }
};

//Foncteur 2
class Remplir{
public:
    Remplir(int i)
        :m_valeur(i)
    {}

    int operator()()
    {
        ++m_valeur;
        return m_valeur;
    }

private:
    int m_valeur;
};

//Foncteur 3
class CompareLongueur
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a.length() < b.length();
    }
};

//Foncteur 4
class Compare
{
public:
    bool operator()(const int& a,const int&  b)
    {
        return a > b;
    }
};
//Predicats = foncteur qui prennent un parametre un renvoie un booleen

struct Fonctor1
{
    public:
    Fonctor1(int) : m_value(int)
    {}

    int operator()()
    {
        3*m_value;
        m_value++;
        return m_value;
    }
    int m_value;
};


//Fonction principale
int main(int argc, char const *argv[])
{
    Pair foncteur1;
    int a(2), b(3);
    foncteur1(a);


    vector<int> tab(100,0); //Un tableau de 100 cases valant toutes 0
    Remplir f(0);       //appel constructeur on initialise le compteur a 0
    for(vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        *it = f(); //On appelle simplement le foncteur sur chacun des éléments du tableau
        cout << *it;
    }
    cout <<"\n";

    sort(begin(tab), end(tab),Compare());//on trie le tableau avec notre foncteur Compare qui trie en decroissant
    for(vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        cout << *it;
    }
    cout <<"\n";


    //Utilisation d'un fonction comme critère de comparaison
    map<string, double,CompareLongueur> poids;  //On utilise le foncteur qui compare qui met dans l'odre de la plus petit chaine de caractere a la plus grande
    
    //On ajoute les poids de quelques animaux       
    poids["souris"] = 0.05;
    poids["tigre"] = 200;
    poids["chat"] = 3;
    
    //Et on parcourt la table en affichant le nom et le poids
    for(map<string, double>::iterator it=poids.begin(); it!=poids.end(); ++it)
    {
        cout << it->first << " pese " << it->second << " kg." << endl;
    }
    //sort(begin(poids), end(poids);

    return 0;
}

