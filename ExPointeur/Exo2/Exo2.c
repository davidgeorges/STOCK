#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration variable et pointeur*/
    float a;
    float *pt_a;

    /*Initialisation valeur de a et pointeur sur l'adresse de la variable a */
    a = 10;
    pt_a = &a;

    printf("Affichage par l'intermediare du pointeur pt_a , l'adresse pointee : [ %d ] , valeur : [ %2.f ].\n",pt_a,*pt_a);

    /* changement valeur en manipulant le pointeur */
    *pt_a = *pt_a /5;

    /* Affichage apres manipulation a l'aide du pointeur */
    printf("Affichage apres manipulation du pointeur  pt_a , adresse pointee : [ %d ]  et valeur final : [ %2.f ].",pt_a,*pt_a);


    
    return 0;
}