#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
#define mod 1000000007
#define sqr(x) x*x
#define rep(i,n) for(int i=0;i<n;i++)
vector<int> arr;
LL ** mul(LL **A,LL **B)
{LL **C;C =(LL**) malloc(sizeof(LL*)*3);
	for(int i=0;i<3;i++)
		C[i] = (LL*) malloc(sizeof(LL)*3);
	for(int i=1;i<3;i++)
		for(int j=1;j<3;j++)
		{	
			C[i][j]=0;
			for(int k=1;k<3;k++)
			{
				C[i][j]+=((A[i][k]*B[k][j])%mod);
				C[i][j]%=mod;
			}
		}
	return C;
}

LL powar(LL num,LL base)
{
	if(base == 0) return 1;
	LL ans = 1;
	bool odd;
	while(base!=0)
	{
		if(base&1)odd = true;
		else odd =false;
		base/=2;
		if(odd)ans*=num;
		if(ans > num )ans%=mod;
		num=sqr(num)%mod;
	}
	return ans;
}
LL ** RaiseTo(LL **arr, LL base)
{
	if(base == 0)
	{
		LL **ans;
		ans =(LL**) malloc(sizeof(LL*)*3);
		for(int i=0;i<3;i++)
			ans[i] = (LL*) malloc(sizeof(LL)*3);
		ans[1][1]=1;ans[1][2]=0;
		ans[2][1]=0;ans[2][2]=1;
		return ans;
	}
	LL **ans = RaiseTo(arr,base/2);
	if (base&1){
		return mul(mul(ans,ans),arr);
	}
	else return mul(ans,ans);
}
long long  fib(LL num)
{
	if(num==0 || num==1)return 1;
	LL **arr;
	arr = (LL**) malloc(sizeof(LL*)*3);
	rep(i,3)
		arr[i]= (LL*) malloc(sizeof(LL)*3);
	arr[1][1]=1;arr[1][2]=1;
	arr[2][1]=1;arr[2][2]=0;
	LL ** ans = RaiseTo(arr,num);
	return (ans[1][1])%mod;
}
int main()
{
	int v,re,i,j,k;
	scanf("%d",&re);	
	long long w,n;
	rep(v,re)
	{scanf("%lld",&n);;if(n==0){cout<<"1\n";continue;}
		w = fib(n-1);
		cout<<powar(2,w)<<endl;
	}
	return 0;
}
