#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12

/* David Georges , Code pour faire Entrer Deux nom caractere par caractere  dans deux tableaux et comparer si c'est le mêmes chaine de caracteres et Afficher le tableau*/

int main(int argc, char const *argv[])
{
    /* Declaration variable*/
    char tab1[N];// chaine de caractere possede un caractere de fin de chaine \0
    char tab2[N];
    int i,longueur1,longueur2,valid;
    
    /* Init*/
    valid =0;
    /* Saisie avec affichage*/
    printf("Veuillez saisir Votre premier nom !\n");
    scanf("%s",tab1);
    /* Saisie avec affichage*/
    printf("Veuillez saisir Votre deuxieme nom!\n");
    scanf("%s",tab2);

    /* Longeur du de la chaine tab1 et tab2*/
    longueur1 = strlen(tab1);
    longueur2 = strlen(tab2);

    /* si taille identique */
    if (longueur1==longueur2)
    {
        for( i=0; i<longueur1; i++)
        {
            if (tab1[i]==tab2[i])//Comparaison caractere par caractere
            {
                valid =1;   
            }else{
                valid =0;
            }
        }
    }else
    {
        printf("Desole Nom Different");
    }
    

    //Affichage si valid ou non
    if (valid)
    {
       printf("Excellent Nom identique");
    }else
    {
        printf("Desole Nom Different");
    }
    
}