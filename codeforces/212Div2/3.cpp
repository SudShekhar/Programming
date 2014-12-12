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
int arr[5000];
int sm[10001];
si(n);
int mx=0,mn=0,cnt=0,cnt1=0;
int as=0;
int i1,i2;
rep(i,n)
{
	si(arr[i]);
	sm[i]=i-arr[i];
	if(sm[i] < mn)mn = sm[i],cnt=1,i1=i;
	else if(sm[i]==mn)cnt++;

	if(sm[i]>mx)mx=sm[i],cnt1=1,i2=i;
	else if(sm[i]==mx)cnt1++;

	as+= (max(sm[i],0));
}
arr[i1] = (arr[i1]+arr[i2]) - (arr[i2]=arr[i1]);
as=0;
//rep(i,n)cout<<arr[i]<<" ";
//cout<<endl;
rep(i,n){
as+=(max((i-arr[i]),0));
}
//rep(i,n)cout<<sm[i]<<" ";
//cout<<endl;
///cout<<as<<endl;

//as -= abs(abs(mx)-abs(mn));
cout<<as<<" "<<cnt1*cnt<<endl;
return 0;
}

