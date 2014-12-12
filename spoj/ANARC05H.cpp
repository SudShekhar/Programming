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
char s[30];
int dp[30][230];
int len;
/*
   this is a 2D dp problem.
   had difficulty with this.
   we carry out memoization of the previous value and store it
   the forward set is calculated and added to the previous score.
   */
int cal(int pos,int prev)
{
	if(pos==len)return 1;
	int &val = dp[pos][prev];
	if(val!=-1){//printf("yo\n");
		return val;
	}
	val=0;
	int sum =0;
	for(int i=pos;i<=len;i++)
	{
	sum+=s[i] -'0';
	if(sum>=prev)
		val+=cal(i+1,sum);
	}
	return val;
}


int main()
{

	//char s[30];
	int num = 1;
	while(1){
	scanf("%s",s);
	if(s[0]=='b')break;
	len = strlen(s);
	memset(dp,-1,sizeof(dp));
	printf("%d. %d\n",num++,cal(0,0));
	}
return 0;
}

