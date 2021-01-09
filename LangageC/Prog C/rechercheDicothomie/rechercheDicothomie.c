#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define MAX 10000
#define MIN 1


/*------------------------------------------- Georges David , 08/01/2021 -------------------------------------------*/

/*  Recherche pas dicothomie  si la valeur recherche est plus grande que la valeur du milieu on divise le tableau en changeant le debut en le mettant au milieu du tableau  
    si la valeur recherche est plus petite que la valeur du milieu on divise le tableau en changeant la fin en la mettant au milieu du tableau    */ 

/*------------------------------------------------------------------------------------------------------------------*/

void recherche(int tab[]);
void initTab(int tab[]);
void afficheTab(int tab[]);
void triTab(int tab[]);

int main(int argc, char const *argv[])
{
    /*Initialisation srand*/
    srand(time(NULL));
    /* Declaration variable */
    int tab[N];

    /*Appel fonction*/
    initTab(tab);/*On initialise le tableau d'abord avec des valeur aleatoire*/
    triTab(tab);/*On le tri on ordre croissant sinon on ne peut pas rechercher une valeur avec la méthode par dicothomie*/
    afficheTab(tab);/*On affiche les valeur du tableau */
    recherche(tab);/*Le tri croissant est effectuer quand on appel cette fonction, on saisie la valeur a rechercher et on la trouve si elle est présente */ 

    return 0;
}

void initTab(int tab[]){

    /* Initialisation du tableau avec des valeur aleatoire */
    for (int i = 0; i < N; i++)
    {
        /* on stock le nombre generer entre MIN et MAX */
        int nbMystere = rand() % (MAX - MIN +1) + MIN; // min + rand( (val-min+1)) val = MAX
        tab[i] = nbMystere;
    }
}

void afficheTab(int tab[]){
    /*Affichage du tableau*/
    for (int i = 0; i < N; i++)
    {
        printf("Element rang %d : %d \n",i,tab[i]);
    }
}

/*Tri du tableau en ordre croissant pour effectuer la recherche pas Dicothomie */

void triTab(int tab[]){

    int permut;

    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (tab[i]>tab[j]) // si i > i+1 si ( 10 > 5 ) permut et ensuite remonter dans la boucle et ressayer avec la valeur suivante...
            {     
                //printf("%d > %d", tab[i],tab[i+1]); //pour le fonctionnement
                //printf("\t");
                permut = tab[i];
                tab[i] = tab[j];
                tab[j] = permut;    
            }
        }
    }
}

void recherche(int tab[]){

    int trouver,fin,debut,milieu,i,valRechercher;

    /*Saisie avec affichage*/
    printf("Veuillez ecrire la valeur a rechercher : ");
    scanf("%d",&valRechercher);

    /*Initialisation variable*/
    i=0;
    trouver =0;
    debut =0;
    fin = N-1;

    while ((trouver==0) && (debut <=fin))
    {
        milieu = ((debut+fin)/2);
        
        if (tab[milieu]==valRechercher)
        {
            trouver=1;/*si la valeur est trouver*/
        }else
        {
            /*si la valeur recherche est plus grane que la valeur au milieu elle sera obligatoirement a droite tu tableau  et on refait la manip ,
            donc la fin debut et milieu changeront a chaque fois.
            si la valeur recherche est plus petite que la valeur au milieu elle sera obligatoirement a gauche du tableau et on refait la manip ,
            donc la fin debut et milieu changeront a chaque fois. selon la condition plus gande ou plus petite */
            if (tab[milieu]<valRechercher)
            {
                debut=milieu+1;
            }else
            {
                fin = milieu-1;
            }
        }

        i++;
    }

    /*Affichage si on la trouver  ou non*/
    if (trouver)
    {
        printf("La valeur %d est trouver en %d iteration en position %d \n",valRechercher,i,milieu);
    }else
    {
         printf("La valeur %d n'est pas dans le tableau ! \n",valRechercher);
    }
    
    
}
