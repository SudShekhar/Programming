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
LL mat[100][100];
int n,m;

void floydWarshal(){
	rep(k,n)
		rep(i,n)
			rep(j,m)
			//if(mat[i][k]!=INF && mat[k][j]!=INF && mat[i][k] + mat[k][j] < mat[i][j])
			if( mat[i][k] + mat[k][j] < mat[i][j])
				mat[i][j] = mat[i][k] + mat[k][j];
return;
}

int main()
{
si(n),si(m);
rep(i,n)
	rep(j,m){
	scanf("%lld",&mat[i][j]);
	if(mat[i][j]==-1)mat[i][j]=INF;
	}
floydWarshal();

rep(i,n)
{	rep(j,m)
	{	if(mat[i][j]==INF)printf("INF ");
		else printf("%lld ",mat[i][j]);
	}
	printf("\n");
}

return 0;
}

