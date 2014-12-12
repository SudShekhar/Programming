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
int dp[1001][11],bck[1001][11];
int m;
char str[11];
scanf("%s",str);
int val[11];
si(m);
FOR(i,1,11)
	if(str[i-1]=='0')val[i]=0;
	else val[i]=1;

FOR(i,1,11)
	dp[0][i]= val[i]==0?-1:i , bck[0][i]=-1;
//rep(i,11)cout<<dp[0][i]<<" ";
//cout<<endl;
//first row
int bk,min,diff;
FOR(j,1,11){
	if(val[j]==0){
	dp[1][j]=-1;
	continue;
	}
	min = INT_MAX;
	diff=j;
	FOR(k,1,11)
		if(dp[0][k]!=-1 && dp[0][k]<diff && k!=j)diff=min=k,bk=k;
	if(min!=INT_MAX)dp[1][j]=j,bck[1][j]=bk;
	else dp[1][j]=-1;
}

rep(i,11)cout<<dp[0][i]<<" ";cout<<endl;
rep(i,11)cout<<dp[1][i]<<" ";cout<<endl;
FOR(i,2,m){
	//each move
	FOR(j,1,11){//j is present move
	if(val[j]==0){
	dp[i][j]=-1;
	continue;
	}
		min = INT_MAX;
	diff=j;
	FOR(k,1,11)
		if(dp[i-1][k]!=-1 && (dp[i-1][k] - dp[i-2][bck[i-1][k]] < diff  && dp[i-1][k]< dp[i-2][bck[i-1][k]] + j) && k!=j)min=dp[i-2][bck[i-1][k]],bk=k,diff=dp[i-1][k]-min;
	if(min!=INT_MAX)dp[i][j]=min+j, bck[i][j]=bk;
	else dp[i][j]=-1;
	
	}
}	
rep(j,m) {
	rep(i,11)cout<<dp[j][i]<<" ";cout<<endl;}


//final setting
int ind =-1;
int t = m-1;
int ans[1001];
int l=0;
FOR(i,1,11)
	if(dp[m-1][i]!=-1){
		ind=i;
		break;
	}
if(ind== -1)cout<<"NO\n";
else{
cout<<"YES\n";

while(bck[t][ind]!=-1)ans[l++]=ind,ind=bck[t][ind],t--;
ans[l++]=ind;
for(int i=l-1;i>=0;i--)cout<<ans[i]<<" ";
cout<<endl;
}
return 0;
}

