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
//create a list of factorials, we have a square with one part cut off and can move only right or down.
/*
 so we take ans from (1,1) to (p,B-1) and multiply ir with (p,B) to (N,M);
 p goes from 1 to A.
 we use formula (N+M)C M.. as we can only permute accordingly.
 for factorial we take sequential, inv fact is found by log approach
 */





LL fact[400002];
LL invfact[400002];

LL pw(LL num,int base){
int c;
LL ans=1;
while(base!=0){
	if(base&1)c=1;
	else c=0;

	base/=2;
	if(c==1) ans=(ans*num)%mod;
	num=(num*num)%mod;
	//if(c==1)ans*=num;
}
return ans;
}


void init(){
	fact[0]=1;
	fact[1]=1;
	FOR(i,2,400001)
	{
		fact[i]=fact[i-1]*i;
		invfact[i] = pw(fact[i],mod-2);
	}
	return;
}


int main()
{
int v,re;
si(re);
int N,M,A,B;
int p;
init();
rep(v,re){
	si(N),si(M);
	si(A),si(B);
	LL ans = 0;

	FOR(i,1,N-A)
		ans+= ((fact[i+B-1]*invfact[i])%mod*invfact[B-1])%mod * ((fact[N-i + M-B ]*invfact[N-i])%mod*invfact[M-B] )%mod;

	cout<<ans<<endl;

}
return 0;
}

