#include<iostream>
#include<stdio.h>
#define N 1000000007
#define MOD 1000000007
#define square(x) x*x

using namespace std;
/*long long int exp(int base,long long int power)
{	long long int ans;

	if(power==0)return 1;
	if(power==1)return base;
	if(power%2==0)
	{
		ans=exp(base,power/2)%N;
		return square((ans%N))%N;
	}
	
	else {
		return (base * (square(exp(base,power/2)%N)))%N;
	}

}
*/	
int exp(int n,long long p)
{
	if(p==0)
		return 1;
	long long sn=(exp(n,p/2))%MOD;
	if(p&1)
		return ((sn*sn)%MOD*n)%MOD;
	else
		return (sn*sn)%MOD;
}
int main()
{
	int rep,v;
	long long n;
	scanf("%d",&rep);
	int i,j;
	    long long ans;

	for(v=0;v<rep;v++)
	{
		scanf("%lld",&n);
	//	cin>>n;
		ans= exp(3,n)+((n%2==0)?3:-3);
		if (ans<0)ans+=N;
		if(n==1)cout<<4<<endl;
		else
		{
	//	cout<<exp(3,n)<<endl;
//		printf("%lld\n",ans%N);
		cout<<ans%N<<endl;
		}
	}
	return 0;
}

