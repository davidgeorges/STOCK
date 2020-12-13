#include <stdio.h>
#include <stdlib.h>
#define N 240

/* David Georges , Code pour faire Trier les  d'un tableau et les mettre a droite et Afficher le tableau*/

int main(int argc, char const *argv[])
{   
    //Declaration variable
    int i,j,permut,c,min,max;

    //Declaraiton et Initialisation variable
    int vrai =0;
    int tab2[] = {45,24,12,9,18,85,33};
    //Initialisation variable
    min=tab2[0];
    max=tab2[0];

    //Calcul min et max
    for (i = 0; i <7; i++)
    {
        if (tab2[i]<min)
        {
            min=tab2[i];
        }
        if (tab2[i]>max)
        {
            max=tab2[i];
        }
        
        
    }

    printf("le minimum est %d\n",min);
    printf("le maximum est %d\n",max);

    //int tab[] ={3,-4,0,0,0,1,-7,1,6,0,2,0}; // 12
    //int tab[] ={3,0,-4,0,0,0,0,1,-7,0,6,0,2,0}; //14
    //int tab[] ={3,-4,8,10,95,15,84,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0}; //34
    //int tab[] ={3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0};
    int tab[] ={3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0,3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0,3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0}; //240
    // 3,-4,1,-7,6,2,-1,0,0,0,0
  
    //Code pour mettre les 0 a droite 
    for(i=0; i <N; i++)
    {
        for (j=0; j <N; j++){
            if (tab[j]==0)//si on trouve un 0
            {
                permut = tab[j+1]; //permut prend la valeur a droite de celle actuelle  
                tab[j+1]=tab[j]; //la valeur de droite prend celle actuelle
                tab[j]=permut; // et la valeur actuelle prend l'ancienne valeur de celle a droite
                /* On echange la valeur de  droite  avec celle actuelle */
            }
        }
    }

    //Affichage du tableau  avec tout les 0 a droite
    for (i=0; i <N; i++)
    {
        printf("%d,",tab[i]);
    }
               
}