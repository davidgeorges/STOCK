#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	int i =0;
	int j =0;
	int tab[3][2];
	printf("Merci beaucuoup\n");
	for (i=0; i<3; i++){


		for (j=0; j<2; j++){

		tab[i][j] = i;
		printf("Element indice  pour i : [%d] et j : [%d] = %d\n",i,j,tab[i][j]);

		}

		
	}

	j =2;

	if (j<=2){
		printf("vrai\n");
	}

	return 0;
}