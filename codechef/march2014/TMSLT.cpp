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
#define mod 1000000
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
vec arr(3000001);

int main()
{
	int v,re;
	int n,a,b,c,d,e;
	si(re);
	vector<int> :: iterator it;
	long long ans=0;
	rep(v,re){
		ans=0;
	si(n),si(a),si(b),si(c),si(d);

	arr[0]= d;
	for(int i=1;i<n;i++)
	{
		arr[i] = (((a*((arr[i-1] * arr[i-1]) %mod))%mod) + ((b*(arr[i-1]))%mod) + c)%mod;
	}
	it = arr.begin() + n;
	sort(arr.begin(),it);
	//rep(i,n)
	//	printf("%d ",arr[i]);
	//printf("\n");
	int i;
	for( i=n-1;i>=1;i-=2){
		ans+= arr[i]-arr[i-1];
	}
	if(i == 0)ans+=arr[0];
	printf("%lld\n",abs(ans));
	}

return 0;
}

