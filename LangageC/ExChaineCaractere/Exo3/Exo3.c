#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void inverserChaine(char tab[],int);

int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[TAILLE]=" ";
    int taille;

    /*Saisie avec affichage*/
    printf("Veuillez saisier votre chaine de caractere : ");
    fgets(nom,TAILLE,stdin);

    /*Appel fonction pour avoir la taille de la chaine */
    taille = tailleChaine(nom);
    /*affichage avant appel fonction inverserChaine*/
    printf("Avant appel fonction : %s\n",nom);

    /*Appel fonction inverser la chaine avec affichage apres*/
    inverserChaine(nom,taille);
    printf("Apres appel fonction : %s\n",nom);


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
void inverserChaine(char tab[],int taille){

    /*Declaration variable*/
    int i,j,temp;

    /*i va valoir le debut et j la fin, du coup on permut les valeurs juqu'a que i croise j*/
    for (i=0, j=taille; i<j; i++,j--)
    {   
        temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
    }
    
}