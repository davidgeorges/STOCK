#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
	char ch1,ch2;
	int nb1,nb2;
	char poubelle;
	int i =0;
	int bo=0;
//do{
	//printf("Veuillez saisir un carac\n");
	//scanf("%c",&ch1);
	//printf("Veuillez saisir un entier\n");
	//scanf("%d",&nb1);
	//printf("Veuillez saisir un entier\n");
	//scanf("%d",&nb2);
	//printf("Veuillez saisir un carac \n");
	//scanf("%c",&poubelle);
	//scanf("%c",&ch2);

	do{
	printf("Veuillez saisir un carac 11\n");
	scanf("%c",&ch1);
	printf("Veuillez saisir un entier 2\n");
	scanf("%d",&nb1);
	printf("Veuillez saisir un entier 3\n");
	scanf("%d",&nb2);
	printf("Veuillez saisir un carac 4 \n");
	scanf("%c",&poubelle);
	scanf("%c",&ch2);

	if (ch1=='a')
	{
		if (nb1==3)
		{
			if (nb2 ==5)
			{
				if (ch2=='b')
				{
					bo=1;
				}
			}
		}
	}
	i++;
	scanf("%c",&poubelle);
	}while( (i!=3) && (bo==0) ); // FAUX while( (i!=3) || (bo!=0) ); car si une des deux valeurs est vrai on ne sort pas si bo=1 et i =2 on ne sort pas
								// avec ( (i!=3) && (bo==0) ); on sort si une des deux est faux


	if (bo==1)
	{
		printf("Bon code!\n");
	}else{
		if (bo==0 && i==3)
		{
			printf("Mauvais mdp le compte est bloquer ! \n");
		}else{
			printf("Mauvais mdp\n");
		}
	}

	/*
	if ((ch1 =='a' ) && ( nb1 == 3))
	{
		if ((ch2 =='b' ) && ( nb2 ==5))
		{
			printf("Code secret bon !\n");
			i=3;
		}
		else{
			if (i==3)
			{
				printf("Désolé votre carte est bloquer!\n");
			}
			else{
				printf("Mauvais code secret 1 \n");
				scanf("%c",&poubelle);
				i++;
			}
		}
	}
	else{
		if (i==3)
			{
				printf("Désolé votre carte est bloquer!\n");
			}
			else{
				printf("Mauvais code secret 2 \n");
				scanf("%c",&poubelle);
				i++;
			}
	}
	}while(i!=3);
	*/
		return 0;
}