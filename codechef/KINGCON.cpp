/*
 Forgot to clear the push_back array after each iter.
	inspired by natani's blog.. articulation points logic
 */

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
#define MIN(a,b) a>b?b:a
//Find articulation points in a given graph
int globalTime;
matrix arr(3003);
int vis[3002];
int Time[3002],parent[3002];
int HighestNeighbourTime[3002];
LL ans;
bool imp[3002];

void Articulate(int v){
	globalTime++;
	Time[v] = globalTime;//its own discovery time
	HighestNeighbourTime[v] = globalTime; //lowest discovery time of neighbour
	vis[v]=1;
	int numChilds = 0;
	for(int i=0;i<arr[v].size();i++){
	if(arr[v][i] == parent[v])continue;
	if(vis[arr[v][i]]) ///it has been visited ==> must be a higher level node
	{
		HighestNeighbourTime[v] = MIN(HighestNeighbourTime[v],Time[arr[v][i]]);
	}
		
	else //(!vis[arr[v][i]])//this child isn't visited
	{
		parent[arr[v][i]] = v;
	
		Articulate(arr[v][i]); //visited it
		HighestNeighbourTime[v] = MIN(HighestNeighbourTime[v],HighestNeighbourTime[arr[v][i]]);
		if(HighestNeighbourTime[arr[v][i]] >=Time[v] && parent[v]!=-1) //this is its highest placed neighbour
		{
			if(!imp[v])ans++,imp[v]=true;
		}
		numChilds++;
	}	

	}

	if(numChilds > 1 && parent[v]==-1)
		if(!imp[v])ans++,imp[v]=true;
	return;
}

int main()
{
int v,re;
si(re);
int n,m,k,a,b;

rep(v,re)
{
si(n),si(m),si(k);
rep(i,n)arr[i].clear();
globalTime = 0;
ans=0;
rep(i,m)
{
	si(a),si(b);
	arr[a].pb(b);
	arr[b].pb(a);
}
memset(vis,0,sizeof(vis));
memset(parent,-1,sizeof(parent));
memset(imp,false,sizeof(imp));

Articulate(0);
int answer=0;
//rep(i,n)if(imp[i])answer++;
printf("%d\n",k*ans);
}
return 0;
}

