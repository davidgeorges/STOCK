#include <stdio.h>
#include <stdlib.h>
#define N 240

int main(int argc, char const *argv[])
{
    int i,j,permut,c;
    int vrai =0;
    //int tab[] ={3,-4,0,0,0,1,-7,1,6,0,2,0}; // 12
    //int tab[] ={3,0,-4,0,0,0,0,1,-7,0,6,0,2,0}; //14
    //int tab[] ={3,-4,8,10,95,15,84,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0}; //34
    //int tab[] ={3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0};
    int tab[] ={3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0,3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0,3,-4,0,0,1,0,0,-7,6,0,2,0,3,-4,8,10,0,15,0,5,1,0,6,0,0,0,0,-7,6,0,2,0,0,7,0,0,0,1,0,0,-7,0,6,0,2,0,3,-4,8,10,95,15,84,5,1,0,6,0,1,0,0,-7,6,0,2,0,0,7,0,5,0,1,0,0,-7,0,6,0,2,0}; //240
    // 3,-4,1,-7,6,2,-1,0,0,0,0
  
    for(i=0; i <N-1; i++)
    {
        for (j=0; j <N-2; j++){
            if (tab[j] ==0)
            {
                permut = tab[j+1];
                tab[j+1]=tab[j];
                tab[j]=permut;
            }
        }
    }

    for (i=0; i <N; i++)
    {
        printf("%d,",tab[i]);
    }
               
}