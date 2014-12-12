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
#define MIN(a,b) a>b?b:a
#define MAX(a,b) a<b?b:a

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007
vector < vector <int> > arr(100001);
int cost[100001];
int vis[100001];
int teleportCost[100001];

void dfs(int ind,int colr){
vis[ind] = colr;

if(teleportCost[colr] < 0 )teleportCost[colr]=cost[ind];
if(cost[ind]>=0)
	teleportCost[colr] = MIN(teleportCost[colr],cost[ind]);

EACH(it,arr[ind]){
if(vis[*it]==0)
	dfs(*it,colr);
}
return;
}



int main()
{
int n,m;
si(n),si(m);
//arr.resize(n); //n planets;
int a,b;
rep(i,m)
{
	si(a),si(b);
	arr[a].pb(b);
	arr[b].pb(a);
}
rep(i,n)si(cost[i+1]);
//have all the info
memset(vis,0,sizeof(vis));
int colr =1;
FOR(i,1,n+1)
{
	if(!vis[i]) //first of its own tree
	{
		teleportCost[colr]=-1;
		dfs(i,colr);
		colr++;
	}
}
int min = INT_MAX;
int sum=0;
FOR(i,1,colr){
sum+=teleportCost[i];
min=MIN(teleportCost[i],min);
}
if(colr < 3)printf("0\n");
else if(min<0)printf("-1\n");
else printf("%d\n",sum + (colr-3)*min);

return 0;
}

