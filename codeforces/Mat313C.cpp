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

int main()
{
long long x,n,m,sum=0,i;

cin>>n;
x = (n-1)/3;
vec arr;
for(i=0;i<n;i++)
{
	cin>>m;
	arr.pb(m);
};
sort(all(arr));
//rep(i,m)cout<<arr[i]<<endl;
LL offset = 3*(n-1)/4;
LL base = 1;
LL factor = 1;
for(i=1;i<=n;i++)
{
	if(i>base + offset){
		factor++;
		base = base+offset;
		offset = (n-base)*3/4;
	}
	sum+=arr[i-1]*factor;
	
}

cout<<sum<<endl;
return 0;
}

