#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void  comparerChaine(char tab[],char tab2[],int);

int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[TAILLE]=" ";
    char nom2[TAILLE]=" ";
    int taille;

    /*Saisie avec affichage*/
    printf("Veuillez saisire votre premiere chaine de caractere : ");
    fgets(nom,TAILLE,stdin);

    printf("Veuillez saisire votre deuxieme  chaine de caractere : ");
    fgets(nom2,TAILLE,stdin);


    /*Appel fonction pour avoir la taille de la chaine */
    taille = tailleChaine(nom);
    /*affichage avant appel fonction inverseChaine*/
    printf("Avant appel fonction : %s\n",nom);

    /*Appel fonction inverser la chaine avec affichage apres*/
    comparerChaine(nom,nom2,taille);


    return 0;   
}



/*Fonction pour recuperer la taille de la chaine*/
int tailleChaine(char tab[])
{
    /*Declaration variable*/
    int i =0;

    /*on incremente jusqu'a trouver le caractere de retour a la ligne ou qu'ont atteint la fin du tableau*/
    while (tab[i] != '\n' && i<= TAILLE && tab[i] != '\0') /* ou 0x0A */
    {
        i++;
    }



    /*si on a trouver le retour a la ligne on le remplace par le caractere de fin de chaine car on utilise fgets*/
    if (tab[i] == '\n')
    {
        tab[i] == '\0';
    }
    
    /*on retourne la taille*/
    return i;
}


/*Fonction pour inverser une chaine de caractere*/
void comparerChaine(char tab[],char tab2[],int taille){

    /*Declaration variable*/
    int i;
    int trouver = 0;

    /*i va valoir le debut et j la fin, du coup on permut les valeurs juqu'a que i croise j*/
    for (i=0;i<taille; i++)
    {   
        if(tab[i] == tab2[i]){
            trouver++;
        }
    }

    if (trouver == taille)
    {
        printf("Les chaines sont identiques ! ");
    }
    else
    {
        printf("Les chaines sont differentes ! ");
    }
   
}