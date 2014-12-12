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
int n,depth;
vec arr[100001];
int vis[100001];
bool flag;
int ans[100002];
int len;
void dfs(int v,int d,int p)
{
	vis[v] = d;
	rep(i,arr[v].size())
	{
		if(flag == true){
		len --;
		if(len>=0)printf(" %d",v);
		return;
		}
		
		if(!vis[arr[v][i]])
			dfs(arr[v][i],d+1,v);
		else{
		if(vis[v] - vis[arr[v][i]] >= depth){
		//we have found the cycle
		len = vis[v] - vis[arr[v][i]]+1;
		printf("%d\n",len);
		printf("%d",v);
		len--;
		flag = true;
		return;
		}
		}
		
		
	}
	if(flag == true){
		len --;
		if(len>=0)printf(" %d",v);
		return;
		}
return;
}


int main()
{
	len=0;
int x,y;	int m,i,j,k;
si(n);
si(m);
si(depth);
for(i=0;i<m;i++)
{
	si(x); si(y);
	arr[x].pb(y);
	arr[y].pb(x);
}
flag = false;
dfs(1,1,0);
printf("\n");
	
return 0;
}

