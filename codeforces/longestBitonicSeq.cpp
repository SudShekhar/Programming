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

int main()
{
int n;
si(n);
int arr[1000];
rep(i,n)si(arr[i]);

int LIS[1001]; ///increasing sub from start
int LID[1001]; ///decreasing sub till end
rep(i,n)LID[i]=LIS[i]=1;
int back[1001],fwd[1001];
FOR(i,1,n)
	FOR(j,0,i)
	{
		if(arr[i]>arr[j] && LIS[i] < LIS[j]+1)
			LIS[i] = LIS[j]+1,back[i]=j;
	}

//LID[n-1] = 1;
for(int i = n-2;i>=0;i--)
	for(int j = n-1;j>i;j--)
		if(arr[i] > arr[j] && LID[i]<LID[j]+1)
			LID[i] = LID[j]+1,fwd[i]=j;

	

int max=0,ind=0;
rep(i,n)
	if(LIS[i] + LID[i]-1 > max)
	max = LIS[i]+LID[i]-1,ind = i;


printf("%d\n",max);	

return 0;
}

