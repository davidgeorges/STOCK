#include <iostream>
using namespace std;

template <typename T>
class Rectangle{
    public:
    Rectangle(T gauche, T droite, T haut, T bas) : m_gauche(gauche),m_droite(droite),m_haut(haut),m_bas(bas)//utilisation constructeur avec template
    {}

    T hauteur() const
    {
      return m_haut-m_bas;
    }
    

    private:
   
   //Les côtés du Rectangle
   T m_gauche;
   T m_droite;
   T m_haut;
   T m_bas;

};


//template qui retourne la plus grande valeur
template <typename T>
T maximum(const T& a,const T& b)
{
   if(a>b)
      return a;
   else
      return b;
}

//template qui prend deux different argument , un certain type de tableau et un certain type de moyenne , car si on a des int en tableau et en int la moyenne sera arrondie vers le bas , donc utilisation de deux type
template <typename T,typename S>
S moyenne(T tableau[], int taille)
{
    for (int j= 0; j < 5;j++)
    {
        tableau[j] =j+1;
    }

    S somme(0);
    for (int i(0); i <taille; i++)
    {
        somme = somme + tableau[i];
    }
    
    cout << somme;
    cout << "\n";
    return somme/taille;
    
}


int main()
{
     double pi(3.14);
     double e(2.71);

     cout << maximum<double>(pi,e) << endl; //Utilise la "version double"de la fonction, type template entre <>

     int cave(-1);
     int dernierEtage(12);

     cout << maximum<int>(cave,dernierEtage) << endl; //Utilise la "version int" de la fonction, type template entre <>

     unsigned int a(43);
     unsigned int b(87);

     cout << maximum<unsigned int>(a,b) << endl; //Utilise la "version unsigned int" de la fonction, type template entre <>

    int tab[5];
    
    cout << "Moyenne : " << moyenne<int,double>(tab,5) << endl;//template T = int , template S  = double

    Rectangle<double> monRectangle(1.0, 4.5, 3.1, 5.2);//Objet ,utilisation du constructeur avec un type de notre choix entre <> ( les valeur varie selon le type choisi)

    cout << monRectangle.hauteur() << endl;

     return 0;
}