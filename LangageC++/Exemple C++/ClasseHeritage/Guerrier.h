#ifndef DEF_GUERRIER
#define DEF_GUERRIER
#include "PersonnagePointeur.h"

class Guerrier : public Personnage
{
private://Aucune varible ici car elle sont en protected dans la classe personnage donc ont peut directement les utiliser 
public:
    Guerrier(int);
    Guerrier(string);
    virtual void sePresenter();//méthode de masquage cette fonction a le même nom que celle de la classe personnage mais n'affiche pas la même chose
    virtual ~Guerrier();//destructeur virual car on utilise le polymorphisme
    virtual int nbrDamis() const;//i
    //string getName();
};






#endif