#include<stdio.h>
#include<stdlib.h>

int main()
{
	int v,rep,m,n,a;
	int i;
	int j;
	scanf("%d",&rep);
	int count;
	for(v=0;v<rep;v++)
	{
		scanf("%d %d",&n,&m);
		int *arr;
		a=m>n?(n+1):m;
		arr=(int *)malloc(sizeof(int)*a);
		
		for(i=0;i<a;i++)arr[i]=0;

		for(i=1;i<=n;i++)
		{
			arr[(i%m)]++;
		}
/*	for(i=0;i<a;i++){
		if(arr[i])printf("[%d]=%d\n",i,arr[i]);
	}
*/	
		count=arr[0]*(arr[0]-1)/2;
/*	for(i=1,j=a-1;i<=j;i++,j--)
	{
		if(i==j && (i+j)%m==0){
			count+=arr[i]*(arr[i]-1);}
		else if((i+j)%m==0)
		count+=arr[i]*arr[j];
	}
*/
	for(i=1,j=a-1;i<=j;)
	{
		if((i+j)%m==0){
			if(i!=j)count+=arr[i]*(arr[j]);
			else count+=arr[i]*(arr[i]-1)/2;
			i++;j--;	
		}
		else if(i+j>m)j--;
		else i++;
	}

	
	printf("%d\n",count);
	free(arr);
	}
	return 0;
}
