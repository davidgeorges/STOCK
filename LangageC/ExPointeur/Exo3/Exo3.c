#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*Declaration variable et initialisation*/
    int i =15;

    /*Declaration pointeur*/
    int *ptr_i;

    /*Changement valeur et affichage*/
    ptr_i=&i;
    printf("Code 'ptr_i=&i;' Affichage de la variable pointee par ptr_i :  [ %d ]\n",*ptr_i);

    /**/
    *ptr_i=*ptr_i+10;
    printf("Code '*ptr_i=*ptr_i+10;' Affichage de la variable pointee par ptr_i :  [ %d ]\n",*ptr_i);

    /*Mauvaise methode *ptr_i++ ; */
    /*Bonne methode ++*ptr_i; ou (*ptr_i)++; */
    (*ptr_i)++;
    printf("Code '*ptr_i++;' Affichage de la variable pointee par ptr_i :  [ %d ]\n",*ptr_i);

    /*Mauvaise methode *ptr_i-- ; */
    /*Bonne methode  --*ptr_i; ou *(ptr_i)-- */
    --*ptr_i;
    printf("Code '--*ptr_i;' Affichage de la variable pointee par ptr_i :  [ %d ]\n",*ptr_i);

    
}