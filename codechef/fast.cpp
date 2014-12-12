#include<iostream>
#include<stdio.h>
#include<unistd.h>
//inline copies this function and puts it where its been called --> reduces memory usage bt leads to inc in execution time
inline void fast(int *a)
{
	register char c=0;
	while (c<33)
	{
		c=getchar_unlocked(); //gets the first char of int
		//putchar(c);
		//putchar("\n");
	//	printf("%c\n",34);
	}
	*a=0;
	while (c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}
int main()
{
	int i,j;

	//fast(&i);
	for(j=0;j<100;j++)
	{
	fast(&i);
	printf("%d\n",i);
	}
	return 0;
}

