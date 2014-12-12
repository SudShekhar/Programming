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

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)


int main()
{

	int n;
	int ar[100001],arr[100001];
	si(n);
	rep(i,n)si(ar[i]);
	sort(ar,ar+n);
	arr[0]=ar[0];
	int j=1;
	FOR(i,1,n)
		if(ar[i]!=ar[i-1])arr[j++]=ar[i];
	n=j;
		
	int start,end,base;
	base=1;
	while(base<arr[n-1])base*=2;
	if(base!=arr[n-1])base/=2;
	end=n-1;
	start=n-1;
	int i = n-1;
	while(arr[i]>base)i--;
	cout<<end-i<<endl;
	for(;i<end;i++)cout<<i<<endl;
	return 0;
}

