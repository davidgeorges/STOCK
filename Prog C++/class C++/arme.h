#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>

class Arme
{
    public:

    Arme();
    Arme(std::string nom, int degats);
    void swapS(std::string nameNewSword, int newSwordDamage);
    void afficher() const;
    int getDegats() const;

    private:

    std::string m_nom;
    int m_degats;
};

#endif
