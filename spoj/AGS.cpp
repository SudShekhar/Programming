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
//#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
int mod;
LL pow(LL num,int base)
{
	LL ans=1;
	bool odd;
	while(base){
	if(base&1)odd=true;
	else odd=false;

	if(odd)
		ans = (ans*num)%mod;
	base>>=1;
	if(base==0)break;
	num = (num*num)%mod;
	}
	return ans;
}

int inv(int a,int b){

//if(a==0) return 0;
int x = 0,y=1,u=1,v=0;
int q,r,m,n;
while(a!=0){
q = b/a;
r = b%a;
m = x- u*q;
n = y-v*q;
b=a;
a=r;
x=u;
y=v;
u=m;
v=n;
}
//cout<<" inv "<<x<<endl;
return x;
}
int main()
{
int v,re;
int n,d,a;
LL r;
si(re);
LL ans,temp,temp1;
rep(v,re){
	si(a),si(d),sl(r);
	si(n),si(mod);
	if(n==1){
		printf("%d\n",a%mod);
	continue;
	}
	if(n==2){
	printf("%d\n",(a+d)%mod);
	continue;
	}
	if(n&1) //n is odd
	{
		n++;
		temp = pow(r,n/2);
		temp1 = pow(r,n/2 -1);
		//cout<<temp<<endl;
		ans = ((a*(temp1))%mod + (d* ((temp+ mod-1)%mod) * inv(r-1,mod))%mod)%mod;
		printf("%lld\n",(ans+mod-d)%mod);
	}
	else{
	temp = pow(r,n/2);
	temp1 = pow(r,n/2 -1);
	//cout<<temp<<" temp "<<endl;
	ans = ((a*(temp1))%mod + (d*((temp-1+mod)%mod)* inv(r-1,mod))%mod)%mod;
	printf("%lld\n",ans);
	}
}
return 0;
}

