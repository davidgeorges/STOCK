#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration variable et initialisation*/
    int x = 1 ;
    int y = 2 ;
    /*Declaration pointeur*/
    int *p;
    int **pp ; //Pointeur de pointeur

    /*Affectation valeur/adresse*/
    p = &x ;


    /*Changement valeur et affichage*/
    printf("Code 'p = &x ;' Affichage de la variable pointee par ptr :  [ %d ]\n",*p);

    /**/
    x = x + y;
    printf("Code 'x = x + y;' Affichage de la variable pointee par ptr :  [ %d ]\n",*p);

    /**/
    
    printf("Code 'pp = &p ;' Affichage de la variable pointee par ptr :  [ %d ]\n",**pp);

}