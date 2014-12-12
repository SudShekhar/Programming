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
#define sqr(x) x*x
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

int bs(int val,int l,int r)
{
//	printf("val %d l %d %d\n",val,l,r);
/*if(r<l)return 0;
int m = (l+r)/2;
int v = sqr(m);
if(v== val) return 1;
else if(v>val) return bs(val,l,m-1);
else return bs(val,m+1,r);
*/
while(l<=r)
{
int m = (l+r)/2;
int v = sqr(m);
if(v == val)return 1;
else if(v>val){
	r = m-1;
}
else l = m+1;
}
return 0;
}
int main()
{
int n;
cin>>n;

int ans = 0;
for(int i=1;i<n+1;i++)
	for(int j=i+1;j<=n;j++)
{
	if(bs(sqr((i)) + sqr((j)) ,j+1,n) )
		ans++;
}

printf("%d\n",ans);

return 0;
}

