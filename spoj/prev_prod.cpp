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
//	LL one = 2,two = 2;
	int re,i;
	LL n;
	cin>>re;
	LL one,two,three,four;
	rep(v,re)
	{
		cin>>n;
		fprintf(stderr,"got %lld\n",n);
		
		//LL arr[n+2];
//		arr[1]=2;arr[2]=2;
		one = 2; two = 2;three = 2;
		for(i=3;i<=n;i++)
		{
				//three=one*two;
		four = three;
		three = (one*two) % mod;
		two = one;
		one = four;
		//two = one;
			//arr[i]=(arr[i-1]*arr[i-2])%mod;
		}
	cout<<three<<endl;
	}
return 0;
}

