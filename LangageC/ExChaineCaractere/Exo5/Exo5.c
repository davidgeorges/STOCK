#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 50
#define TAILLE2 26

int k =0;

/*Prototype Fonction*/
int tailleChaine(char tab[]);
void compterOccurence(char nom[],int,int,int tab[],int);
void initTab(int tab[]);


int main(int argc, char const *argv[])
{
    /*Declaration variable*/
    char nom[TAILLE]=" ";
    char nom2[]="abcdefghijklmnopqrstuvwxyz";
    int tab[TAILLE2];
    int taille;
    char car=96;

    /*Saisie avec affichage
    printf("Veuillez saisire votre premiere chaine de caractere : ");
    fgets(nom,TAILLE,stdin);*/

    /*Appel fonction pour avoir la taille de la chaine */
    taille = tailleChaine(nom2);
    /*affichage avant appel fonction inverseChaine
    printf("Avant appel fonction : %s\n",nom);*/

    initTab(tab);

    /*Appel fonction inverser la chaine avec affichage apres*/
    compterOccurence(nom2,97,0,tab,taille);


    printf("Avant appel fonction : %s\n",nom2);

    for (int i = 0; i < TAILLE2; i++)
    {   
        car++;
        printf("Element '%c' trouver [%d] fois \n",car,tab[i]);
    }
    


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
void compterOccurence(char nom[],int carTrouver,int comptTab2,int tab[],int taille){
    /*Declaration variable*/
    int i =0;
    
    /*si le compteur allant jusqu'a 26 atteint (25) on arrete la fonction avec le return*/
    if (comptTab2<TAILLE2)
    {
        /*on compare le caractere a trouver avec notre tableau*/
        while (i<taille)
        {   /*si on a trouver l'element*/
            if (nom[i] == carTrouver)
            {
                tab[comptTab2]++;
                //printf("compt : %d\n",comptTab2);
            }
            i++;
        }
        
        /*on rappel la fonction avec un nouveau caractere a trouver et on incrementant le compteur pour effectuer 25 iterrations*/
        compterOccurence(nom,carTrouver+1,comptTab2+1,tab,taille);
    }else
    {
        return;
    }
    
}

/*Fonction initialiser tableau a 0*/
void initTab(int tab[]){
    
    for (int i = 0; i <TAILLE2; i++)
    {
        tab[i] =0;
    }
    
}


