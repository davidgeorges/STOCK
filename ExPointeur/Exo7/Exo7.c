#include <stdio.h>
#include <stdlib.h>



void diag(int *p,int n);

int main(int argc, char const *argv[])
{
    //L C
    int tab2D[5][5];

    int n=5;
    int i,j;
    int *p;

    p=(int *)tab2D;

    /*Initialisation tableau  2D*/
    for (i = 0; i <5; i++)
    {
        for (j= 0; j <5; j++)
        {
            tab2D[i][j]=i+1;
        }
        printf("\n");
    }  

    diag(p,5);
    /*Affichage tableau 2D*/
    for (i = 0; i <5; i++)
    {
        for (j= 0; j <5; j++)
        {
            printf("%d ",tab2D[i][j]);
        }
        printf("\n");
    }  

    
}


void diag(int *p,int n){

    int i,j;

    for (i = 0; i <n*n; i++)
    {
        if(i%6==0){
            printf("[%d]\n" ,*(p+i));
            *(p+i) =0;
        }
            
        printf("\n");
    }  


}

//0 , 6 , 12 , 18