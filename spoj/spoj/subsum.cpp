#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define trb(c,i) for(type(c.rbegin())i=c.rbegin();i!=c.rend();i++)

void dp(int* v,int **arr,int j,int w)
{
	int i;
	if(j==0)
	{	
		for(i=0;i<w;i++)
		{
			arr[j][i]=
			


int main()
{
	int n,i,j;
	int weight;
	scanf("%d",&n);

//	vector <int> v(n,0);
	int v[n];
	for(i=0;i<n;i++)
	{
		cin>> v[i];
	}

	scanf("%d",&weight);

	int arr[n][weight];
	
	//for(i=n-1;i>0;i--)
//	{
//		dp(v[i],i,arr);
//	}
	dp(v,arr,n,weight);

	return 0;
}


