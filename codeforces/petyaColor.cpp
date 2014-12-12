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

LL fact[1000001];

LL pow(LL num,int base)//for num^base
{	
LL ans =1;
int c;
while(base!=0){
	if(base&1)c=1;
	else c=0;

	base/=2;
	num=(num*num)%mod;
	if(c==1)ans= (ans*num)%mod;
}
return ans;
}

void int(){
fact[0]=1;
fact[1]=1;

FOR(i,2,1000001)fact[i]=(fact[i-1]*i)%mod;

}



int main()
{
	init();
int n,m,k;
si(n),si(m),si(k);

if(n>k)//choose 2*k to be distinct and let rest be anythin
{
LL ans = (((fct(n,k) * fct(n,k))%mod )* pow(k,m*n - 2*k))%mod;
cout<<ans<<endl;
}
else{
// if k > n, choose any n colors and use them

LL ans = ((fct(k,n) *fct(k,n))%mod)*pow(n,(m-2)*n );	

}
return 0;
}

