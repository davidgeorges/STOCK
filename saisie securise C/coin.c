#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <coin.h>

int coin(char *chaine1,char *chaine2){

	char c [] = "CO";
	char i [] = "IN";


	printf("* Appuyez sur CO pour vous connecter : \n");
	printf("* Appuyez sur IN pour vous Inscrire : \n");
	lire(r,3);

	//Condition si connexion ou inscrption
	if ( strcmp(r,c) == 0 ){
		printf("Vous avez choisis connexion ! :\n");
		printf("Veuillez ecrire votre pseudo : \n");
		lire(psd,P);
		printf("Veuillez ecrire votre mot de passe : \n");
		lire(mdp,M);
		printf("%s et %s \n",psd,mdp);	
	}
	else{

			if( strcmp(r, i) == 0 ){
					printf("Inscrire\n");	
					printf("Veuillez ecrire votre pseudo : \n");
					lire(psd,P);
					printf("Veuillez ecrire votre mot de passe : \n");
					lire(mdp,M);
					printf("Veuillez confirmer votre mot de passe : \n");
					lire(mdp,M);
					printf("%s et %s \n",psd,mdp);
			}
			else{

				printf("Mauvais choix de commande sorti du programme\n");
				printf("Ok %s\n",r);
				return 0;
			}
	}

}


//---------------------FONCTION-LIRE----------------------------//

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL) // si pas null ( si il y a une chaine de caractère)
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
}