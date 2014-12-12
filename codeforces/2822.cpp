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
#define mod 100000000
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
int dp[101][101][2];
int ans;
int k1,k2;


void calc(int n1,int n2,int prev){

memset(dp,0,sizeof dp);
FOR(i,1,k1+1)dp[i][0][0]=1;
FOR(i,1,k2+1)dp[0][i][1]=1;

FOR(i,1,n1+1)
	FOR(j,1,n2+1){
		
		for(int k=1;k<= (min(j,k2));k++){
			dp[i][j][1] =(( dp[i][j][1] + dp[i][j-k][0])%mod + mod)%mod;
		}
		
		for(int k=1;k<=(min(i,k1)) ;k++){
			dp[i][j][0]= ((dp[i][j][0]+dp[i-k][j][1])%mod +mod)%mod;
		}
}
ans = ((dp[n1][n2][0] + dp[n1][n2][1])%mod+mod)%mod;
		
		
	


}
int main()
{
int n1,n2;
si(n1),si(n2),si(k1),si(k2);

calc(n1,n2,0);
cout<<ans<<endl;
return 0;
}

