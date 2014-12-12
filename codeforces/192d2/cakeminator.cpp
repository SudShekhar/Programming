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
#define sc(a) scanf("%c",&a);
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
LL n,k;
sl(n),sl(k);
char arr[n][k];
int eatr[n];
int eatc[k];
LL numrows=0,numcols=0;
memset(eatr,0,sizeof(eatr));
memset(eatc,0,sizeof(eatc));
getchar();
rep(i,n){

rep(j,k)
{
	sc(arr[i][j]);
	if(arr[i][j]=='S'){
	if(!eatr[i])eatr[i]=1,numrows++;
	if(!eatc[j])eatc[j]=1,numcols++;
	}
}
getchar();		
}
/*rep(i,n)
{
	rep(j,k)
	cout<<arr[i][j];
	cout<<endl;
}*/
LL ans = n*k-numcols*numrows;
cout<<ans<<endl;
return 0;
}

