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
typedef long long int LL;
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)


int main()
{
LL arr[100005];
LL len=0;
LL n,x;
LL ans=0;
sl(n);
LL tmp;
LL tst;
rep(i,n){
	sl(x);
	if(x<0)arr[len++]= -x;
}
//have all the negative numbers
sl(x);
if(len==0){
	cout<<"0\n";
	return 0;
}
sort(arr,arr+len);
LL cum[len];
memset(cum,0,sizeof cum);
for(int i = len-2;i>=0;i--)cum[i]= cum[i+1]+arr[i+1];
//rep(i,len)cout<<cum[i]<<" ";
//cout<<endl;

LL mn=cum[0]+arr[0];;
rep(i,len){
//tmp=arr[i]*(x);
// max(0,cum[i]- (len-1 - i)*arr[i]);
tst = (cum[i] + arr[i]*(x- (len-i-1)));
//for(int j=i+1;j<len;j++)tmp+= max(0,arr[j]-arr[i]);
//if(tst !=tmp)cout<<tst << " !=- "<<tmp<<endl;
	if(tst	< mn)
		mn =tst;// arr[i]*(x) + max(0,cum[i] - (len-1-i)*arr[i]);
	//cout<<tmp<<" for "<<i<<endl;
}
cout<<mn<<endl;
//printf("%lld\n",mn);
return 0;
}

