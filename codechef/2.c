#include<stdio.h>

int main()
{
	int in,a,b,i,j,n;
	long long int ans;
	int rep,v;
	scanf("%d",&rep);
	for(v=0;v<rep;v++)
	{
		scanf("%lld",&n);
		ans=4;
		for(i=1;i<n-1;i++)
		{
			ans=(ans*3)%1000000007;
		}
		ans=((ans*3)%1000000007 + (ans*2)%1000000007)%100000007;

		printf("%lld\n",ans);
	}
	return 0;
}
