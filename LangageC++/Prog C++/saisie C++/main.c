#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  * = ignorer ( tout ce qui  a été lu )
//  ^ = ce qui n'est pas

int main()
{
    printf("Hello world!\n");
    return 0;
}

 /*-------------------------------- FONCTION 1 PLUS FACILE !! -------------------------------------------------- */


int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL) // si pas null
    {
        positionEntree = strchr(chaine, '\n'); // on cherche le retour a la ligne
        if (positionEntree != NULL) // si on la trouver
        {
            *positionEntree = '\0'; // on le remplace
        }
        else
        {
            // Intruction pour vider buffer
            int c = 0;
            while (c != '\n' && c != EOF) // tant que c n'est pas egal au caractère de fin de ligne ( retour a la ligne ) (\n) ou fin de fichier on continuer la lecture
            {
                c = getchar();
            }
        }
        return 1;
    }
    else
    {
        // Intruction pour vider buffer
        int c = 0;
            while (c != '\n' && c != EOF) // tant que c n'est pas egal au caractère de fin de ligne ( retour a la ligne ) (\n) ou fin de fichier on continuer la lecture
            {
                c = getchar();
            }

        return 0;
    }
}

 /*-------------------------------- FONCTION 2 PLUS COMPLIQUER !! -------------------------------------------------- */

char *input_read(char *str, int size)
{
    char *data;// valeur a return

    data = fgets(str,size,stdin);

    if(data) // si data pas nul
    {
        size_t len = strlen(str) -1;//recuperer la taille de la chaine -1 ( sans le  caractere de fin de chaine )

        if(str[len] == '\n') // on accède directemnt a la fin de la chaine avec le ( len ) et  si a la fin on a le caractere de retour a la ligne
        {

            str[len] = '\0'; // on enleve le retour a la ligne dans notre chaine

        }
        else
        {
            // vider buffer
            fscanf(stdin,"%*[^\n]"); // % = flag , je capture tout ce qui n'est pas un \n  pour l'ignorer
            fgetc(stdin); //nettoyage
        }
    }

    return data; // return la chaine sans le retour a la ligne + buffer vide
}
