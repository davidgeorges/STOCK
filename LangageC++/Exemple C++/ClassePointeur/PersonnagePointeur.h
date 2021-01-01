#ifndef DEF_PERSONNAGEPOINTEUR
#define DEF_PERSONNAGEPOINTEUR
#include "Arme.h"

class Personnage
{
private:
    Arme *m_arme;//Pointeur de type Arme
    int vie;
    string name;
    int *mana;//Pointeur de type int
public:
    Personnage(/* args */);//constructeur par defaut
    Personnage(Personnage const& personnageACopier);//creation d'un constructeur de copie
    Personnage& operator=(const Personnage &personnage);//creation d'un deuxieme constructeur de copie avec operateur = 
    string getName(); //méthode pour avoir le nom du personnage
    string getWeaponName();//méthode pour avoir le nom  de l'arme
    int getMana();//méthode pour avoir le nombre de maan
    void setMana(int x);//méthode pour  changer le nombre de mana
    void changeWeaponDamge(int);//méthode pour changer les degats de l'arme
    int getWeaponDamage();//méthode pour avoir les degats de l'arme
    ~Personnage();
};




#endif