#include <stdio.h>
#define N 4

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
    int tab[N] = {5,0,10,9};
    int nbr, i;

    nbr=10;
  
    quickSort(tab,0,N-1);//N-1

    //triRapid(tab, 0, nbr - 1);
    
    printf("\n Tableau trie : ");
    for(i = 0; i < N; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    printf("x : %d",x);
    return 0;
}

/*explication pour un tableau de 4 elements 
{5, 0, 10, 9}
 0  1  2   3

Premier appel : quickSort(tab,0,N-1)
Premier Appel qs(0,3) , pivot = t0(5), i(-1) , boucle j = j(4), j-- t3>5(9>5 , oui), j-- t2>5(10>5 , oui) j-- t1>5(0>5 , NON ,j=1)//boucle i =  i++ t0>5(5<5 NON , i=0)
si i<j ( 0<1 , oui donc permute = 0, 5, 10, 9) , boucle j = j-- t0>5 (5>5 non , j=0)//boucle i = i++ t1>5(5<5 NON , i=0), i<j (0<0 non on sort et return j(0) ) donc q = 0


appel recu1(0,0) (0<0 non on sort sans rien faire) , 

ici p = 0 et r 3

recu2(1,3)(premiere appel) (1<3) donc on continue et on rappel partition !!  [avec 1 et 3] , pivot = 5, [ i =0, j=4 ] // boucle j , j-- t3>5(9>5 oui), j-- t2>5(10>5 oui), j-- t1>5(5>5 non (j=1))
//boucle i =  i++ t1>5(5<5 NON , i=1) , i<j (1<1 non on sort et return j(1) ) donc q = 1


tab : 0, 5, 10, 9
appel recu1(deuxieme appel) avec [(1,1)] (1<1 non on sort sans rien faire) ,
ici q = 1(p)
recu2(2,3)(deuxieme appel) (2,3) (2<3 oui) on rappel partition avec   [2 ,3] !!, pivot = 10  [ i=1, j=4 ]// boucle j , j-- t3>10 (non on sort j = 3)
//boucle i =  i++ t2>10(10<10 NON on sort, i=2), i<j (2<3) on permute :0, 5, 9,10 // boucle j , j-- t2>10 ( 9>10 non on sort j = 2)// boucle i , i-- t3>10 (10>10 non on sort j = 3)
i<j ( 3<2 non on sort et retourne 2); q= 2

appel recu1(troisieme fois) (appeler avec p = 2 et r 2) , qs(2,2) p<r (2<2 non on sort) et on appel recu2(troisieme fois) , qs(3,2) p<r (3<2 non on sort) et il n'y a plus de rappel !

Le tableau est trié */
 