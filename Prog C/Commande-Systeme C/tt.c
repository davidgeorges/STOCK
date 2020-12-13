#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lire(char *chaine, int longueur);

int main(int argc, char const *argv[])
{
	char *positionEntree = NULL;

	char c[] = "";
	char s[] = "start chrome ";

	printf("Que voulez vous chercher sur google ? : \n");
	lire(c,20);


	strcat(s,c);
	printf("%s\n",s);
	printf("%s\n",c);
	system(s);
	

}

int lire(char *chaine, int longueur){
    char *positionEntree = NULL;
    int c;
    /* lecture du texte saisi au clavier */
    if (fgets(chaine, longueur, stdin) != NULL) // si pas null ( si il y a une chaine de caractère)
    {
        positionEntree = strchr(chaine, '\n'); // on cherche le retour a la ligne ( entrée )
        if (positionEntree != NULL) // si on la trouver
        {
            *positionEntree = '\0'; // on le remplace
        }
        else
        {
            // Intruction pour vider buffer
            c = 0;
            while (c != '\n' && c != EOF) // tant que c n'est pas egal au caractère de fin de ligne ( retour a la ligne ) (\n) ou fin de fichier on continuer la lecture
            {
                c = getchar();
            }
        }
        return 1;
    }
    else{
    	c = 0;
            while (c != '\n' && c != EOF) // tant que c n'est pas egal au caractère de fin de ligne ( retour a la ligne ) (\n) ou fin de fichier on continuer la lecture
            {
                c = getchar();
            }
        }
        
}
