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
matrix arr(100001);
int vis[100001];
int val[100001];
LL decr[100001],incr[100001];

int n;
void dfs(int v,int p)
{
	int i,z;
	vis[v] = 1;
	//if(out[v] == 0)return val[v];
	LL  min = mod ,max=-mod;
	for(int j=0;j<arr[v].size();j++)
	{
		int i = arr[v][j];
		if(i==p)continue;
		dfs(i,v);
	if(incr[v] < incr[i]) incr[v] = incr[i];//parent will decrease atleast the max of all number
	if(decr[v] < decr[i])decr[v] = decr[i];//parent will increase atleast the min of all
	}
	LL k = val[v] - decr[v] + incr[v];
	if(k > 0) decr[v]+=k;
	else  incr[v] -= k;
//reduce the inc factor accordingly
}

int main()
{
int i,j,m,k;
si(n);int x,y;
for(i=0;i<n-1;i++)
{
	si(x);
	si(y);
	arr[x].pb(y);
	arr[y].pb(x);
	//out[x]++;
}

for(i=1;i<=n;i++)
	si(val[i]);

dfs(1,0);	
//printf("%d\n",dfs(1));
printf("%I64d\n",decr[1]+incr[1]);

return 0;
}

