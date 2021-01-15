#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAILLE 20


/*Prototype Fonction*/
int tailleChaine(char tab[]);

int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[TAILLE]=" ";
    char poub;
    char car;
    int i,vraiTaille,nbTrouver;
    int taille2;

    /*Saisie avec affichage*/
    printf("Veuillez saisier votre chaine de caractere : ");
    fgets(nom,TAILLE,stdin);
    //scanf("%s",nom);
    
    
    /*Saisie avec affichage*/
    printf("Veuillez saisir le caractere : ");
    scanf("%c",&car);

    /*Appel fontion pour avoir le taille de la chaine*/
    vraiTaille = tailleChaine(nom);
    printf("TAILLE 1 %d\n",vraiTaille);
    nbTrouver=0;

    /*on le compte le nombre de fois qu'ont a trouver la caractere chercher*/
    for ( i = 0; i <vraiTaille; i++)
    {
        if (nom[i] == car)
        {
            nbTrouver++;
        }
        
    }
    
    /*Affichage si on la trouver 1 fois ou non */
    if (nbTrouver>0)
    {
       printf("Nous avons trouver le caractere %d fois. \n",nbTrouver);
    }else
    {
        printf("Nous avons trouver le caractere 0 fois. \n");
    }
    

    return 0;
}



/*Fonction pour recuperer la taille de la chaine*/
int tailleChaine(char tab[])
{
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
    
    return i;
}