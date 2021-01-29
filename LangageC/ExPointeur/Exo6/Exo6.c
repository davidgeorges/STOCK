#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration variable et initialisation*/
    int A [] = {-3, 4, 0, -7, 3, 8, 0, -1, 4, -9};
    int B [] = {0, 0, 0, 0, 0, 0, 0, 0, 0,0};
    int i =0;

    /*Declaration pointeur*/
    int *pt_a;
    int *pt_b;

    /*Affectation adresse au pointeur*/
    pt_a=A;
    pt_b=B;

    /*On met la valeur du tableau A a l'envers dans la tableau B */
    for(i =0; i<10; i++){
        *(pt_b+i) = *(pt_a+9-i);
    }
    


    /*Affichage des deux tableaux */
    printf("Affichage tableau A : [ | ");
    for(i =0; i<10; i++){
        printf("%d | ",*(pt_a+i));
    }
    printf("]\n");

    printf("Affichage tableau B : [ | ");
    for(i =0; i<10; i++){
        printf("%d | ",*(pt_b+i));
    }
    printf("]\n");



    
}