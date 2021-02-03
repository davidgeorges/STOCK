#include <stdio.h>
#include <stdlib.h>

#define N 10

void diag(int *p,int n);

int main(int argc, char const *argv[])
{
    //Tab Bi-Dimen..
    int tab2D[N][N];

    /*Decla Variable*/
    int i,j;
    /*Pointeur */
    int *p;

    p=(int *)tab2D;

    /*Initialisation tableau  2D*/
    for (i = 0; i <N; i++)
    {
        for (j= 0; j <N; j++)
        {
            tab2D[i][j]=i+1;
        }
    }  

    /*Appel fonction*/
    diag(p,N);
    
    /*Affichage tableau 2D*/
    for (i = 0; i <N; i++)
    {
        for (j= 0; j <N; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }  

    
}


void diag(int *p,int n){

    int i,j;
    
    *(p) =0;
    i =0;

    //tout les i+N+1 'ittération' nous somme a la meme ligne et colonne donc en diagonale  ( avec deux boucle c'est quand nous avons i==j on est en diago )
    for (i =i+N+1; i <n*n; i=i+N+1)
    {   

        printf("[%d]\n" ,*(p+i));
        *(p+i) =0;

    }  
    printf("\n");

}

/* Pour N = 9 , i+N+1 = 0+9+1 = 10 , ( Deuxieme element = diagonale ) , ensuite i = 10+9+1 =  deuxieme troisieme element diagonale...

0 1 1 1 1 1 1 1 1
2 0 2 2 2 2 2 2 2
3 3 0 3 3 3 3 3 3
4 4 4 0 4 4 4 4 4
5 5 5 5 0 5 5 5 5
6 6 6 6 6 0 6 6 6
7 7 7 7 7 7 0 7 7
8 8 8 8 8 8 8 0 8
9 9 9 9 9 9 9 9 0*/