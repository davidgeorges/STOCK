#ifndef DEF_DUREE
#define DEF_DUREE

#include <iostream>
#include <string>

// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
// NOT ALL OPERATOR - NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -NOT ALL OPERATOR -
using namespace std;
/*----------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------------------------------------------------------------------------------------------*/
class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    Duree();
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    bool estPlusGrandQue(Duree const& b) const;
    bool estPlusGrandOuEgal(Duree const& b) const;
    Duree& operator+=(Duree const& a);
    void afficher() const;
    void afficher(std::ostream &flux) const;

    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
    int res_minutes;
    int res_secondes;
};

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator>=(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);
ostream& operator<<( ostream &flux, Duree const& duree );


#endif
