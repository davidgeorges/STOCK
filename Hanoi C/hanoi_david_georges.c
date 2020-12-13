#include <stdio.h>
#include <stdlib.h>



void hanoi(char orig, char dest, char temp,int no);

int main()
{
	int n = 3;

	hanoi('A','C','B', n+1);

}

void hanoi(char orig, char dest, char temp,int no)
{
	if (no>1)
	{
		hanoi(orig, temp, dest , no-1);
		printf("move disque %d from %c to %c \n",no-1, orig,dest);
		hanoi(temp, dest, orig, no-1);
	}
	
}

