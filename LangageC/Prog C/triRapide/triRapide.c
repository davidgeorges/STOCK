#include <stdio.h>
#define N 10

/*On met tout les valeurs inférieurs au pivot a sa gauche et les valeurs supérieurs au pivot a  sa droite
  on change la taille lors du premier appel le pivot lors de la deuxième appel*/

int x =0;

void afficheTab(int tab[]){
     printf("Tableau : ");
    for (int i = 0; i < N; i++)
    {
       
        printf("Tableau : [%d] , ",tab[i]);
    }
    
    printf("\n");
}

void afficheTabApres(int tab[]){
    printf("Tableau apres permut : ");
    for (int i = 0; i < N; i++)
    {
        
        printf(": [%d] ",tab[i]);
    }
    
    printf("\n");
}

int partitionner(int *tableau, int p, int r) {
    int pivot = tableau[p], i = p-1, j = r+1; // -1 et +1 car on fait un do while
    int temp;
    while (1) {
        do{
            j--;

            //printf("on cherche un element plus petit que %d ,",pivot);

        }while (tableau[j] > pivot);//si l'element de droit est plus grand que le pivot on decremente pour en chercher un plus petit, si il est plus petit on sort(on cherche l'element le plus petit)

        //printf("[%d] < [%d] , ",tableau[j],pivot);

        do{
            i++;

            //printf("on cherche un element plus grand que %d , \n",pivot);

        }while (tableau[i] < pivot);//si l'element de gauche est plus petit que le pivot on incremente pour en chercher un plus grand, si il est plus grand on sort(on cherche l'element le plus grand)

        //printf("[%d] < [%d] , \n",tableau[j],pivot);
        //afficheTab(tableau);
       // printf("valeur de i %d et j %d \n",i,j);

        if (i < j) {// si i<j on s'est croisé

            //printf("Permutation de %d et %d \n",tableau[i],tableau[j]);

            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;

            //afficheTabApres(tableau);
            
        }
        else{

            //printf("on retourne \n");
            //printf("Valeur de i [%d] et j [%d] \n",i,j);
            return j;//condition de sortie
        }

       // printf("\n \n");
    }   
}

void quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        //printf("ICI Valeur de p [%d] et r [%d] \n",p,r);
        q = partitionner(tableau, p, r);
        //printf("cette appel 1 - ");
        quickSort(tableau, p, q);//ici on a deja fait un petit trie avec la taille de fin de tableau modifier
        //printf("cette appel - ");
        quickSort(tableau, q+1, r);//ici on refait le tri avec un autre pivot et la vrai taille du tableau
    }
}

int main() {
    int tab[N] = {5,0,10,9,6,1,4,5,2,4};
    int nbr, i;

    nbr=10;
  
    quickSort(tab,0,9);//N-1

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
