#include<stdio.h>
#include<stdlib.h>

int sqr(int a)
{
	int i=1;
	while(i*i<=a)i++;
	return i;
}

int main()
{
	int m,n,v,rep,i,j;
	scanf("%d",&rep);
	int count,t;
	int *arr=(int*)malloc(sizeof(int)*1000000);
	for(i=2;i<1000;i++)
	{
		for(j=2;j<1000000;j++)
		{
			if(j%i==0 && arr[j]!=1 && j!=i)
			{
				arr[j]=1;
			}
		}
	}
	
		
	for(v=0;v<rep;v++)
	{
		scanf("%d %d",&m,&n);
		if(m<100000 && n<=1000000)
		{	j=m;
			while(j<=n)
			{
				if(arr[j]!=1 && j!=1)
				{
					printf("%d\n",j);
				}
				j++;
			}
			continue;
		}
		else{
		
		count=n-m+2;
		//printf("the number of elements %d\n",count);
		t=sqr(n);
		//printf("t is %d\n",t);
		int *temp=(int*)malloc(sizeof(int)*count);
	//	printf("no error with malloc\n");
		
		for(i=2;i<=t;i++)
		{
			for(j=m;j<=n;j++)
			if(j%i==0 && temp[j-m]!=1 && j!=i)
			{	
				temp[j-m]=1;
			}
		}
		
		for(i=m;i<=n;i++)
		{
			if(temp[i-m]!=1){
				printf("%d\n",i);
			}
		}
		free(temp);
	}
	}
	return 0;
}
