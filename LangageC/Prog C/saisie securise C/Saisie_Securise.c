#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Fonction pour vider le buffer*/
void viderBuffer();
/*Fonction pour lire une chaine de caractere, et enlever le retour a la ligne(entrer) et le remplacer par le caractere de fin de chaine*/
int lire(char *chaine, int longueur);

int main(int argc, char const *argv[])
{
    char nom[15];
    printf("Veuillez ecrire votre nom : \n");
    lire(nom,15);

    printf("Bienvenue %s ! ",nom);


}


void viderBuffer()
{
    int c = 0;
    /*tant qu'ont a pas trouver le retour a la ligne et qu'ont est pas a la fin de 'fichier' ->(fin du buffer)*/
    while (c != '\n' && c != EOF)
    {
        c = getchar();//on récupere le caractere en ecrasent le precedent*/
    }
}
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;/*pointeur de type char*/
 
    /*si il n'est pas egale a NULL on n'a pas d'erreur donc on continue*/
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        /*on recherche la caractere '\n' dans la chaine passe en parametre*/
        positionEntree = strchr(chaine, '\n');
        /*si on la trouver*/
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';/* on le remplace par le caractere de fin de chaine*/
        }
        else/*si on la pas trouver on vide le buffer*/
        {
            viderBuffer();
        }
        /* on sort de la fonction*/
        return 1;
    }
    else/*si on a un probleme avec fgets on vide le buffer*/
    {
        viderBuffer();
        return 0;
    }
}