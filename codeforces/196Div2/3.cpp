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
#define mod 1000000009
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)

LL pw(LL n,int base){
LL ans=1;
int c;
while(base!=0){
c=  base&1;
base/=2;
if(c)ans = (ans*n)%mod;
n = (n*n)%mod;
}
return ans;
}

int main()
{
LL n,m,k;
sl(n),sl(m),sl(k);

LL ans  = ((n-(k-1))*(k-1))/k + k-1;
//cout<<ans<<endl;
if(m<=ans){
	cout<<m<<endl;
	return 0;
}
LL rem = m - ans; // number of coin left



LL temp = ((2* (pw(2,rem)-1))%mod*k)%mod;
ans= (temp  + m - (rem*k)%mod)%mod;
cout<<ans<<endl;




return 0;
}

