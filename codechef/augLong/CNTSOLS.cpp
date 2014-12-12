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
LL pw(LL num,LL base,int md){
LL ans=1;
int c;
while(base!=0){
c = base&1;
base/=2;
if(c)ans = (ans*num)%md;
num = (num*num)%md;
}
return ans;
}

int main()
{
int v,re;
LL upper,n,m,d;

si(re);
LL ans,cnt,sm;
int rem;
LL temp;
LL num[101];
LL val[101];

rep(v,re){
ans=0,cnt=0,sm=0;
sl(upper),sl(d),sl(m),sl(n);
rem=upper%n;
rep(i,n)
	val[i]=pw(i,d,n);//,cout<<i<<" = "<<val[i]<<endl;;

rep(i,n)
	num[i]= (upper/n) + (i<=rem?1:0);// , cout<<i<<" = "<<num[i]<<endl;

rep(i,n)
	rep(j,n)
		rep(k,n)
		{
			if((temp=(val[i]+val[j]+val[k])%n) == m)
			{
			
				ans+= ((((num[i]*num[j])%mod)*num[k])%mod);
				ans%=mod;	
	//		cout<<temp<<" for "<<i<<" "<<j<<" "<<k<<endl;
			}
		}
//got answers for each set of 7.

printf("%lld\n",ans);

}
return 0;
}

