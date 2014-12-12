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
int mod = 1000000009;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
vector< vec> mat(501);

int n,m,start,dest;
int arr[501][501];
int dis[501];
int parent[501];
int vis[501];

struct orderby{

	bool operator()(int const &a,int const &b){
		
		return (dis[b]==-1 || dis[a]<dis[b]);
	}
};

void bs(int v){
	priority_queue<int,vec,orderby> q;
	memset(vis,0,sizeof vis);
	q.push(v);//irst node at zero dist
	int aux,l;
	vis[v]=2; //2 means in queue
	while(!q.empty()){

		aux = q.top();
		q.pop();
		vis[aux]=1;
	//	cout<<"checking "<<aux<<" with "<<dis[aux]<<endl;
		//if(vis[aux])continue;
		//vis[aux]=1;
		//if(aux == dest)break;
		rep(i,mat[aux].size())
		{
			
			l = dis[aux] + arr[aux][mat[aux][i]];
			if((l < dis[mat[aux][i]] && arr[aux][mat[aux][i]]!=0)){
				parent[mat[aux][i]]=aux;
				dis[mat[aux][i]]=l;
				if(vis[mat[aux][i]] !=1)
					q.push(mat[aux][i]),vis[mat[aux][i]]=1;
			}

		}

	
	}
//	cout<<"----------------------------\n";
	//return ans;
}

/*

   void dfs(int v){
   vis[v]=1;
   int next=-1;
   int mn = INT_MAX;
   rep(i,mat[v].size())
   if(!vis[mat[v][i]])
   if(arr[v][mat[v][i]]!=0 && mat[v][i]!=v && arr[v][mat[v][i]]+dis[v] < dis[mat[v][i]])
   {
   dis[mat[v][i]]=arr[v][mat[v][i]]+dis[v];
   parent[mat[v][i]] = v;
   if(dis[mat[v][i]]<mn)mn=dis[mat[v][i]],next = mat[v][i];
   }
   if(next!=-1)
   dfs(next);
   return;
   }

 */

int main()
{
	int initmax;
	int x,y,z;
	int vert,par;
	while(1){

		si(n),si(m);
		if(n==0) break;
		rep(i,n)mat[i].clear();

		si(start),si(dest);
		memset(arr,0,sizeof arr);
		rep(i,m){
			si(x),si(y),si(z);
			mat[x].pb(y);
			arr[x][y]=z;
		}
		//memset(dis,mod,sizeof dis);
		fill(dis,dis+n,mod);
		//	memset(vis,0,sizeof vis);
		memset(parent,-1,sizeof parent);
		//parent[0]=-1;
		dis[start]=0;
		bs(start);
		vert = dest;
		par = parent[vert];
		while(par!=-1){
			arr[par][vert]=0;
			vert = par;
			par=parent[par];

		}	
		initmax = dis[dest];
		 //cout<<"initial it was "<<initmax<<endl;
		if(initmax!= mod)
		while(1){
		//	memset(dis,mod,sizeof dis);	
		fill(dis,dis+n,mod);
			memset(parent,-1,sizeof parent);
			//memset(vis,0,sizeof vis);

			//	parent[0]=-1;
			dis[start]=0;

			bs(start);
			if(dis[dest]==mod)break;
			if(dis[dest]== initmax){
				vert = dest;
				par = parent[vert];
				while(par!=-1){
					arr[par][vert]=0;
					vert = par;
					par=parent[par];

				}
			}
			else break;
		}
		//cout<<mod<<endl;

		if(dis[dest] == mod)
			dis[dest]=-1;
		printf("%d\n",dis[dest]);
	}

	return 0;
}

