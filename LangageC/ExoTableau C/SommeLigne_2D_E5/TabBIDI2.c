#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 5

/* David Georges , Code pour faire Initialiser un tableau et Afficher le tableau*/

int main(int argc, char const *argv[])
{
    //Declaration variable
    int tab2D[L][C];
    int sommeLigne[L],sommeColl[C];
    int i,j,k,sommeD,min,somme;   
    
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
    for (i = 0; i <L; i++)
    {
        for (j= 0; j <C; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }  
    
    /*Exercice A Fonctionne*/
    for ( i = 0; i < L; i++)
    {
        sommeLigne[i] = 0;
    }
    /*Calcule somme tableau 2D */
    for (i = 0; i <L; i++)
    {
        for (j= 0; j <C; j++)
        {
            sommeLigne[i] = sommeLigne[i] +tab2D[i][j];
        }
        
    }
    for (i = 0; i <L; i++)
    {
        printf("La somme de la ligne %d vaut %d\n",i,sommeLigne[i]);
    }
    
    


    /*Exercice B Fonctionne*/
    /*Init*/
    i =0;   
    /*On prend un compteur jusqu'au nombre de ligne, somme en diagonale donc pour un tab de 3 ligne on va prendre [0][0] ensuite [1][1] et [2][2]*/
    
    /*Pour ne pas depasser
    sommeD=0;
    min =L;
    if(C<L){
        min =C; //si on ne fait pas ce code on sortir de la diago avec si L a une valeur trop grande
    }
    for (i = 0; i <min; i++)
    {
        /*Donc on veut la valeur de la case  [0][0],[[1][1],[2][2]
        sommeD = sommeD +tab2D[i][i];
    }
    printf("La somme de tout les elements valent  en Diago: %d\n",sommeD);
    */

   

   /*Exercice C Fonctionne*/
   /*Init*/
    /*
    for ( i = 0; i < L; i++)
    {
        //sommeColl[i] = 0;
    }
    /*On parcours les colo ensuite ligne
   k=0;    
    for (j = 1; j <C; j=j+2) // J = 1 ou 0 a changer selon...
    {
        for (i= 0; i <L; i++)
        {
                sommeColl[k] = sommeColl[k] +tab2D[i][j];
                printf("%d\n",j);

        }
        k++;/*k pour ne pas laisser des 0 au col pair
    }
    for (i = 1,k=0 ; i <C; i=i+2,k++) /* J = 1 ou 0 a changer selon...
    {
        printf("La somme de la col %d vaut %d\n",i,sommeColl[k]);
    }*/
    

   /*Exercice D Non fonctionnel*/
   /*Init*/
   somme=0;
   /*On parcours le tableau , si j%2==0 c'est qu'on est sur la bonne colone dans on fait la somme */
    /* si Col pair */
    if(C%2==0)
    {
        for (i = 0; i <L; i++)
        {
            for (j= 0; j<C; j=j+2)
            {
                somme = somme +tab2D[i][j];
                printf("on prend ici 1 %d\n",tab2D[i][j]);
            }
        }
    }else
    {
        for (i = 0; i <L; i++)
        {
            for (j=0,k=0; j<C; j++,k=k+2)
            {
                if ((i%2)==0 && (k<=C))
                {
                    somme = somme +tab2D[i][k];
                    printf("on prend ici 2 %d \n",tab2D[i][k]);
                    
                }
                if((j%2)!=0 && (i%2)!=0)
                {
                    somme = somme +tab2D[i][j];
                    printf("on prend ici 3 %d\n",tab2D[i][j]);
                }
                
            }
        }
    }

    printf("La somme de tout les elements valent : %d\n",somme);
    

}