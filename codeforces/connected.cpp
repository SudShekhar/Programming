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
//matrix arr(500);
vector < vector< pair<int,int> > > arr(502);
int n,m;
int vis[501];int lft,rght;
void dfs( int y )
{
	vis[y] = 1;
	
	for(int itr = 0;itr < arr[y].size();itr++)
			{
				if(arr[y][itr].second < lft || arr[y][itr].second > rght )
					if(vis[arr[y][itr].first] == 0)dfs(arr[y][itr].first);
			}
}

int main()
{

	int i,j,k;
	si(n);si(m);
	
	int x,y;
	for(j=1;j<=m;j++)
	{
		si(x);
		si(y);
		arr[x].pb(mp(y,j));
		arr[y].pb(mp(x,j));
	}
	//created an edge list with the timestamps
	//int k;
	si(k);

	int count = 0;
	
	
	for( j =0;j<k;j++)
	{
	count = 0;
	memset(vis,0,sizeof(vis));
	//setting them all as unmarked

	si(lft),si(rght);
	//queue<int> list;
	for(i=1;i<=n;i++)
	{	//list.clear();
		//write an iterative bfs code
		if(vis[i] == 0){
			dfs(i);
		count++;
		}
	//	else printf("%d is visired\n",i);
	}
	printf("%d\n",count);

	}
	
return 0;
}

