#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 10

/* David Georges , Code pour faire la Intialiser Tableau 2Dimension et Afficher le tableau*/

int main(int argc, char const *argv[])
{
    //Declaration variable
    int tab[N];
    int tab2D[N][M];
    int i,j,k;
    
    /*-------------Debut block tab1------------------------------------------------------*/
    //Initialiastion tableau 1
    printf("Affichage tab 1D :\n");
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < N; j++)
        {
            tab[j] =j+1;
        }
        
    }

    //affichage
    // affichage valeur tableau 2
     for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf("%d ",tab[i]);
        }
        printf("\n"); 
    }
    /*-------------Fin block tab1------------------------------------------------------*/

    /*-------------Debut block tabD2------------------------------------------------------*/
    //Initialiastion tableau 2d 
    printf("Affichage tab 2D :\n");
    for (i = 0; i <N; i++)
    {
        for (j= 0; j <M; j++)
        {
            tab2D[i][j] =j+1;
        }
        
    }

     for (i = 0; i <N; i++)
    {
        for (j= 0; j <M; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }
    /*-------------Fin block tab1------------------------------------------------------*/
    
    
}