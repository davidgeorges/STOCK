#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Personnage
{
    public:
        Personnage(); // constructeur
        virtual ~Personnage(); // destructeur virtual car on donne l'h�ritage
        void recevoirDegats(int degats); // methode public
        void coupDePoing(Personnage &cible) const; // methode public constante

        virtual void affiche() const; // methodes virtuelles pour la r�solution dynamique des liens

    private:
        int m_vie; // variable priv�e
        std::string m_nom;
};

#endif
