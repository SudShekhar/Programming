#include<iostream>
#include<stdlib.h>
#define f(i,start,end) for(i=start;i<end;i++)
using namespace std;
int comp(const void *a,void const *b){
	return *(int*)b - *(int*)a;
}

int main()
{	long long sum;
	int rep,v,n,k;
	int *arr;
	int i;
	cin>>rep;
	f(v,0,rep)
	{
		cin>>n>>k;

		arr= new int[n];

		f(i,0,n){
		cin>>arr[i];
		}

		qsort(arr,n,sizeof(int),comp);
		sum=0;
		f(i,0,k)
		{
			sum+=(long long )arr[i];
		}
		cout<<sum<<endl;
		delete []arr;
	}
	return 0;
}
