#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 8


/*------------------------------------------- Georges David , 11/12/2020 -------------------------------------------



------------------------------------------------------------------------------------------------------------------*/

/*renvoie un entier generer entre 8 et X*/
int alea(int nb1);

int main(int argc, char const *argv[])
{
    /* code */
    int nb;
    srand(time(NULL));
    printf("Veuillez saisir un entier :\n");
    scanf("%d",&nb);
    if (nb>10)
    {
        printf("on a : %d \n",alea(nb));
    }else
    {
        printf("Erreur nombre plus petit que 10 !\n");
    }
    
    
 
}

int alea(int nb1){

    int nbMystere = rand() % (nb1 - MIN +1) + MIN; // min + rand( (val-min+1))
    return nbMystere;
}
