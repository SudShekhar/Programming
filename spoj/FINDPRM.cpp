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
#define lim 10000001
vector<bool> arr(10000001,false);

void init(){
	for(int i=2;i<lim;i++)
	{
		if(!arr[i]){
			for(int j = i*2;j<lim;j+=i)
				arr[j]=true;
		}
	}

}

int main()
{
int v,re;
int n;
si(re);
init();
int ans;
rep(v,re){
	si(n);
	if(!n&1)n-=1;
	ans=0;	
	for(int i= n;i > n/2 && i>1;i--)
		if(arr[i]==false){
			//cout<<i<<" is prime"<<endl;
			ans++;
		}
	printf("%d\n",ans);
}
return 0;
}

