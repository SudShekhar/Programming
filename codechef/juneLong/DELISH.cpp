// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pil(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define MIN(x,y) x>y?y:x
#define MAX(x,y) x>y?x:y

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007
LL p1,prev,arr[10001];
int ind2,ind1;
LL MAX[10002],MAXRev[10002],MIN[10002],MINRev[10002];

LL findmin(int l,int r)
{	
	LL gmn = mod;
	int i,i1,i2;
	LL mn;
	mn=mod;
	for(i=l;i<=r;i++)
	{
		if(arr[i] <= arr[i]+mn){
		mn = arr[i];
		//i1 = i2= i;
		}
		else mn = arr[i]+mn;//i2=i;
		if(mn < gmn) {
		gmn = mn;
		}
		MIN[i]=gmn;
	}
}


LL findminR(int l,int r)
{	LL gmn = mod;
	int i;
	LL mn;
	mn=mod;
	for(i=r;i>=l;i--)
	{
		mn=MIN(arr[i],arr[i]+mn);
		if(mn < gmn) gmn = mn; 
		MINRev[i-1]=gmn;
	}
//	return gmn;

}

LL findmaxR(int l,int r)
{

	//if( l < ind ) return prev;
	LL gmx = -mod;
	int i;
	LL mx = -mod;
	for(i=r;i>=l;i--)
	{
		if(arr[i] > arr[i]+mx){
		mx=arr[i];
		//ind = i;	
		}
		else mx = arr[i]+mx;
		if(mx > gmx)gmx = mx;

		MAXRev[i-1]=gmx;
	}
}

LL findmax(int l,int r)
{
	LL gmx = -mod;
	int i;
	LL mx = -mod;
	for(i=l;i<=r;i++)
	{
		if(arr[i] > arr[i]+mx){
		mx=arr[i];
		}
		else mx = arr[i]+mx;
		
		if(mx > gmx)gmx = mx;
		
		MAX[i]=gmx;
	}
}

int main()
{
int v,re,n;

si(re);
rep(v,re)
{
	si(n);
	rep(i,n)scanf("%lld",&arr[i]);
	int l1 = 0;int r2=n-1;
	LL a,b,c;
	LL ans = -mod;
	
//	ind2 = -1,ind1=-1;
	findmin(l1,r2);
	findmax(l1,r2);
	findminR(l1+1,r2);
	findmaxR(l1+1,r2);
	MAXRev[n-1]=0;MINRev[n-1]=0;
	//rep(k,n)cout<<MIN[k]<<" ";cout<<endl;	
//	rep(k,n)cout<<MINRev[k]<<" ";cout<<endl;	
//	rep(k,n)cout<<MAX[k]<<" ";cout<<endl;	
//	rep(k,n)cout<<MAXRev[k]<<" ";cout<<endl;	
	rep(k,n-1)
	{
		if(MAX[k] - MINRev[k] > ans)ans = MAX[k]-MINRev[k];
		if(MAXRev[k] - MIN[k] > ans)ans = MAXRev[k] - MIN[k];
	}


	printf("%lld\n",ans);
}
return 0;
}

