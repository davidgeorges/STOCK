#include <stdio.h>
#include <stdlib.h>

/* David Georges , Code pour faire Initialiser un tableau et Afficher le tableau*/

//Prototype Fonction
int saisieEntier();
int factorielle(int);
void parite(int);

//Fonction principale
int main(int argc, char const *argv[])
{
    //Declaration Variable
    int nombre1;
    nombre1 = saisieEntier();
    printf("%d\n",factorielle(nombre1));
    parite(nombre1);
    return 0;
}

//
int saisieEntier(){
    //Decla Variable
    int nb1;
    //Affichage et Saisie
    
    //Voir si nb1 est compris entre 2 et 6
    while (nb1<2 || nb1>6)
    {
        printf("Veuillez saisir un nombre entre 2 et 6 !\n");
        scanf("%d",&nb1);
        if (nb1>2 && nb1<6)
        {
        printf("La valeur %d est comprise entre deux et six ! Cacul factorielle en cours...\n",nb1);
        return nb1;
        }else
        {
        printf("La valeur %d n'est pas comprise entre deux et six  veuillez ressayer ! \n",nb1);
        return EXIT_FAILURE;
        }  
    }

}

int factorielle(int nb2){

    //Decla et Init Variable
    int resultat;
    int fact =1;
    for ( int i = 1; i<nb2; i++)
    {
        fact = fact *i;
    }
    resultat = fact*nb2;
    return resultat;
    
}

void parite(int nb3){
    if ((nb3%2)==0)
    {
        printf("Le nombre est pair !\n");
    }else
    {
        printf("Le nombre est impair !\n");
    }
    
}
