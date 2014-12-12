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
//use Floyd Warshall algo
int mat[501][501];
int inf;
int n;
void floyd(){
int a,b,c;
	int i,j,k;
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			a= mat[i][j];
			b = mat[i][k];
			c = mat[k][j];
			/*if(j == inf)a = c = mod;
			if(k == inf) b = c = mod;
			if( i == inf) a = b= mod;
			if(j == k ) c= 0;
			if(i == k) b = 0;;
			if(i== j) a=0;
			*///if(mat[i][j] > mat[i][k]  + mat[k][j])
			if(a > b +c )	
			mat[i][j] = mat[i][k] + mat[k][j];
		}
//created the floyd effect;
LL ans =0;
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		if(mat[i][j] < mod)ans+=mat[i][j];
//printf("%d\n",ans);
cout<<ans<<endl;
}

int main()
{
	int i,j,k,l,m;
	si(n);
	for(i=1;i<=n;i++)
	{
		
			rep(l,n)
			{
				si(m);
				mat[i][l+1] = m;
			}
	}
	//created the graph

	rep(i,n)
	{
		si(m);
		floyd();
		inf = m;
		rep(i,n)
		{
			mat[i+1][m] = mod;
			mat[m][i+1] = mod;
		}
		mat[m][m] = 0;
	
		//floyd();
	}

return 0;
}

