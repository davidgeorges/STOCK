#include "PersonnagePointeur.h"

/* -------------------------------------- David Georges ------------------------------------- */

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(/* args */)
{
    vie = 100;
    name = "P1";
    m_arme = new Arme();// création d'un pointeur d'arme, on utilise new suivie du constructeur new Arme();
    mana = new int;//creation d'un pointeur de type int
    *mana = 152;//on affecte 15 a la valeur stocker dans l'adresse pointée
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(Personnage const& personnageACopier) : name(personnageACopier.name), vie(personnageACopier.vie), m_arme(0)
{
    m_arme = new Arme(*personnageACopier.m_arme);
    mana = new int (*personnageACopier.mana);
}

/* --------------------------------------------------------------------------------------------------------------------------- */
/*Destructeur on supprime les pointeur alloué */
Personnage::~Personnage()
{
    delete m_arme;
    delete mana;
    m_arme =0;
    mana =0;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
string Personnage::getName(){

    return name;//on retourne le nom comme il est en privé
}

/* --------------------------------------------------------------------------------------------------------------------------- */
string Personnage::getWeaponName(){
    
   return m_arme->getName();//on accede a la methode de l'arme crée pour récuperer son nom -> car m_arme est pointeur de type Arme
}

/* --------------------------------------------------------------------------------------------------------------------------- */
int Personnage::getWeaponDamage(){
    
   return m_arme->getDegats();//on accede a la methode de l'arme crée pour récuperer les degats -> car m_arme est pointeur de type Arme
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::changeWeaponDamge(int newDegats){

    m_arme->setDegats(newDegats);//on accede a la methode de l'arme crée pour change les degats -> car m_arme est pointeur de type Arme
}

/* --------------------------------------------------------------------------------------------------------------------------- */
int Personnage::getMana(){
    return *mana; //on retourne la valeur de mana , on met * devant car on retourne la valeur stocker dans l'adresse pointée
}

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::setMana(int x){
    *mana = x; //on change la valeur de mana , on met * devant car on retourne la valeur stocker dans l'adresse pointée
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage& Personnage::operator=(Personnage const& personnageACopier) 
{
    if(this != &personnageACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        vie = personnageACopier.vie; //On copie tous les champs
	delete m_arme;
    delete mana;
        m_arme = new Arme(*(personnageACopier.m_arme));
        mana = new int;
        *mana = *(personnageACopier.mana);
    }
    return *this; //On renvoie l'objet lui-même
}