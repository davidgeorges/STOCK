#ifndef DEF_CLASSE2
#define DEF_CLASSE2

#include <iostream>
#include <string>
using namespace std;
 
class Arme
{
    public:
 
    Arme();
    Arme(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    int getDegats() const;
 
    private:
    std::string m_nom;
    int m_degats;
};
 
#endif