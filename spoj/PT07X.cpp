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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define sqr(x) (x*x)
int dp[100002][2];
//find vertex cover of given graph
vector<int> arr[100002];

int findMinCover(int node, int parent,int parentCovered){
	//1 means parent is uncovered ; 0 means covered
	if(dp[node][parentCovered]!=-1)
		return dp[node][parentCovered];
	int &res = dp[node][parentCovered];
	res = 0;
	if(parentCovered==1){
		//parent is uncovered; means we must select this node
		int ans2=1;
		rep(i,arr[node].size())
			if(arr[node][i]!=parent)
				ans2 += findMinCover(arr[node][i],node,0);
		res = ans2;
	}
	else{
		//parent is covered so we can leave this node or take it
		int ans1=1;
		rep(i,arr[node].size())
			if(arr[node][i]!=parent)
				ans1+=findMinCover(arr[node][i],node,0);

		int ans2 = 0;
		rep(i,arr[node].size())
			if(arr[node][i]!=parent)
				ans2+=findMinCover(arr[node][i],node,1);	
	
		res = min(ans1,ans2);
	}
	return res;
}

int main(){
	int n;
	si(n);
	int a,b;
	
	rep(i,n-1)
	{
		si(a),si(b);
		arr[a].pb(b);
		arr[b].pb(a);
	}	
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	//we will run this for all vertices related to 1
	int ans1,ans2,ans,result;
	//result = 10000000;
	memset(dp,-1,sizeof(dp));
	int j=1;
	 ans1 = 1;
	rep(i,arr[j].size())
		ans1 += findMinCover(arr[j][i],j,0);
	 ans2 = 0;
	rep(i,arr[j].size())
		ans2 += findMinCover(arr[j][i],j,1);	

	ans = min(ans2,ans1);	
	printf("%d\n",ans);
	return 0;
}