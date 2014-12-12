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
int n;
struct edge{
int a;
int b;
};

int comp(const void *x,const void *y){
int ans;
edge *a = (edge*)x;
edge *b=(edge*)y;
int x1 = abs((a->a - a->b)) ;
if(a->a == 1 && a->b == n || (a->a==n && a->b==1)) x1 = 1;

int x2 = abs((b->a - b->b));
if(b->a == 1 && b->b == n || (b->a==n && b->a == 1)) x2 = 1;
ans = x1 -x2;
if(ans == 0 )ans = a->a - b->a;
return ans;
}
int main()
{
//take in all the edges , construct the graph
// afterwards start with the 1st  node and keep adding to another array (ans) once you have all the nodes. end it
edge arr[100001];
int ans[100001];

int j,k;	

si(n);
rep(i,2*n)
{
	si(arr[i].a);
	si(arr[i].b);
}
qsort(arr,2*n,sizeof(edge),comp);

rep(j,2*n){
printf("%d %d\n",arr[j].a,arr[j].b);
}
int len=0;
ans[0]=arr[0].a;
ans[1] = arr[0].b;
len = 2;
bool flag = true;
int i;
for(i=1;i<n;i++)
{
	if(ans[len-1]!=arr[i].a){
		flag=false;
		break;
	}
	ans[len++]=arr[i].b;
//ans[len++] = arr[i].a;
}
if(flag!=false){
	len=0;
for(i=n;i<2*n;i++)
{
	if(ans[i-n] == arr[i].a && ans[i-n+2] == arr[i].b)continue;
	else {
		flag=false;break;}
}

}
if(flag == false)printf("-1\n");
else for(i=0;i<n-1;i++)printf("%d ",ans[i]);
printf("%d\n",ans[n-1]);

return 0;
}

