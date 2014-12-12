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
int t,sx,sy,ex,ey;
si(t),si(sx),si(sy),si(ex),si(ey);
char s[100001];
scanf("%s",s);

int dif1 = ex-sx;
int dif2 = ey-sy;

if(dif1 > t || dif2 > t){cout<<"-1\n";return 0;}

int i=0;
while((dif1!=0 || dif2!=0) && i <t){
switch(s[i]){
	case 'E':
		if(dif1 > 0 )dif1--;break;
	case 'W':
		if(dif1 < 0)dif1++;break;
	case 'S':
		if(dif2 < 0) dif2++;
			break;
	case 'N': if(dif2 > 0)dif2--;
			  break;

}
i++;
}

if(dif1==0 && dif2==0)cout<<i<<endl;
else cout<<"-1"<<endl;
return 0;
}

