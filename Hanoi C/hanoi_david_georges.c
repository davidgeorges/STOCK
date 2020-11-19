#include <stdio.h>
#include <stdlib.h>



 void hanoi(char Orig, char Dest, char Inter,int nombre_disques_max);

int main()
{
	int n = 3;

	hanoi('A','C','B',n);

}

void hanoi(char Orig, char Dest, char Inter,int no)
{
	hanoi(Orig, Inter, Dest ,no-1);	// ss-problème 1
	printf(" move disque %d from %s to %s",no, Orig,Dest);	// ss-problème 2
	hanoi(Inter, Dest,  Orig,no-1);	// ss-problème 3
}

