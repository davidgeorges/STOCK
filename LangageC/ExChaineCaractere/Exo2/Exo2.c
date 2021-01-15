#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void transformMinMaj(char tab[],int);

int main(int argc, char const *argv[])
{
    char nom[TAILLE]=" ";
    int taille;

    /*Saisie avec affichage*/
    printf("Veuillez saisier votre chaine de caractere : ");
    fgets(nom,TAILLE,stdin);

    taille = tailleChaine(nom);

    printf("Avant appel fonction : %s\n",nom);

    transformMinMaj(nom,taille);

    printf("Apres appel fonction : %s\n",nom);


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
    
    /*on retourne la taille*/
    return i;
}

void transformMinMaj(char tab[],int taille){

    int i;

    for ( i = 0; i <taille; i++)
    {   
        /*si on a des minuscule on le change en majuscule*/
        if((tab[i]>='a') && (tab[i]<='z')){
            tab[i] -= 32;
            //tab[i] =tab[i] ^ 32;
        }else
        {   /*si on des majuscule on le change en minuscule*/
            if ((tab[i]>='A') && (tab[i]<='Z'))
            {   
                tab[i] += 32;
                //tab[i]= tab[i] ^ 32;
            }
            
        }
        
    }
    
}