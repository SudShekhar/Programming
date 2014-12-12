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


int main()
{
	int arr[101][101];
	int re;
	si(re);int m,n;
	int ans,mx,side;
	rep(v,re){
		si(n),si(m);
		rep(i,n)
			rep(j,m)
				si(arr[i][j]);

		mx=INT_MIN;
		side = min(m,n);
		FOR(l,1,side){
			for(int i=0;i<n-l;i++){
				for(int j=0;j<m-l;j++){
					ans=0;
					for(int k=0;k<=l;k++)
						ans+= arr[i+k][j+k];
					for(int k=0;k<=l;k++)
						ans+= arr[i+l-k][j+k];
					if(l%2==0)
						ans-=arr[i+(l/2)][j+(l/2)];
					mx = max(mx,ans);
				}
			}
		}
		printf("%d\n",mx);
	}
return 0;
}

