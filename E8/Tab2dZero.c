#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 5
#define N C*L

/* David Georges , Code pour faire Initialiser un tableau et Afficher le tableau et tier les 0 a droite*/

int main(int argc, char const *argv[])
{
   //Declaration variable
    int tab2D[L][C];
    int sommeLigne[L],sommeColl[C];
    int i,j,k,sommeD,min,somme,permut;   
    
    /*Saisie valeur utilisateur dans tableau 2D */
    for ( i = 0; i <L; i++)
    {
        for ( j = 0; j < C; j++)
        {
            printf("Veuillez saisir une valeur\n");
            scanf("%d",&tab2D[i][j]);
        }
    }
    printf("\n");
    /*Affichage tableau 2D*/
    printf("Affichage avant Tri : \n");
    for (i = 0; i <L; i++)
    {
        for (j= 0; j <C; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }  




    /*Init permut*/
    permut=0;
    /*Recherche de 0 dans la boucle et permut valeur de gauche avec celle de droite */
    for (k= 0; k<N; k++)
    {
        for(i=0; i<L; i++)
        {
            for (j=0; j<C; j++)
            {
                if (tab2D[i][j] ==0) //si on trouve un 0
                {
                    printf("indice : %d | %d\n",i,j);
                    permut=tab2D[i][j+1];       //permut prend la valeur a droite de celle actuelle             
                    tab2D[i][j+1]=tab2D[i][j]; //la valeur de droite prend celle actuelle
                    tab2D[i][j]=permut; // et la valeur actuelle prend l'ancienne valeur de celle a droite
                    /* On echange la valeur de  droite avec celle actuelle dans la colonne j ( on le fait N * N fois) */ 
                }
            }
        }
    
    }
    
    /*Affichage tableau apres Tri des 0 */
    printf("Affichage apres Tri : \n");
    for (i = 0; i <L; i++)
    {
        for (j= 0; j <C; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }  

}
