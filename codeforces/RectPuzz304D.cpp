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
#define min(a,b) a>b?b:a
int hcf(int a,int b)
{	//int temp = min(a,b);
	if(a<b) a = a+b - (b=a);
	int c;
	while(a%b!=0)
	{
		c = b;
		b = a%b;
		a = c;
	}
	return b;
}

int main()
{
int n,m,x,y,a,b;
cin>>n>>m>>x>>y>>a>>b;
int HCF = hcf(a,b);
a/=HCF,b/=HCF; // reduced both to least valuesc
int size = min(n/a,m/b); //tells us how many times the rect can be formed
a*=size;b*=size;
int x1 = x-(a-a/2);
int y1 = y-(b-b/2);
int x2 = x+a/2;
int y2 = y+b/2;

//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
//check that they dont exceed bounds
int shift=0;
if(x1 <0)shift=-x1;
if(x2>n)shift += n-x2;
x1+=shift,x2+=shift;
shift=0;
if(y1<0)shift=-y1;
if(y2>m)shift+=m-y2;
y1+=shift;y2+=shift;

cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

return 0;
}

