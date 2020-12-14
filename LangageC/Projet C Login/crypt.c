#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"

void crypt(char *chaine1){

	int l;
	int i;
	l = strlen(chaine1);
	for (int i = 0; i <=l; ++i)
	{
		chaine1[i] = chaine1[i] +848;
		//printf("%d\n",chaine1[i] );
	}

}

void decrypt(char *chaine1){

	int l;
	int i;
	l = strlen(chaine1);
	for (int i = 0; i <=l; ++i)
	{

		chaine1[i] = chaine1[i] -848;
		//printf("%d -- \n",chaine1[i] );
	}

}

