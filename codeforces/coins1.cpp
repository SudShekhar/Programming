// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
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
int val[301],next[100001],vis[100001],in[100001];
int n,t;

void dfs(int v) // will check for loops and add values of dependecies
{
if(vis[v] != 0|| t < 0) {
printf("0\n");
exit(0);
}
vis[v]=1;

if(next[v] == 0) {
			//must[v] = true;
			return;
		}
val[next[v]] += val[v];
t-=val[v];
dfs(next[v]);
return;
}

int main()
{
//take in all the input
// create a graph and add values to the lesser ones
//subtract all those coins which are not at end of dependency list... i.e we must take one of each of which
//for the remaining apply unbounded knapsack
int q,i,j,k;

memset(val,0,sizeof(val));
memset(vis,0,sizeof(val));
memset(next,0,sizeof(val));
memset(in,0,sizeof(val));
si(n);
si(q);
si(t);
for(i=1;i<=n;i++)si(val[i]);
int x,y;
for(i=1;i<=q;i++){
	si(x);
	si(y);
	next[x] = y;
	in[y]++;
}

for(i=1;i<=n;i++)
	if(in[i] == 0)
		dfs(i);

for(i=1;i<=n;i++)
	{
	if(vis[i] !=1) {
	printf("0\n");
	exit(0);
	}
	}
//for(i=1;i<=n;i++) printf("%d ",val[i]);
//printf("\n");

//time for knapsack
int final[100001];
final[0]=1;
for(i=1;i<=n;i++)
	for(j=0;j<=t;j++)
	{
		if(j + val[i] <= t)
			final[j + val[i] ] = (final[j+ val[i] ] + final[j])%mod;
	}
printf("%d\n",final[t]);
return 0;
}

