#include <stdio.h>
#include <stdlib.h>


/*Prototype min max avec utilisation pointeur*/
void MinMax (int *p, int *Min, int *Max);

int main(int argc, char const *argv[])
{
    /*Declaration variable et initialisation*/
    int Tab[10] = {9, -1, 4, -8, 7, 15, 0, -3, 11, -5} ;

    int ValMini=0;
    int ValMaxi=0;
    int *pTab;

    MinMax(Tab, &ValMini, &ValMaxi) ; 

    printf("Pour min nous avons %d et pour max nous avons %d\n",ValMini,ValMaxi);


    
}

/* p = tab */
void MinMax (int *p, int *Min, int *Max){

    int i;
    *Min = *p;
    *Max = *p;
    for ( i = 1; i <10; i++) /* i = 1 et N-1 car on a deja le premier element affecter , donc on compare les autres ..*/
    {
        if (*(p+i)<*Max)//si element de i < valeur de Min , on affecte l'element i a la valeur de Min
        {
            *Min=*(p+i);
        }
        if (*(p+i)>*Max)
        {
            *Max=*(p+i);
        }
    }

}
