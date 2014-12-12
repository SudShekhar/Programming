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
bool isOk(int x,int y,int n){
	return (x>=0 && x<n && y>=0&&y<n);
}

int main()
{
	int n;
	char arr[101][101];
	si(n);
	rep(i,n)
		scanf("%s",arr[i]);
	bool flag=true;
	int diffX[]={-1,1,0,0};
	int diffY[] ={0,0,-1,1};
	int val,nx,ny;
	rep(i,n)
	{
		rep(j,n){
			rep(k,4){
				nx = i+diffX[k];
				ny = j+diffY[k];
				if(isOk(nx,ny,n))
					val+= arr[nx][ny]=='o'?1:0;
			}
			if(val&1)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
			break;
	}
	if(flag)
		printf("YES\n");
	else printf("NO\n");
return 0;
}

