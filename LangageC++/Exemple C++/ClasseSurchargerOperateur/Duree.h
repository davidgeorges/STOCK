#ifndef DEF_DUREE
#define DEF_DUREE


class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    Duree& operator+=(const Duree &duree);
    Duree& operator-=(const Duree &duree);
    Duree& operator*=(const Duree &duree);
    Duree& operator/=(const Duree &duree); // NON FONCTIONEL
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    void afficher() const;
    void affiche(ostream& out) const;  //Permet d'écrire la durée dans un flux , on écrira pas la fonction ceci est juste pour un exemple
    

    private:
    int m_heures;
    int m_minutes;
    int m_secondes;
    /*------------------------------- Amitié -------------------------------*/
    friend std::ostream& operator<< (std::ostream& flux, Duree const& duree);//notre operateur a accès a tout qui se trouve dans la classe Duree sans aucune restriction
    /*Il faut eviter a tout prix l'utilisation de l'amitié si c'est possible ! cela casse l'encapsulation qui est l'element le plus important en POO, on écrira pas la fonction ceci est juste pour un exemple */
};

Duree operator+(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, Duree const& b);
Duree operator*(Duree const& a, Duree const& b);
Duree operator/(Duree const& a, Duree const& b); // NON FONCTIONEL
bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
//Surcharge de l'opérateur << pour l'écriture dans les flux
//Utilise la méthode affiche() de Duree


#endif
