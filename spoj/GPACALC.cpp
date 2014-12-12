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

int grade(char c)
{
	switch(c){
		case 'S': return 10;
		case 'A': return 9;
		case 'B': return 8;
		case 'C': return 7;
		case 'D': return 6;
		case 'E': return 5;
		default : return 0;	  
	
	}
}
int main()
{
int v,re,n;
float ans;
char c; int g;
int sum;
si(re);
rep(v,re){
si(n);
	ans=0;
	sum = 0;
	rep(i,n)
	{
		si(g);
		scanf("%*c%c",&c);
		ans += g*grade(c);
		sum+=g;
	}
	printf("%.2f\n",ans/sum);///;<<endl;
}
return 0;
}

