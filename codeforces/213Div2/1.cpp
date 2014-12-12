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
	int n,k;
	si(n),si(k);
	LL num;
	int ans=0;
	int f;
	int dig[10];
	
	//memset(dig,0,sizeof dig);
		rep(i,n)
		{	memset(dig,0,sizeof dig);
			sl(num);f=0;
			if(num%10 == 0 && k==0)ans++;
			while(num){
				dig[(num%10)]=1;
				num/=10;
			}
			if(!f)
			rep(l,k+1)
				if(dig[l]!=1)
				{
					f=1;break;
				}
			//else dig[l]=0;
			if(f==0)ans++;

		}
	cout<<ans<<endl;
	return 0;
}

