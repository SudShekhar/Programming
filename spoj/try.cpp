// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
typedef long long LL;
#define mod 1000000007

int main()
{
	LL arr[1000000];
	arr[0]=1;
	arr[1]=2;
	LL one,two,three,four;
	arr[2]=2;
	one = 2;
	two = 2;
	three = 2;

	//rep(i,1000000)
/*	for(int i=3;i<=1000000;i++)
	{
		arr[i]=(arr[i-1]*arr[i-2])%mod;
	}
	int re,v;
*/	int re,v;
	LL n;
	cin>>re;
	int prev=0;
	rep(v,re)
	{
		cin>>n;
		if(n <prev){
		one = 2;
		two = 2;
		three = 2;
		}
		else prev = 3;
		for(int i =prev;i<=n;i++)
		{
			//four = three;
		three =(one*two) %mod;
		one = two;
		two = three;
		//if(three != arr[i])cout<<"no\n";
		}
		
//		cout<<arr[n]<<endl;
		cout<<three<<endl;
		prev = n;
	}
return 0;
}

