#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "coin.h"
#include "crypt.h"

/*----------------------REGROUPE POUR LINSTANT 2 FONCION-----------MAJ/21/10------------*/



/*-------------------------------- Fonction Connexion et Inscription -------------------------------- */

void coin(char *chaine1,char *chaine2){

	// Decla variable et init de quelques variables
	FILE *FILEC = NULL;
	char c [] = "CO";
	char i [] = "IN";
	char r[3];
	char chaine3 [M];
	int size;
	char *positionEntree = NULL;

	//Affichage et lecture
	printf("* Appuyez sur CO pour vous connecter : \n");
	printf("* Appuyez sur IN pour vous Inscrire : \n");
	lire(r,3);


	//Condition si connexion ou inscrption
	if ( strcmp(r,c) == 0 ){
		printf("Vous avez choisis connexion ! :\n"); 
		printf("Veuillez ecrire votre pseudo : \n"); // affichage et lecture pseudo
		lire(chaine1,P);
		/*	Ouvre le fichier  */
		FILEC = fopen(chaine1, "r");
		if (FILEC != NULL) // si fichier pas vide
		{
			printf("Veuillez ecrire votre mot de passe : \n"); // affichage et lecture pseudo
			lire(chaine2,M);//on demande la saisie
			fgets(chaine3,15,FILEC)//on lit ligne dans dossier
			// fonction decrypt
			decrypt(chaine3);
			// on enleve le retour a la ligne et on le remplace apr \0
			positionEntree = strchr(chaine3, '\n'); // on cherche le retour a la ligne
       		 if (positionEntree != NULL) // si on la trouver
        	{
            	*positionEntree = '\0'; // on le remplace
        	}
			/* on comparer si c'est le même mot de passe*/
			if ( strcmp(chaine2,chaine3) == 0 )
			{
				printf("Bienvenue %s connexion avec succes !\n",chaine1);
			}
			/* si mot de passe différent*/
			else{
				printf("Pseudo ou mot de passe non reconnu 1 !\n");
			}
		}
		/* si pseudo différent */
		else{
			printf("Pseudo ou mot de passe non reconnu  2 !\n");
		}	
	}
	/*si on choisis inscription ou autre*/
	else{
		// si on choisis inscription
		if( strcmp(r, i) == 0 ){
					printf("Vous allez vous s'inscrire\n");	
					printf("Veuillez ecrire votre pseudo : \n"); // affichage et lecture pseudo
					lire(chaine1,P);
					FILEC = fopen(chaine1, "a+");
					// si ouverture fichier a fonctionner
					if(FILEC != NULL){ // 
    					fseek (FILEC, 0, SEEK_END);
    					size = ftell(FILEC);
    					//si le fichier est vide on peut proceder a l'inscription
    					if (0 == size){
        					printf("Veuillez ecrire votre mot de passe : \n"); // affichage et lecture mot de passe
							lire(chaine2,M);
							// fonction crypt
							crypt(chaine2);
							printf("%s\n",chaine2 );
							printf("Veuillez confirmer votre mot de passe : \n");
							lire(chaine3,M);
							// fonction crypt
							crypt(chaine3);
							//si mot de passe et confirmation mot de passe sont les mêmes
							if(strcmp(chaine2,chaine3) == 0 ){
								fprintf(FILEC, "%s\n", chaine2); // si pas erreur on écrit le mot de passe seulement
								printf("Inscription avec succes bienvenue %s! ",chaine1);
								fclose(FILEC);
      						}
      						// si lors de saisie de la confirmation du mot de passe ne correspond au mot de passe saisie avant
      						else{
      							printf("Les mots de passe ne correspondent pas\n");
      							fclose(FILEC);
      							remove(chaine1);
      						}
						}
						// si fichier non vide 
						else{
							printf("Nom d'utilisateur deja pris !  \n");
							fclose(FILEC);
							exit(0);
						}
    				}
    				// si erreur lors d'ouverture
    				else{
    					printf("Erreur ouverture dossier\n");
      					exit(0);
    				}
		}
		// si aucun des deux choix
		else{
			printf("Desole mauvais choix ! %s\n");
		}
	}
}


//---------------------FONCTION-LIRE----------------------------//

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