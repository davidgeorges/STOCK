#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef int T_FONCTION(int x);

T_FONCTION calculer_carre;
T_FONCTION calculer_int;




int main()
{
    int x, res, res1;
    T_FONCTION *ptr;
    printf("Veuillez ecrire un chiffre entier svp ! : ");
    scanf("%d", &x);
    ptr = calculer_carre;
    res = (*ptr)(x);
    printf("le resultat du carre de %d est %d \n",x, res);
    ptr = calculer_int;
    res = (*ptr)(x);
    printf("le reulstat de la racine carre de %d est %d", x ,res);



}



int calculer_carre (int x)
{
    return x*x;
}

int calculer_int (int x)
{
    return x*x-100;
}

