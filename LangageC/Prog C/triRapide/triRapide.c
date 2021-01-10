#include <stdio.h>

#define N 10

int x =0;

int partitionner(int *tableau, int p, int r) {
    int pivot = tableau[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (tableau[j] > pivot);
        do
            i++;
        while (tableau[i] < pivot);
        if (i < j) {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
        else
            return j;
    }
}

void quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r);
        quickSort(tableau, p, q);
        quickSort(tableau, q+1, r);
    }
}

int main() {
    int tab[N] = {5,0,10,9,6,1,4,5,2,4};
    int nbr, i;

    nbr=10;
  
    quickSort(tab,0,10);

    //triRapid(tab, 0, nbr - 1);
    
    printf("\n Tableau trie : ");
    for(i = 0; i < N; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    printf("x : %d",x);
    return 0;
}

/*
void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            printf("Valeur de  i avant : %d \n",i);
            while(tab[i] <= tab[pivot] && i < last){ //on incremente i jusqu'a trouver les element plus petit que le pivot
                printf("tab i :[%d] = %d et tab pi : [%d] = %d \n",i,tab[i],pivot,tab[pivot]);
                i++;
            }
            printf("Valeur de  i : %d \n",i);
            printf("Premiere boucle stoper tab i  %d :[%d] plus grand que  tab p %d  :[%d]  \n",i,tab[i],pivot,tab[pivot]);
            printf("Valeur de  j avant : %d \n",j);
            while(tab[j] > tab[pivot]){// on decrement j jusqua trouver les elements plus grand que le pivot
                printf("tab j : [%d] = %d et tab pi : [%d] = %d \n",j,tab[j],pivot,tab[pivot]);
                j--; 
            }
            printf("Valeur de  j : %d \n",j);
            printf("Deuxieme boucle stoper tab j  %d :[%d] plus petit que  tab p %d  :[%d]  \n",j,tab[j],pivot,tab[pivot]);
            if(i < j) {
                permuter(&tab[i], &tab[j]);
                printf("tab i : [%d] = %d permut ici avec tab j :[%d] = %d \n",i,tab[i],j,tab[j]);
            }
            printf("[%d] < [%d] ?   \n",i,j);
        }
        printf("J : %d est  plus petit que I %d \n",j,i);
        permuter(&tab[pivot], &tab[j]);
        printf("tab[%d] = %d permut avec tab[%d] = %d \n",pivot,tab[pivot],j,tab[j]);
        triRapid(tab, first, j - 1);
        printf("J CHANGE \n");
        triRapid(tab, j + 1, last);
    }

}*/
