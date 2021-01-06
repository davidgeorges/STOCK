#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

/*------------------------------------------- Georges David , 11/12/2020 -------------------------------------------


------------------------------------------------------------------------------------------------------------------*/

/*Affichage et intialise le tableau avec des valeurs aléatoire*/
void printInitTab(int tab[]);
/*Stock la plus petite et grande valeur du tableau*/
void minMax(int tab[],int tabMinMax[]);
/*Multiple l'element du tableau 1 et tableau 2 et on le stock dans le tableau 3*/
void multiplyElem(int tab [], int tab2[],int tab3[]);
/*Trie le tableau dans l'ordre */
void trierTab(int tab[]);
/*Affiche le tableau*/
void printTab(int tab []);

int main(void)
{
    /* code */
    srand(time(NULL));
    int tab1[N];
    int tab2[N];
    int tab3[N];
    //printf("First Tab : \n");
    printf("Avant tri : \n");
    printInitTab(tab1);
    //printf("Second Tab : \n");
    //printInitTab(tab2);
    //multiplyElem(tab1,tab2,tab3);
    //printTab(tab1);
    trierTab(tab1);
    printf("Apres tri : \n");
    printTab(tab1);

    return EXIT_SUCCESS;
}

/* Fonction Init tab affichage et appel minMax*/
void printInitTab(int tab[]){

    int i;
    int tabMinMax[2] = {0,0};
    int nbMystere;
    for ( i = 0; i <N; i++)
    {
        nbMystere = rand() % 20 +1;
        tab[i] = nbMystere;
        
    }
    for ( i= 0; i <N; i++)
    {
        printf("Element %d vaut : %d \n",i,tab[i]);
    }

    minMax(tab,tabMinMax);/*vu qu'on a deux tableau intialiser pour l'instant
    je met directement l'appel a minMax ici qui ce fera pour chaque tableau  */
    
    
}

/* Fonction affichage du tableau */
void printTab(int *tab){

    int i;

    for ( i= 0; i <N; i++)
    {
        printf("Element [%d] vaut : %d \n",i,tab[i]);
    }

    
    
}

/* Fonction recherche Min et Max d'un tableau */
void minMax(int tab[],int tabMinMax[]){

    int i;
    tabMinMax[0] = tab[0];
    tabMinMax[1] = tab[0];
    for ( i = 1; i <N-1; i++) /* i = 1 et N-1 car on a deja le premier element affecter , donc on compare les autres ..*/
    {
        if (tab[i]<tabMinMax[0])
        {
            tabMinMax[0]=tab[i];
        }
        if (tab[i]>tabMinMax[1])
        {
            tabMinMax[1]=tab[i];
        }
    }

    printf("Pour min nous avons %d et pour max nous avons %d\n",tabMinMax[0],tabMinMax[1]);
    
}

void multiplyElem(int tab [], int tab2[],int tab3[]){
    
    for (int i = 0; i < N; i++)
    {
        tab3[i] = tab[i] * tab2[i];
    }
    
}


/* Fonction trie tab decroissant */
void trierTab(int tab[]){

    int permut = 0;
     for (int i = 0; i <N-1; i++)
    {
        printf("Iterataion i : [%d] \n",i);
        for (int j=i+1; j<N; j++) /* on met j=i+1 pour ne pas refaire depuis le debut du tableau 
        car normalement apres la première iteration la plus grande valeur est stocker au debut du tableau ( Tri par selection du maximum )*/
          {    
              printf("Iterataion j : [%d] \n",j);      
            if (tab[i]<tab[j]){/* si i < j si ( 10 > 5 ) permut et ensuite remonter dans la boucle 
            et ressayer avec une nouvel valeur de j et apres que j = X on remonte dans i ... */

                //printf("permut i : [%d] et j [%d] \n",i,j);
                permut = tab[i];
                tab[i] = tab[j];
                tab[j] = permut;
                /*
                for (int k  = 0; k<N; k++)
                {
                    printf("Element [%d] vaut : %d \n",k,tab[k]);
                }
                */
                /* on compare l'élement de gauche a celui de droite donc i = 0 et j = j+1
                si element de gauche plus petit que celui de droite on permut...*/
            }
            
            /* a i=9 on ne rentrer pas dans le deuxieme for car 9+1 n'est pas plus petit que 10*/
            
          }
    }
}