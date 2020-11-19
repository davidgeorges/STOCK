#include <stdio.h>
#include <stdlib.h>
const int MAX = 100, MIN = 1;

int main()
{
srand(time(NULL));
int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

int nbM = 0;

 do
{

    printf("Quel est le nombre mystere ?");
    scanf("%d",&nbM);

    if (nbM > nombreMystere)
        printf("moins !");


     else if (nbM < nombreMystere)
        printf("Plus ! !");

    else
        printf("Bravo vous avez trouver le nombre mystere %d", nbM);



 } while(nbM != nombreMystere);

}



