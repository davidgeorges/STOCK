#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void  compterOccurence(char nom[],int);
void initTab(int tab[]);
void trouverCarac(char nom);

int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[TAILLE]=" ";
    char nom2[TAILLE]=" ";
    int taille;

    /*Saisie avec affichage*/
    printf("Veuillez saisire votre premiere chaine de caractere : ");
    fgets(nom,TAILLE,stdin);

    /*Appel fonction pour avoir la taille de la chaine */
    taille = tailleChaine(nom);
    /*affichage avant appel fonction inverseChaine*/
    printf("Avant appel fonction : %s\n",nom);

    /*Appel fonction inverser la chaine avec affichage apres*/
    compterOccurence(nom,taille);


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
void compterOccurence(char nom[],int taille){
   
    /*Declaration variable*/
    int tab[26];

    /*Appel fonction initTab*/
    initTab(tab);

    for (int i = 0; i <taille; i++)
    {
        
        
    }
    

}

/*Fonction initialiser tableau a 0*/
void initTab(int tab[]){
    
    for (int i = 0; i <26; i++)
    {
        tab[i] =0;
    }
    
}


/*Fonction pour trouver un caractere*/
void trouverCarac(char nom[]){

}