#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 4
#define C 4

void printTab2D(int *p, int taille);

void triCol(int *p);

int main(int argc, char const *argv[])
{
    //Tab Bi-Dimen..
    int tab2D[L][C];

    srand(time(NULL));

    /*Decla Variable*/
    int i, j;

    /*Pointeur */
    int *p;

    /*affectation adresse tab Bidi au pointeur*/
    p = &tab2D[0][0];

    /*Initialisation tableau  2D*/
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            tab2D[i][j] = rand() % (9 - 0 + 1) + 0; // min + rand( (val-min+1))
        }
    }

    printf("\n");
    /*Appel de fonction pour afficher le tableau*/
    printTab2D(p, L * C);

    printf("Affichage apres \n");
    triCol(p);
    printTab2D(p, L * C);
}

/*Fonction pour afficher un tableau a l'aide d'un pointeur qui pointe sur l'adresse du premier element du tableau*/
void printTab2D(int *p, int taille)
{

    printf("Debut tab :  \n");
    for (int i = 0; i < taille; i++)
    {
        if (i % C == 0)
        {
            printf("\n");
        }
        printf("Indice %d valeur : [ %d ] ", i, *(p + i));
    }
    printf("\n\nFin tab : \n\n");
}

void triCol(int *p)
{

    int comptCol;
    int permut;
    for (comptCol = 0; comptCol< C; comptCol++){

        /*compteur j va prendre pour C = 3 va prendre les valeurs 0,3,6*/
        /* ce compteur va prendre chaque element de la colonne comptCol */
        for (int j = comptCol; j < L*C; j = j + C)
        {
            printf("I:  %d et  J : %d - [ %d > %d ]  \n", comptCol, j, *(p + comptCol), *(p + j));

            /* compteur k va prendre pour C = 3 va prendre les valeurs 3,6*/
            /* ce compteur va prendre chaque element de colonne apres le compteur j*/
            for (int k = j+C; k <L*C ; k =k+C)
            {
                //printf("Comparaison de l'indice J [ %d ] et K [ %d ] \n",j,k);
               //printf("J %d et K %d \n",j,k);
                if (*(p + j) > *(p + k))
                {
                    //printf("Permut de la valeur [ %d ] et (>) [ %d ] a l'indice J [ %d ] et K [ %d ] \n",*(p + j),*(p + k),j,k);
                    permut = *(p + j);
                    *(p + j) = *(p + k);
                    *(p + k) = permut;
                }
            }
        }
        printf("Fini \n");
    }
}

/* comptCol va nous servir pour les indice ( colonne 0,1...)*/
/* j va nous servir pour comparer chaque element de la colonne*/
/* a k qui lui va prendre l'element apres j */

/*EXEMPLE AVEC L=3 et C=3*/
/*compteCol va valoir 0 , ensuite j va valoir 0 et k 3 , on va comparer j et k ( le premier et deuxieme element de la colonne)*/
/* ensuite k va valoir 6 on va comparer j et k ( le premier et troisieme element de la colonne) ensuite 9<9 ? non on compare pas */

/*j va valoir 3 et k 6 , on va comparer j et k ( le deuxieme et troisieme element de la colonne)*/
/* ensuite k va valoir 9 , 9<9 ? non on compare pas ...*/


