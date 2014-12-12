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
matrix arr(1001);
int n;
int vis[1001];
int depth[1001];
vector< pair <int,int> > ans;
int road;
int dfs(int v){
if(depth[v]>2){
return 1;
}
vis[v]=1;
road++;int ind;
int flag;
FOR(i,1,n+1){
	 flag=0;
	if(vis[i])continue;
	 rep(j,arr[v].size()){
	if(i==arr[v][j]){
		ind=i;
		flag=1;break;
		}
	}
	if(flag==0){
		ind =i;
		depth[ind]=depth[v]+1;
		//ans.pb(mp(v,ind));
		dfs(ind);
		ans.pb(mp(v,ind));
	}
}
return 0;
}


int main()
{
int m;
si(n),si(m);
int x,y;

rep(i,m)
{	si(x),si(y);
	arr[x].pb(y);
	arr[y].pb(x);
}
int numRoads=0;
memset(vis,0,sizeof(vis));
memset(depth,0,sizeof(depth));
depth[1]=0;
road=-1;
dfs(1);
numRoads=road;
cout<<numRoads<<endl;
rep(i,ans.size()){
cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

return 0;
}

