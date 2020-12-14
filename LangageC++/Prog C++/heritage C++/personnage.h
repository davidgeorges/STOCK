#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Personnage
{
    public:
        Personnage(); // constructeur
        virtual ~Personnage(); // destructeur virtual car on donne l'héritage
        void recevoirDegats(int degats); // methode public
        void coupDePoing(Personnage &cible) const; // methode public constante

        virtual void affiche() const; // methodes virtuelles pour la résolution dynamique des liens

    private:
        int m_vie; // variable privée
        std::string m_nom;
};

#endif
