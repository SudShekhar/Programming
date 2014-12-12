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
//need to find shortest path keeping in mind that cost doesn't exceed given N

struct node{
	int pos,len,cost;
	node(){}
	node(int _pos,int _len, int _cost)
	{
		pos = _pos,len = _len, cost = _cost;
	}
	bool operator < (node a) const{
		return ((a.len < len) || (a.len == len && a.cost < cost));
	}
} aux;

int main()
{
	int v,re;
	int n,k,r;
	int length[101],price[101],vis[101][10001];
	//length and price between node and node
	//vis with node and cost (100*100)
	matrix pc(101),lt(101),to(101);
	si(re);
	int lth,p,dest;int src;

	rep(v,re){
		si(k),si(n),si(r);
		memset(vis,0,sizeof vis);
		rep(i,100){
			pc[i].clear();
			lt[i].clear();
			to[i].clear();
		}
		rep(i,r){
			si(src),si(dest),si(lth),si(p);
			src--,dest--;

			to[src].pb(dest);
			pc[src].pb(p);
			lt[src].pb(lth);
		}
		priority_queue <node> q;
		q.push(node(0,0,0));
		int ans=-1;
		while(!q.empty()){
			aux = q.top();
			q.pop();
			//cout<<"checking"<<aux.pos<<" at len "<<aux.len<<" wit "<<aux.cost<<endl;
			if(vis[aux.pos][aux.cost]==1)continue;
			vis[aux.pos][aux.cost]=1;
			if(aux.pos == n-1)
			{
				ans = aux.len;
				break;
			}
			for(int i = 0; i<to[aux.pos].size();i++)
			{
				lth = lt[aux.pos][i] + aux.len;
				p = pc[aux.pos][i] + aux.cost;
				dest = to[aux.pos][i];
				//ound the three road vars
				if(p <= k)
				{
					q.push((node(dest,lth,p)));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

