#include <stdio.h>
#include <stdlib.h>
#define N 7

/* David Georges , Code pour faire la somme d'un tableau et Inverser le tableau*/

int main(int argc, char const *argv[])
{
    //Declaration et Initialisation variable
    int tab[] = {45,24,12,9,18,85,33};
    int tab2[N];
    int i=0;
    int permut=0;
    int somme=0;

     for (i = 0; i <N; ++i)
    {
        printf("Veuillez saisir une valeur\n");
        scanf("%d",&tab2[i]);
    }

    //Calcul somme du tableau
    for (i = 0; i <N; ++i)
    {
        somme = somme + tab2[i];
    }
    //Affichage somme du tableau
    printf("La somme du tableau est de %d \n" ,somme);
    

    //Affichage tableau avant inversement
    for (i = 0; i <N; ++i)
    {
        printf("avant  %d\n",tab[i] );
    }
    /* code ici --------------------------------*/
   for (i = 0; i<N/2; i++) //diviser sans reste par 2 et ensuite +1
        {
            permut = tab[i];
            tab[i] = tab[N-i-1];
            tab[N-i-1] = permut;
       }
          printf("\n");
    /* code ici --------------------------------*/
    //Affichage tableau apres inversement
    for (i = 0; i <N; ++i)
    {
       printf("apres %d\n",tab[i] );
    }
    printf("\n"); 

    /* Deuxieme methode
    int T[] = {45,24,12,9,18,85,33};
    int j, temp;
	for (i=0, j=N-1; i<j; i++,j--)
	{
		temp = T[i];
		T[i] = T[j];
		T[j] = temp;
	}
    for (i = 0; i <N; ++i)
    {
        printf("apres %d\n",tab[i] );
    }
    */    

}