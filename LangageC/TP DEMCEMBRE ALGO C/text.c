#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int tab[4] = {8,6,5,2};
    int tab1[4] = {0,0,0,0};

    int essai = 0;
    int trouver = 0;
    int i;

    while (essai !=5 && trouver !=4 )
    {
        trouver = 0;
        for ( i= 0; i <4; i++)
        {
            printf("Veuillez saisir une valeur ");
            scanf("%d",&tab1[i]);
            if (tab[i] == tab1[i])
            {
                trouver++;
            }else
            {
                trouver = 0;
            }
      
        }

        essai++;
        if (trouver !=4 && essai !=5)
        {
            printf("Acces refuse !\n");
        }
        
    }

    if (trouver == 4)
    {
        printf("Acces autorise \n");
    }else
    {
        printf("Acces au batiment bloquer definitivement \n");
    }
    
    
    
    return 0;
}
