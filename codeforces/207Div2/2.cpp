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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
int n;
int col[100001];
int vis[100001];
vector <vec > arr(100001);

int dfs(int v,int color){
//cout<<"set "<<v<<" to "<<color<<endl;
col[v] = color;
vis[v]=1;
int toSend = (color+1);
if(toSend == 4)toSend=1;

rep(i,arr[v].size()){
if(!vis[arr[v][i]])
{
	while(dfs(arr[v][i],toSend)){
	toSend++;
	if(toSend==4)toSend=1;
		if(toSend==color)return 1;
	}
}
else{
if(col[arr[v][i]] == col[v])return 1;
}
}

return 0;
}




int main()
{
int m;

si(n),si(m);
int x,y,z;
rep(i,m){
si(x),si(y),si(z);
x--,y--,z--;
arr[x].pb(y);
arr[x].pb(z);

arr[z].pb(x);
arr[z].pb(y);

arr[y].pb(z);
arr[y].pb(x);
}

memset(col,0,sizeof col);
memset(vis,0,sizeof vis);
int scol;
rep(i,n){
	scol= 1;
if(col[i]==0)
while(dfs(i,scol))scol++;
}
rep(i,n)cout<<col[i]<<" ";
cout<<endl;
return 0;
}

