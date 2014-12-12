#include<stdio.h>
#define SIZE 5000
int main()
{
	char buf[SIZE];
	int i,j,c;

	int n,k;
	int count=0;
	scanf("%lu %lu\n",&n,&k);
	int ti=0;
	while((c=fread(buf,1,SIZE,stdin))>0)
	{
		
		for(j=0;j<c;j++)
		{
			if(buf[j]=='\n')
			{
				printf("ti is %d\n",ti);

			printf("read \n",buf[j]);
				if(ti%k==0)
					count++;
				ti=0;
			}
			else
			{
				ti=ti*10+(buf[j]-'0');
			}

		}
	}

	printf("%d\n",count);
	return 0;
	
}
