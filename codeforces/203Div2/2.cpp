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
#define N 100001
int arr[N];
int numPath[N];
int hotels[N];
matrix mat(N);

int findlen(int v){
if(mat[v].empty() || (numPath[mat[v][0]] > 1))
	return 1;
return findlen(mat[v][0])+1;

}
void pri(int v){
if(mat[v].empty()||numPath[mat[v][0]]>1)
	printf("%d ",v);
else {
	pri(mat[v][0]);
	printf("%d ",v);
}
return;
}

int main()
{
int n;
si(n);
int len=0;
memset(numPath,0,sizeof numPath);
int x;
FOR(i,1,n+1){
	si(x);
	if(x==1)hotels[len++]=i;
}
FOR(i,1,n+1){
si(x);
if(x!=0)
	//x hs path to i
	mat[i].pb(x),numPath[x]++;
}
int mx =0 ,ind=-1;
rep(i,len){
//mx = max(mx,findlen(hotels[i]));
if(mx < (x = findlen(hotels[i])))
	//cout<<"len "<<x<<" by "<<hotels[i]<<endl;
	mx = x,ind = hotels[i];;
}
cout<<mx<<endl;
pri(ind);
cout<<endl;
return 0;
}

