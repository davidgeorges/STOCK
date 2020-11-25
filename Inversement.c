#include <stdio.h>
#include <stdlib.h>
#define N 7


int main(int argc, char const *argv[])
{
    int tab[] = {45,24,12,9,18,85,33};
    int i=0;
    int permut=0;

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
