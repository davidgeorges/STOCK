#include "PersonnagePointeur.h"

/* -------------------------------------- David Georges ------------------------------------- */

int Personnage::compteur = 0;//on doit initialiser dans l'espace global
/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(/* args */)
{
    cout << "herite de la" << std::endl;
    vie = 100;
    name = "P1";
    m_arme = new Arme();// création d'un pointeur d'arme, on utilise new suivie du constructeur new Arme();
    mana = new int;//creation d'un pointeur de type int
    *mana = 152;//on affecte 15 a la valeur stocker dans l'adresse pointée
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(int manaa,string nom){

    cout << "niveau mana" << std::endl;
    mana = new int;//creation d'un pointeur de type int
    *mana = manaa;
    name = nom;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(string nom){

    name = nom;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
Personnage::Personnage(int viee){

    cout << "niveau vie" << std::endl;
    vie = viee;
    mana = new int;//creation d'un pointeur de type int
    *mana = 999;
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
int Personnage::getVie(){
    return vie; //on retourne la valeur de mana , on met * devant car on retourne la valeur stocker dans l'adresse pointée
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

/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::recevoirDegats(int degats)
{
    vie -= degats;
}
 
/* --------------------------------------------------------------------------------------------------------------------------- */
void Personnage::coupDePoing(Personnage &cible) const
{
    cible.recevoirDegats(10);
}

/* --------------------------------------------------------------------------------------------------------------------------- */
//méthode de masquage cette fonction a le même nom que celle de la classeguerrier mais n'affiche pas la même chose
void Personnage::sePresenter(){

    cout << "Bonjour je m'apelle  " << name << std::endl;
}

/* --------------------------------------------------------------------------------------------------------------------------- */
//Polymorphisme(résolution dynamique des liens, utilise la bonne version de la fonction selon le personnage a l'aide d'une methode virtuelle et de passage par reference)
void affiche(Personnage  &p){

    p.sePresenter();
}

/* --------------------------------------------------------------------------------------------------------------------------- */
//va retourne le nombre d'instance creer
int Personnage::nbInstance(){
    return compteur;
}

void Personnage::test(){
    
    cout << " ceci est un test " << std::endl;
}