#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration Tableau*/
    int  A[ ] = {9, 15, 26, 28, 33, 45, 46 , 51, 52, 67} ; 

    /*Declaration pointeur*/
    int *ptr ;

    /*ptr prend l'adresse du première element du tableau*/
    ptr = A ;

    /*Affichage différente situation*/
    printf("Code 'ptr;' Affichage de la variable pointee par ptr :  [ %p ]\n",ptr);//Affichage de l'adresse pointée par ptr

    printf("Code 'ptr+1;' Affichage de la variable pointee par ptr :  [ %p ]\n",ptr+1);

    printf("Code 'ptr+2;' Affichage de la variable pointee par ptr :  [ %d ]\n",*ptr+2);//car ici c'est la valeur du première element + 2 donc = 11

    printf("Code '(ptr+2);' Affichage de la variable pointee par ptr :  [ %d ]\n",*(ptr+2));//Acces troisième element du tableau

    printf("Code '&A[4]–3 ;' Affichage de la variable pointee par ptr :  [ %p]\n",&A[4]-3 );

    printf("Code 'A+3;' Affichage de la variable pointee par ptr :  [ %p ]\n",A+3);

    printf("Code '& A[7] – ptr ;' Affichage de la variable pointee par ptr :  [ %d ]\n",& A[7]- ptr );

    printf("Code '*(ptr + *(ptr+8) – A[7]);' Affichage de la variable pointee par ptr :  [ %d ]\n", *(ptr + *(ptr+8) - A[7]) );
    

}