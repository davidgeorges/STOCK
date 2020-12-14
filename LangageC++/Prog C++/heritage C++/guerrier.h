#ifndef DEF_GUERRIER
#define DEF_GUERRIER

#include <iostream>
#include <string>
#include "Personnage.h"
//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !

class Guerrier : public Personnage
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
    public:
        Guerrier();
        virtual ~Guerrier();

        virtual void affiche() const; // methodes virtuelles pour la résolution dynamique des liens

    private:
        int m_vie;
        std::string m_nom;


};

#endif
