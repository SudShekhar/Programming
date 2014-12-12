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
int n,m;
si(n),si(m);
int row[n],col[n],ans[n];
memset(row,0,sizeof(row));
memset(col,0,sizeof(col));
memset(ans,0,sizeof(ans));
int x,y;
rep(i,m){
si(x),si(y);
row[x-1]=-1;
col[y-1]=-1;
}
int as=0;
FOR(i,1,n)if(row[i]==0||col[i]==0)as++,ans[i]=1;
FOR(i,1,n){
if((i!=(n+1)/2||n%2==0) && row[i]==0 && col[i]==0)as++;
}
cout<<as<<endl;

return 0;
}

