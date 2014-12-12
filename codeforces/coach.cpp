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
int vis[48];
int col[48];
matrix arr(48);

int dfs(int v,int color)
{
	//	if(col[v] == color) return 0;
	//	if(col[v]!=0 ) return -1;
		
		printf("colored %d with %d\n",v+1,color);
		vis[v] = 1;
		col[v] = color;
		int val = 0;
		rep(i,arr[v].size())
		{
				
				if(vis[arr[v][i]]==0)
					{
						printf("%d neighbours %d\n",arr[v][i]+1,v+1);
						//perform dfs on unused nodes
						val = dfs(arr[v][i],color);
						if(val == -1) break;
					}
					else if(col[arr[v][i]] !=col[v] ) return -1;
			//colored them all with the same color		
		}
return val;
}


int main()
{
int v,re;
int x,y,j,color;
int n,i,k,m;

	si(n),si(m);
	rep(i,m)
	{
		si(x),si(y);
		arr[x-1].pb(y-1);
		arr[y-1].pb(x-1);
	}
	//created the adjacency list
	rep(i,n)
	{	
		printf("%d: - ",i+1);
		rep(j,arr[i].size())
			printf("%d ",arr[i][j] +1 );
		printf("\n");
	}

	//int vis[48];
	memset(vis,0,48);
	memset(col,0,48);
	color = 1;
	
	for(j=0;j<n;j++)
		if(vis[j] == 0)
			if(dfs(j,color++) == -1)break;
		
if(color <=3){printf("-1\n");
		return 0;
		}
rep(i,n)
	if(col[i] == 1)printf("%d ",i+1);
printf("\n");
rep(i,n)if(col[i]==2)printf("%d ",i+1);
printf("\n");
rep(i,n) if(col[i]!=1 && col[i]!=2) printf("%d ",i+1);	
printf("\n");

return 0;
}

