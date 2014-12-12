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
// #define max(a,b) a>b?a:b
// #define min(a,b) a<b?a:b
#define sqr(x) (x*x)
// int dp[51][51];
int dp[100][2200];
// lim will be less than 2200
int solve(vec &arr,int ind,int lim){
	if(ind == arr.size() || ind<0)
		return 0;
	if(lim<0)lim=0;
	if(ind == arr.size()-1)
	{
		if(lim < 2200 && lim+arr[ind]>=2200)
			return 1;
		else return 0;
	}
	if(dp[ind][lim]!=-1)
		return dp[ind][lim];
	// now we use 2 consecutive elements
	int val=0;
	int mx=0;
	int op2;
	int op1 = solve(arr,ind+1,lim-arr[ind]);
	if(lim+arr[ind] >=2200)
	{
		if(lim+arr[ind]-arr[ind+1]< 2200)
			op2 = 2+solve(arr,ind+2,lim+arr[ind]-arr[ind+1]);
		else op2 = (1<<31);
	}
	else op2 = solve(arr,ind+1,lim+arr[ind]);
	dp[ind][lim] = max(op1,op2);
	return dp[ind][lim];
}

int getMax(vec arr,int start){
	rep(i,arr.size())
		rep(j,2200)
			dp[i][j]=-1;
	int ans = solve(arr,0,start);
	return ans;
}

int main(){
	vector<int> arr;
	int n;
	int x;
	int re;
	si(re);
	rep(v,re){
		si(n);
		arr.resize(n);
		rep(i,n)
			si(arr[i]);
		si(x);
		cout<<getMax(arr,x)<<endl;
	}
	int ar[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
	int val = (sizeof(ar)/sizeof(ar[0]));
	arr.resize(val);
	// cout<<val;
	rep(i,val)
		arr[i]= ar[i];
	x = 1223;
	// cout<<val<<endl;
	cout<<getMax(arr,x)<<endl;;
}