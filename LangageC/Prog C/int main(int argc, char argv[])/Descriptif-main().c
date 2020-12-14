#include <stdio.h>


//Le programme simple suivant affiche les paramètres qui lui sont passés depuis le Terminal :
//prg.c
int main ( int argc , char * argv[] ) {
int i;
// affichage des arguments
printf("Nombre d’arguments passes au programme : %d\n",
argc);
for(i = 0 ; i< argc ; i ++) {
printf(" argv[%d] : ‘%s’\n", i, argv[i]);
}
return 0 ;
}

/*
Une fois ce programme compilé, si l'utilisateur le lance depuis le Terminal en tapant:
$ ./prg.exe test.txt 2
!alors le programme affichera dans le Terminal :

Nombre d’arguments passes au programme : 3
 argv[0] : ‘./prg.exe’
 argv[1] : ‘test.txt’
 argv[2] : ‘2’

puis retournera 0 (tout s’est bien passé)

*/