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
int n;
int arr[1001];
int vis[1000001][2];
memset(vis,0,sizeof vis);
int x;
si(n);
int back =-1;
int sign;
rep(i,n)si(arr[i]);
int flag=0;
int start,end;
FOR(i,1,n-1){
start = min(arr[i],arr[i+1]);
end = max(arr[i],arr[i+1]);

rep(j,i){
	if(arr[j]>start && arr[j]<end && (arr[j+1]>end || arr[j+1]<start))
	{
		flag=1;
		break;
	}
	if((arr[j]< start || arr[j]>end) && (arr[j+1]<end && arr[j+1]>start))
	{
		flag=1;
		break;
	}
}
}


if(flag==0)cout<<"no\n";
else cout<<"yes\n";
return 0;
}

