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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
vector< vector<LL> > price,discount,ans;

int main()
{
	int re;
	si(re);
	int n,m;
	LL min,GMIN;
	rep(v,re){
	si(n),si(m);
	ans.clear();
	price.clear();
	discount.clear();


	price.resize(n);
	rep(i,n)price[i].resize(m);
	//memset(price,0,sizeof(price));
	
	discount.resize(n);
	rep(i,n)discount[i].resize(m);
	//memset(discount,0,sizeof(discount));

	rep(i,n)
		rep(j,m)
			sl(price[i][j]);

	rep(i,n)
		rep(j,m)
			sl(discount[i][j]);
	
	ans.resize(n);
	rep(i,n)ans[i].resize(m);

	///memset(ans,0,sizeof(ans));
	min = (LL)INT_MAX*INT_MAX;
	//cout<<min<<endl;
	rep(i,m){
		ans[0][i]=price[0][i];
		if(min > price[0][i])min = price[0][i];
	}
	
	FOR(i,1,n) //i stands for the ith item brought
	{
		GMIN =(LL) INT_MAX*INT_MAX;
		rep(j,m) //each m represents the shop where the last item is bought
			{
			ans[i][j] = MIN(min + price[i][j] , ans[i-1][j] + (MAX(price[i][j] - discount[i-1][j],0)));
			if(ans[i][j] < 0)ans[i][j]=0;
			if(ans[i][j] < GMIN)GMIN = ans[i][j];
			}
		min = GMIN;
	}
			/*
	rep(i,n){
		rep(j,m)printf("%d ",ans[i][j]);
		printf("\n");
	}*/
	GMIN = (LL)INT_MAX*INT_MAX;
	rep(j,m)if(ans[n-1][j]< GMIN)GMIN = ans[n-1][j];
	printf("%lld\n",GMIN);
	}

return 0;
}

