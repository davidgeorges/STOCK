#include <stdio.h>
#include <stdlib.h>
#define N 20

/* David Georges , Code pour faire Initialiser un tableau et Afficher le tableau*/

int main(int argc, char const *argv[])
{
    //Declaration variable
    int tab[N];
    int i;
    

    //Initialiastion tableau ( on peut directement en faire l'affichage ici)
    for ( i = 0; i <N; i++)
    {
        tab[i] = i+1;
    }
    
     //affichage
    printf("Affichage en ligne : \n");
    // affichage valeur tableau 2
    for ( i = 0; i <N; i++)
    {
        printf("%d ",tab[i]);
    }
    
    
}