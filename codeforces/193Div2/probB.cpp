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
#define MAX(a,b) a>b?a:b

#define swp(a,b)a= (a+b)-(b=a)
int main()
{

	int n,k;
	LL arr[200001];
	int firstSeg;
	LL dp[200001];
	si(n);
	si(k);
	rep(i,n)sl(arr[i]);
	int sseg,fseg;
	LL ssum;
	dp[0]=0;
	rep(i,k)dp[0]+=arr[i];//first k elements in dp[1]
	FOR(i,1,n-k+1)dp[i]=dp[i-1]-arr[i-1]+arr[k+i-1];//dp goes ro n-k
	LL fsum =0;
	int ind=0;
	LL  maxsum =0;
	FOR(i,k,n-k+1){

	if(dp[i-k]>fsum){
	fsum = dp[i-k];
	ind = i-k;
	}
	
	if( dp[i] + dp[ind] > maxsum){
	maxsum = dp[i] + dp[ind];
	fseg = ind;
	sseg = i;
	}
	}
	
	printf("%d %d\n",fseg+1,sseg+1);


	return 0;

}

