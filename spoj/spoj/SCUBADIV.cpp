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
int dp[22][80][1001];
int ocyl[1001],ncyl[1001],wcyl[1001];
int oweight,nweight,numCyl;
int v,re;
si(re);
int inclusive;
rep(v,re){
	si(oweight),si(nweight);
	si(numCyl);
	FOR(i,1,numCyl+1){
	si(ocyl[i]);
	si(ncyl[i]);
	si(wcyl[i]);
	}
	//taken the weight
	memset(dp,0,sizeof dp);
	rep(i,oweight+1)
		rep(j,nweight+1)
			rep(k,numCyl+1)
				dp[i][j][k]=10000000;
	dp[0][0][0]=0;
	rep(i,oweight+1){
		rep(j,nweight+1){
		//nitrogen and oxygen required
			FOR(k,1,numCyl+1){
			if(i > ocyl[k] && j > ncyl[k])
				inclusive = dp[i-ocyl[k]][j-ncyl[k]][k-1]+wcyl[k];
			else if (i>=ocyl[k] && j <=ncyl[k])
					inclusive = dp[i-ocyl[k]][0][k-1]+wcyl[k];
			else if (i <=ocyl[k] && j >=ncyl[k])
					inclusive = dp[0][j-ncyl[k]][k-1]+wcyl[k];
			else inclusive = wcyl[k];
				//	{
				
			dp[i][j][k] = min(inclusive,dp[i][j][k-1]);
		//	}
			//else dp[i][j][k] = dp[i][j][k-1];
			
			}
		
		}
	
	}
	/*rep(i,oweight+1)
	{
		rep(j,nweight+1)
		{
			cout<<"covering oxygen "<<i<<" nitrogen "<<j<<" == ";
			FOR(k,1,numCyl+1)
				cout<<dp[i][j][k]<<" ";
			cout<<endl;
		}
		cout<<"---------\n";
	}*/
	cout<<dp[oweight][nweight][numCyl]<<endl;
}

return 0;
}

