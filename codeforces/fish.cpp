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
int comp(const void *a,const void *b)
{
	//cout<<*(int*)a<<endl;
	return *(int*)a - *(int*)b;
}
int main()
{
int n,m,t,j;
int alice[100001],bob[100001];
si(n),si(m),si(t);

//rep(i,m)cout<<bob[i]<<endl;
rep(i,n)
	si(alice[i]);

rep(i,m){
	si(bob[i]);
	//cout<<"cauth "<<j<<endl;
}

//rep(i,m+1)cout<<bob[i]<<endl;
if(n > m) printf("YES\n");//number of alice's fish is greater

qsort(alice,n,sizeof(int),comp);
qsort(bob,m,sizeof(int),comp);

//rep(i,m)cout<<bob[i]<<endl;
for(int i=0;i<m;i++)
{
	//printf("%d %d\n",bob[i],alice[i]);
	if(bob[i] < alice[i]){
		printf("YES\n");
		return 0;
	}
}
printf("NO\n");


return 0;
}

