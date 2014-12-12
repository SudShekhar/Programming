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
int v,re,n,k;
int b[60];
int r[60][60];

si(re);
int x;
rep(v,re){
si(n),si(k);
n<<=1;

rep(i,n)b[i]='.';
rep(i,k)
	si(x), b[--x]='[';

memset(r,0,sizeof r);
r[0][1]=1; //opening bracket

FOR(i,1,n)
	rep(j,n){
	if(j)//we add a closing bracket
		r[i][j] +=r[i-1][j-1];
	if(b[i]!='[' && j!=n-1)
		r[i][j]+= r[i-1][j+1]; //opening bracket
	
	}

cout<<r[n-1][0]<<endl;
}
return 0;
}

