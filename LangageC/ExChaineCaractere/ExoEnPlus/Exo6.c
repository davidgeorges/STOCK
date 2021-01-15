#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void  compterLe(char nom[],int);


int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[]="Bonjour tout le monde, le soleil brille";
    int taille;

    /*Appel fonction pour avoir la taille de la chaine */
    taille = tailleChaine(nom);
    /*affichage avant appel fonction inverseChaine*/
    printf("Avant appel fonction : %s\n",nom);


    /*Appel fonction inverser la chaine avec affichage apres*/
    compterLe(nom,taille);



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


/*Fonction compter le fois de "Le" dans une chaine de caractere*/
void compterLe(char tab[],int taille){
   
    int nbr=0;
    int k = 1;
    int i =0;
    /*Appel fonction initTab*/

    while (tab[i] !='\0')
    {
        if(tab[i] =='l' && tab[k] =='e'){
            nbr++;
            printf("trouver a %d et %d  \n",i,i+1);
        }
        i++;
        k++; 
    }
    
    if (nbr>0)
    {
        printf("Nous avons trouver 'le' %d fois.",nbr);
    }else
    {
        printf("'le n'est pas présent dans votre chaine de caractere.");
    }
    
    

}
