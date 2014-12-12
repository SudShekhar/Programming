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
int n,m,k;
int arr[301];
int isIn[301];
memset(isIn,0,sizeof isIn);
si(n),si(m),si(k);

rep(i,k)si(arr[i]),isIn[arr[i]]=1;

if(k==n || (m > (n-1)*(n)/2 + k-1))
{
	cout<<"-1\n";
	return 0;
}
else{
int c = 1,j;
while(c <=n)
	if(isIn[c]!=1)break;
	else c++;
printf("%d %d\n%d %d\n",arr[0],c,arr[1],c);
isIn[arr[0]]=-1;
isIn[arr[1]]=-1;
m-=2;
c=1;
while(isIn[c]==-1)c++;
while(m){
	j=c+1;
	if(j>n)break;
	while(j<=n && m){
	if(isIn[j]!=-1)
	cout<<c<<" "<<j<<endl,m--;
	j++;
	}
c++;
if(isIn[c]==-1)c++;
}

}
return 0;
}

