#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[] = {10,5,8,4,9,11,2,6,1,3,7};
    int i=0;
    int j=0;
    int permut=0;

    for (i = 0; i <11; i++)
    {
    
        for (j= i+1; j<11; j++) // i = 1
          {
            
            if (tab[i]>tab[j]) // si i > i+1 ( 2) permut et ensuite remonter dans la boucle et ressayer
            {     
                //printf("%d > %d", tab[i],tab[i+1]); //pour le fonctionnement
                //printf("\t");

                permut = tab[i];
                tab[i] = tab[j];
                tab[j] = permut;
            }
          }
          printf("\n");
    }

    for (i = 0; i < 11; ++i)
    {
        printf("%d",tab[i] );
    }


}
