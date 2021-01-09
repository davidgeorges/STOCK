#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------- Georges David , 11/12/2020 -------------------------------------------



------------------------------------------------------------------------------------------------------------------*/

//Prototype Fonction
/* renvoie l'inverse d'un nombre */
float inverse(float x);

//Fonction principale
int main(int argc, char const *argv[])
{
    //Declaration Variable
    float val;
    //Afichage et saisie
    printf("Veuillez entrer la valeur : ");
    scanf("%f",&val);
    //Affichage la valeur inversé
    printf("La valeur est %.2f",inverse(val));
    //notre variable val n'est pas modifié
    return 0;
}

//Fonction secondaire qui effectue l'inverse du nombre donner en parametre
float inverse(float x){
    if (x==0)
    {
        printf("Impossible de faire l'inverse de  0\n");
        return EXIT_FAILURE;
    }else
    {
       return 1/x;
    }
    
}