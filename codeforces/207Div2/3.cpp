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

int arr[500001];
int next[500001];
int n;
int find(int m,int stop){
	if(m>stop)return m;
return next[m] = next[m]==m?m:find(next[m],stop);

}
void update(int start,int stop,int val){
int m = start;
while(m<=stop){
if(next[m]==m){

	if(m!=val)
	{
		arr[m]=val;
		next[m]= m+1;
	}
	else arr[m]=0,m++;
	
}
m = find(m,stop);
}

return;
}

int main()
{
int m,a,b,c;
si(n),si(m);
//memset(arr,0,sizeof arr);
memset(next,0,sizeof next);
rep(i,500001)next[i]=i;

rep(i,m){
si(a),si(b),si(c);
//a,b--,c--;
update(a,b,c);
}

FOR(i,1,n+1)printf("%d ",arr[i]);
printf("\n");
return 0;
}

