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
int arr[200];
int main()
{
int n;
si(n);
int l=-1;
int numOne=0;
rep(i,n){
	si(arr[i]);
	if(arr[i]==1)numOne++;
}
rep(i,n){
	if(arr[i]==0)
	{
	l=i;break;
	}

}
int ans=0;
if(l==-1)cout<<n-1<<"\n";
else{
ans=numOne;
int mx=0;
int zero=0;
int rem[n+1];

rem[n-2]=(arr[n-1]==0?0:1);
for(int i=n-3;i>=0;i--){
rem[i]=rem[i+1] + arr[i+1]==0?0:1;
}
rem[n-1]=0;

FOR(i,l,n){
	
if(arr[i]==0)zero++;
	else zero--;
if(zero<0)zero=0;

if(zero >mx)mx =zero;

}

if(mx>0){
	cout<<ans+mx<<endl;
}
else cout<<ans<<endl;

}
return 0;
}

