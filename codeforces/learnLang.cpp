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
int vis[101];
int m,n;
int mat[101][101];

void dfs(int v)
{

	vis[v] =1;
	for(int i=1;i<=m;i++)
	{
		if(mat[v][i] == 1)//if he speaks that language
		{
		//	printf("%d speaks %d\n",v,i);
			for(int j=1;j<=n;j++)
				if(mat[j][i] == 1 && !vis[j] && j!=v)
				{
		//			printf("so does %d\n",j);
					dfs(j);
				}
		}
	}
	
}
int main()
{
//int mat[101][101];
memset(mat,0,sizeof(mat));
memset(vis,0,sizeof(vis));
int i,j,k;
si(n);
si(m);
int x,y;
bool flag=true;
for(i=1;i<=n;i++)
{
	si(y);
	if(y!=0)flag = false;
	rep(k,y){
	si(x);
	mat[i][x] = 1;
	}
	//mat[i][x] = 1;
}
if(flag){
printf("%d\n",n);
return 0;
}
int count = 0;
//for(i=1;i<=n;i++)
	
for(i=1;i<=n;i++)
{
	if(vis[i] == 0) {
//		printf("poor  %d\n",i);
		dfs(i);
		count++;
	}
}

printf("%d\n",count-1);
return 0;
}

