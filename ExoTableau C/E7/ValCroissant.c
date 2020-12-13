#include <stdio.h>
#include <stdlib.h>

/* David Georges , Code pour trier un tableau dans un odre croissant Afficher le tableau*/
int main()
{
    /*Decla et Init variable*/
    int tab[] = {10,5,8,4,9,2,6,1,3,7};
    int i=0;
    int j=0;
    int permut=0;

    //Affichage
    printf("Tableau avant :\n");
    //Boucle pour affichage valeur tableau avant tri ordre croissant
    for (i = 0; i < 11; ++i)
    {
        printf("%d",tab[i] );
    }

    //Comparaison on fait 10 ittération si 
    for (i=0; i<10; i++)
    {
        for (j=i+1; j<10; j++) // i = 1
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
     //Affichage
    printf("\n");
    printf("Tableau apres :\n");
    //Boucle pour affichage valeur tableau apres tri  ordre croissant
    for (i = 0; i < 11; ++i)
    {
        printf("%d",tab[i] );
    }


}


