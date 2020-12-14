#include <stdlib.h>
#include <stdio.h>



int recursive(int i,int x);

int main(int argc, char const *argv[])
{
	recursive(1,5);
	printf("\nla daronne a bilal");
	return 0;
}

int recursive(int i,int x)
{
	/*
	int i;
	for (i = 0; i <x; ++i)
	{
		printf("*");
		if (x-1==i)
		{
			printf("\n");
		}
	}
	if(x==0){
		return 4;
	}
	else{
	recursive(x-1);
	}
	*/


	if(x>=i){
		printf("*");
		i++;
		recursive(i,x);
	}
	if (x==i)
	{
		i=1;
		printf("\n");
		recursive(i,x-1);
	}
}