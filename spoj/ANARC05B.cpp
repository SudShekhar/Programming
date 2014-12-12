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
#define MIN(a,b) a>b?b:a
#define MAX(a,b) a>b?a:b
int arr2[10001];
int arr1[10001];
int dp1[10001];
int dp2[10001];
int main()
{
int n1,n2;
while(1){
	si(n1);
	if(n1==0)break;
	rep(i,n1)si(arr1[i]);
	si(n2);
	rep(i,n2)si(arr2[i]);

	int i=0,j=0;
	while(i<n1 && arr1[i]<arr2[j])
		if(i==0)dp1[i++]=arr1[0];
		else dp1[i++]=arr1[i]+dp1[i-1];

	while(j<n2 && arr2[j]<arr1[i])
		if(j==0)dp2[j++]=arr2[0];
		else dp2[j++] = arr2[j] + dp2[j-1];
	

	while(i<n1 && j<n2)
	{
		if(arr1[i]==arr2[j]){
		dp1[i]=( (MAX(dp1[i-1],dp2[j-1])) + arr1[i]);
		dp2[j]=dp1[i];i++,j++;
	}
	while(j<n2 && arr2[j]<arr1[i])dp2[j++]=dp2[j-1]+arr2[j];
	//added j
	while(i<n1 && arr1[i]<arr2[j])dp1[i++]=dp1[i-1]+arr1[i];
	}
	//int ans = MAX(dp1[i-1],dp2[j-1]);
	while(i<n1)dp1[i++]=dp1[i-1]+arr1[i];
	while(j<n2)dp2[j++] = dp2[j-1] + arr2[j];
	
	int ans = MAX(dp1[i-1],dp2[j-1]);
cout<<ans<<endl;
}


return 0;
}

