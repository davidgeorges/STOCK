#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coin.h"
#include "crypt.h"

int lire(char *chaine, int longueur);

int main(int argc, char const *argv[])
{
	//Decla variable
	FILE *fichier = NULL;
	char psd[P];
	char mdp[M];

	//Appel fonction
	coin(psd,mdp);
	
	/* code */
	
	return 0;
}
