// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define LL long long
#define si(a) scanf("%d",&a)
#define mod 1000000007
LL arr[1000001];
int main()
{
	int v,re;
	LL ans;
	int n;
	LL a1,a2;
	memset(arr,0,sizeof arr);
	si(re);
	int mx=1;
	arr[0]=1,arr[1]=2;
	rep(v,re){
		si(n);
		a1 = 1;
		a2 = 2;
		//if(n == 0) printf("1\n");
		//else if(n==1)printf("2\n");
		if(n <= mx)
			printf("%lld\n",arr[n]);
		else{
			for(int i =mx+1;i<=n;i++)
			{
				arr[i] = (arr[i-1]*arr[i-2])%mod;
			//	a1 = a2;
			
			}
			mx = n;
			//cout<<ans<<endl;
			printf("%lld\n",arr[n]);

		}

	}
	return 0;
}

