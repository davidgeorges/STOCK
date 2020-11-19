#include "crypt.h"


void crypt(string &chaine1)
{

    for (int i = 0; i <chaine1.size(); i++)
    {
        chaine1[i] = chaine1[i] +848;
    }
    cout << chaine1 << endl;
}

void decrypt(string &chaine1)
{

    for (int i = 0; i <chaine1.size(); i++)
    {
        chaine1[i] = chaine1[i] -848;
    }
    cout << chaine1 << endl;
    

}
