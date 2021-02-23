#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 3
#define C 3

void tab2dIntoTab1d(int *p,int *p2);

void printTab(int *p,int taille);

int main(int argc, char const *argv[])
{
    //Tab Bi-Dimen..
    int tab2D[L][C];
    int tab1d[L*C];

    srand(time(NULL));
    
    /*Decla Variable*/
    int i,j;

    /*Pointeur */
    int *p;
    int *p2;

    /*affectation adresse tab Bidi au pointeur*/
    p=  &tab2D[0][0];
    p2 = tab1d;



    /*Initialisation tableau  2D*/
    for (i = 0; i <L; i++)
    {
        for (j= 0; j <C; j++)
        {
            tab2D[i][j]= rand() % (9- 0 +1) + 0; // min + rand( (val-min+1))
        }
    }


    /*Affichage du tableau sans aucune initialiastion*/    
    printf("Affichage tab1D sans aucune initialisation\n");
    for ( i = 0; i < L*C; i++)
    {
        printf("Indice %d valeur : [ %d ] \n",i,*(p2+i));
    }
    
     

    /*Appel fonction pour inserer les valeur du tableau 2D dans la tableau 1d*/
    tab2dIntoTab1d(p,p2);
    
    /*Appel de fonction pour afficher le tableau*/
    printTab(p,L*C);
    printTab(p2,L*C);



    
}


void tab2dIntoTab1d(int *p,int *p2){

    int i;
    

    //tout les i+N+1 'ittération' nous somme a la meme ligne et colonne donc en diagonale  ( avec deux boucle c'est quand nous avons i==j on est en diago )
    for (i=0; i<L*C; i++)
    {         
        *(p2+i) = *(p+i);
        /* on met dans la case i du  tableau tab1D via le pointeur p2 (tab1D)  la valeur de la case i du tableau  tab2D via le pointeur p1 (tab2D)*/
    }  
    printf("\n");

}


/*Fonction pour afficher un tableau a l'aide d'un pointeur qui pointe sur l'adresse du premier element du tableau*/
void printTab(int *p,int taille){

    printf("Debut tab : \n\n");
    for (int i = 0; i < taille; i++)
    {
       printf("Indice %d valeur : [ %d ] \n",i,*(p+i));
    }
    printf("Fin tab : \n\n");
    
}

