#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printTab(int tab[]);
void minMax(int tab[],int tabMinMax[]);
int multiplyElem();
int trierTab(int tab[]);

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int tab1[10];
    int tab2[10];
    printf("First Tab : \n");
    printTab(tab1);
    printf("Second Tab : \n");
    printTab(tab2);
}

/* Fonction Init tab affichage et appel minMax*/
int printTab(int tab[]){

    int i;
    int tabMinMax[2] = {0,0};
    int nbMystere;
    for ( i = 0; i <10; i++)
    {
        nbMystere = rand() % 20 +1;
        tab[i] = nbMystere;
        
    }
    for ( i= 0; i <10; i++)
    {
        printf("Element %d vaut : %d \n",i,tab[i]);
    }

    minMax(tab,tabMinMax);
    
    return tab[0];//retourne la première valeur du tableau (nous avons donc toute les autres valeurs car il se suivent)
    
}

/* Fonction recherche Min et Max d'un tableau */
void minMax(int tab[],int tabMinMax[]){

    int i;
    tabMinMax[0] = tab[0];
    tabMinMax[1] = tab[0];
    for ( i = 0; i <10; i++)
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

int multiplyElem(){
    return 0;
}


/* Fonction trie tab decroissant */
int trierTab(int tab[]){

    int permut = 0;
     for (int i = 0; i <10; i++)
    {
        for (int j= i+1; j<10; j++)
          {           
            if (tab[i]<tab[j]) // si i < i+1 si ( 10 > 5 ) permut et ensuite remonter dans la boucle et ressayer
            {     
                //printf("%d > %d \n", tab[i],tab[j]); //pour le fonctionnement
                //printf("\t");
                permut = tab[i];
                tab[i] = tab[j];
                tab[j] = permut;
                /* on compare l'élement de gauche a celui de droite donc i = 0 et j = j+1
                si element de gauche plus petit que celui de droite on permut...*/
            }
            /* a i=9 on ne rentrer pas dans le deuxieme for car 9+1 n'est pas plus petit que 10*/
            
          }
    }
    return tab[0];
}