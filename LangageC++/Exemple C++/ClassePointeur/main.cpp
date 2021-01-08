#include <iostream>
#include "PersonnagePointeur.h"
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
    Personnage p1,p2;
    
    cout <<"Nom p1 : " << p1.getName() << std::endl;
    cout <<"Nom p2 : " << p2.getName() << std::endl;
    
    cout << "Nom de l'arme p1 : "<< p1.getWeaponName() << std::endl;
    cout <<"Arme dmg p1 : "<<  p1.getWeaponDamage() << std::endl;
    cout <<"Arme dmg p2 : "  << p2.getWeaponDamage() << std::endl;
    cout <<"Changement des degats de l'arme de P1" << std::endl;
    p1.changeWeaponDamge(811);
    cout <<"Arme dmg p1: " << p1.getWeaponDamage() << std::endl;
    cout <<"Arme dmg p2 : " << p2.getWeaponDamage() << std::endl;
    cout <<"Changement du mana de  P1" << std::endl;
    cout << "P3 = P1" << std::endl;
    p1.setMana(455);
    Personnage p3(p1); // ou p3 = p1;
    cout <<"Mana pour p1 : " << p1.getMana() << std::endl;
    cout <<"Mana pour p3 : " << p3.getMana() << std::endl;
    cout <<"Arme dmg p1 : " << p1.getWeaponDamage() << std::endl;
    cout <<"Arme dmg p3 : " << p3.getWeaponDamage() << std::endl;
    cout <<"Nom p3 : " << p3.getName() << std::endl;
    cout <<"Changement des degats de l'arme de P1" << std::endl;
    p1.changeWeaponDamge(45);
    cout <<"Changement des degats de l'arme de P3" << std::endl;
    p3.changeWeaponDamge(81);
    cout <<"Arme dmg p1 : " << p1.getWeaponDamage() << std::endl;
    cout <<"Arme dmg p3 : " << p3.getWeaponDamage() << std::endl;
    cout <<"Changement du mana de  P3" << std::endl;
    p3.setMana(810);
    cout <<"Mana pour p1: " << p1.getMana() << std::endl;
    cout <<"Mana pour p3 : " << p3.getMana() << std::endl;

    return 0;
}



