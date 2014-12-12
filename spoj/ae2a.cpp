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
	int n,k;
	int v,re;
	si(re);
	LL ans;
	LL pr;
	LL rng,mid;
	LL sum;
	rep(v,re){
		si(n),si(k);
		rng = 5*n+1;
		if(n==1){
			cout<<"16\n";
			continue;

		}
		if(k < n || k > 6*n)
			{
				cout<<"0\n";
				continue;
			}
		if(rng&1){
			//its odd
			mid = n + rng/2;
			//only 1 mid
			sum = (rng/2)*(rng/2 +1) + rng/2+1;

			pr = rng/2 +1 - abs(k - mid);
			
			ans = (100*pr)/sum;
			cout<<pr<<" / "<<sum<<endl;

		}
		else{
			mid = n+rng/2;
			//two mids
			sum = (rng/2)*(rng/2 + 1);
			if(k == mid || k == mid-1)
				pr = rng/2;
			else if(k > mid)
				pr = rng/2+1 - abs(k - mid+1);
				else pr = rng/2+1 - abs(k - mid);
			
			cout<<pr<<"// "<<sum<<endl;
			ans = (100*pr)/sum;

		}
		cout<<ans<<endl;
	}
	return 0;
}

