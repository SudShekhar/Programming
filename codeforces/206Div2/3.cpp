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
	int n,l,r,ql,qr;
	int arr[100001];
	si(n),si(l),si(r),si(ql),si(qr);

	rep(i,n) si(arr[i]);

	LL finalAns=INT_MAX;
	LL sum = 0;
	int pre[100001];
	LL ans,lsum,rsum;
	pre[0]=0;
	FOR(i,1,n+1)
		pre[i] = pre[i-1]+arr[i-1];
	rep(i,n+1){
		//if(i==0)lsum=0
		lsum = pre[i];
		rsum = pre[n]-pre[i];
		//i is the place where we cut

		ans = lsum*l + rsum*r;
		if(n-2*i  > 1) ans+= qr*(n-2*i -1);
		else if (1< 2*i - n)ans+= ql*(2*i-n -1);

		if(ans < finalAns) finalAns = ans;
	}
	cout<<finalAns<<endl;
	return 0;
}

