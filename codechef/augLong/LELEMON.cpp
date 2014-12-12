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
int arr[101][105];
int cmd[10001];
int main()
{
int v,re;
int mx;
LL ans;
si(re);int n,m;
int len,ind,IND;
rep(v,re){

	ans=0;
	si(n),si(m);
rep(i,m)si(cmd[i]);
	rep(i,n){
	si(len);
	arr[i][0]=len;
	rep(j,len)si(arr[i][j+1]);
	}

rep(i,m){
ind= cmd[i];
mx=0;
IND=1;
rep(j,arr[ind][0])if(arr[ind][j+1]>mx)mx=arr[ind][j+1],IND = j+1;

arr[ind][IND]=0;
ans+=mx;
}

printf("%lld\n",ans);
}

return 0;
}

