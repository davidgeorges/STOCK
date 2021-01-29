#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a=10,i;
    int tab[4] ={5,7,9,3};
    int *ptab;

    ptab = tab;
    
    for (i = 0; i <4; i++)
    {
        printf("La valeur de l'element %d vaut %d\n",i,*(ptab+i));
    }

    int aa =10;
    int *pta1;
    int **pta2;//pointeur de pointeur
    pta1=&aa;
    pta2=&pta1;
    

    /*affichage de l'adresse de aa de pta1 et pta2*/
    printf("Adresse de a %d \n",&aa);
    printf("Adresse de pta1 %d \n",&pta1);
    printf("Adresse de pta2 %d",&pta2);

    /*affichage de l'adresse de aa et a valeur pta1 et pta2 (affiche l'adresse pointée)*/
    printf("Adresse de la variable a  %d \n",&aa);
    printf("Adresse de la variable pointee  %d \n",pta1);
    printf("Adresse de la variable pointee  %d",pta2);
    

    /*affichage de la variable a et des valeurs pointée */
    printf("\nValeur de a %d \n",aa);
    printf("\nValeur de la variable pointee %d \n",*pta1);
    printf("Valeur de la variable pointee  %d",**pta2);

    
    return 0;
}
