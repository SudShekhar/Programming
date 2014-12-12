//sharky's help taken

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
#define mod 1000003
#define sqr(x) x*x

long long power(LL num,int base)
{
	bool odd;
	//int rem;
	int ans = 1;
	while (base != 0)
	{
		if(base&1) odd = true;
		else odd = false;
		//rem = base%2;
		base= base/2;
		if (odd)
			ans = (ans * num) % mod;
		num= (num * num) % mod; 
	}
	return ans;

}

LL ans[1000002];
LL inv[1000002];
void precompute()
{
		
		inv[0]=1;inv[1]=1;
		

	for( LL i=2;i<1000001;i++)
		{
			inv[i]=power(i,mod-2); //store inverse of this num
			
			//ans[i] =   ((((3*(2*i-1))%mod)*ans[i-1])%mod) - ((((i-1)*ans[i-2]) %mod)*inv[i])%mod ;//formula from wikipedia
 		ans[i] = ((mod + (3*(2*i - 1)*ans[i-1])%mod - ((i-1)*ans[i-2])%mod)*inv[i]) % mod;
 		}

}


int main()
{
	int v,re,n,i,j;
	//long long ans;
	si(re);
	ans[0]=1;ans[1]=3;
	int r;
	precompute();
	rep(v,re)
	{
		si(n);
		//printf("%lld\n",ans[n]);
	cout<<ans[n-1]<<endl;
	}	
return 0;
}

