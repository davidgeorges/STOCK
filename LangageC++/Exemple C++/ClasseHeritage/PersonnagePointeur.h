#ifndef DEF_PERSONNAGEPOINTEUR
#define DEF_PERSONNAGEPOINTEUR
#include "Arme.h"
//#include "Magicien.h"

class Personnage
{
protected://Privé, mais accessible aux éléments enfants (Guerrier, Magicien)
    Arme *m_arme;//Pointeur de type Arme
    int vie;
    string name;
    int *mana;//Pointeur de type intZ
    static int compteur;//variable static 
public:
    Personnage(/* args */);//constructeur par defaut*
    Personnage(int,string);//constructeur surchager
    Personnage(string);//constructeur surchager
    Personnage(int);//constructeur surchager
    Personnage(Personnage const& personnageACopier);//creation d'un constructeur de copie
    Personnage& operator=(const Personnage &personnage);//creation d'un deuxieme constructeur de copie avec operateur = 
    int nbInstance();//va retourne le nombre d'instance creer
    string getName(); //méthode pour avoir le nom du personnage
    string getWeaponName();//méthode pour avoir le nom  de l'arme
    virtual void sePresenter();/*méthode de masquage cette fonction a le même nom que celle de la classe guerrier mais n'affichage pas la même chose,
    une méthode virtuelle peut être redéfinie dans une classe fille, cette methode sera appeler lors de l'appel de la methode affiche(); */


    /*Si on met cette ligne on declare une méthode virtuelle pure, cette classe devient une classe abstraite et on ne pourra plus cree d'objet a partir de cette classe!
    virtual int nbrDamis() const = 0;
    une méthode virtuelle pure doit être redéfinie dans une classe fille sans le =0 , car sinon elle aussi deviennent des classe abstraite*/


    int getMana();//méthode pour avoir le nombre de mana
    int getVie();//méthode pour avoir le nombre de vie
    void setMana(int);//méthode pour  changer le nombre de mana
    void changeWeaponDamge(int);//méthode pour changer les degats de l'arme
    int getWeaponDamage();//méthode pour avoir les degats de l'arme
    void recevoirDegats(int);
    void coupDePoing(Personnage &cible) const;
    virtual ~Personnage();//destructeur virual car on utilise le polymorphisme
    
};

void affiche(Personnage &p);//Polymorphisme(résolution dynamique des liens,  utilise la bonne version de la fonction selon le personnage a l'aide d'une methode virtuelle et de passage par reference)



#endif