#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration variable et pointeur*/
    char c ='A';
    char *pt_c;

    /*Initialisation pointeur sur l'adresse de la variable c */
    pt_c = &c;

    /*Affichage */
    printf("Affichage par l'intermediare du pointeur pt_c a l'adresse pointee : [ %d ] , valeur [ %c ].",pt_c,*pt_c);


    
    return 0;
}