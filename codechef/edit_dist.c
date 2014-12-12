#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define f(i,start,end) for(i=start;i<end;i++)
#define SI(a) scanf("%d",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define SF(a) scanf("%f",&a)
#define LL long long
int arr[100][100];


int main()
{	int n;
	char str1[100],str2[100];
	SI(n);
	SS(str1);
	SS(str2);
	int cost,i,j,k;
	SI(cost);
	
	f(i,0,n){
		f(j,0,n)
			arr[i][j]=0;
	}
	f(i,1,n)
	{
		arr[i][0]=i;
		arr[0][i]=i
	}
	f(i,1,n){
		f(j,1,n)
		{
			int  
	return 0;
}

