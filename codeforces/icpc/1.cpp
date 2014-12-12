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


// map<int, vector<int> > mp;
// vector<int> glob(100000000,0);
int glob[100000000];
int main()
{
	string num;
	int m,q,l;
	// scanf("%s",num.c_str());
	cin>>num;
	si(q);
	int n;
	int ans=0;
	int cand=0;
	vector< pair<int,int> > mods(5);
	rep(v,q)
		si(mods[v].first),si(mods[v].second);
	int lcmMod=1;
	int ind=0;
	long long tillNow;
	int start=0;
	n = num.size();
	while(ind < q){
		// lcmMod=1;
		memset(glob,0,sizeof glob);
		tillNow=1;
		while(tillNow < 10000000 && ind < q)
			tillNow *= mods[ind].first,ind++;
		if(tillNow > 100000000)
			tillNow/=mods[ind-1].first,ind--;
		//will run the algo for this length
		// mp[tillNow].resize(tillNow,0);
		rep(i,n){
			cand=0;
			FOR(j,i,n)
			{
				cand = (cand*10 + (num[j]-'0'))%tillNow;
				glob[cand]++;
			}
		}
		while(start<ind){
			ans=0;
			rep(i,tillNow)
				if(i% mods[start].first == mods[start].second)
					ans+=glob[i];
			printf("%d\n", ans);
			start++;		 
		}
	}
	return 0;
}

