#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000007
int exp(int n,int p)
{
	if(p==0)
		return 1;
	long long sn=exp(n,p/2)%MOD;
	if(p&1)
		return ((sn*sn)%MOD*n)%MOD;
	else
		return (sn*sn)%MOD;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cout<<exp(3,i)<<endl;
	}
}
