#include "crypt.h"

/*Passage paremetre par reference ( la variable chaine est une copier et acces direct a la variable passer )*/
void crypt(string &chaine1)
{

    for (int i = 0; i <chaine1.size(); i++)
    {
        chaine1[i] = chaine1[i] +848;
    }
    cout << chaine1 << endl;
}

/*Passage paremetre par reference */
void decrypt(string &chaine1)
{

    for (int i = 0; i <chaine1.size(); i++)
    {
        chaine1[i] = chaine1[i] -848;
    }
    cout << chaine1 << endl;
    

}
