#include <stdio.h>
#include <stdlib.h>

#define N 3


void inverseTab2D(int *pt_a2D);

int main(int argc, char const *argv[])
{
    /*Declaration variable et initialisation*/
    int A[N][N] ;
    int i =0;

    /*Declaration pointeur*/
    int *pt_a;


    /*Affectation adresse au pointeur*/
    pt_a= &A[0][0];


    /*On met la valeur du tableau A a l'envers dans la tableau B */
    for(i =0; i<N*N; i++){
        *(pt_a+i) = i+1;
    }
    


    /*Affichage des deux tableaux */
    printf("Affichage tableau A : [ | ");
    for(i =0; i<N*N; i++){
        printf("%d | ",*(pt_a+i));
    }
    printf("]\n");

    inverseTab2D(pt_a);

    /*Affichage des deux tableaux */
    printf("Affichage tableau A : [ | ");
    for(i =0; i<N*N; i++){
        printf("%d | ",*(pt_a+i));
    }
    printf("]\n");



    
}


void inverseTab2D(int *pt_a2D){

    /*Declaration Variable*/
    int permut;


    /*Inversement tableau 2D a l'aide de pointeur sur tableau et valeur permut*/
    for(int i =0; i<N; i++){
        permut = *(pt_a2D+i);
        *(pt_a2D+i) = *(pt_a2D+N*N-i-1) ;
        *(pt_a2D+N*N-i-1) = permut;
    }
}