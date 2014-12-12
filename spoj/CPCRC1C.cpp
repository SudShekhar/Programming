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
int arr[] ={0,1,3,6,10,15,21,28,36,45};

LL solve(int a,int mult){
if (a<=0)return 0;
LL aLeft = a/10;
LL lastDig = a%10;
LL lastSum = arr[lastDig];
LL sum=0;
while(a){
sum+=a%10;
a/=10;
}
sum-=lastDig;
return lastSum*mult + aLeft*45*mult + sum*(lastDig+1)*mult + solve(aLeft-1,mult*10); 
}

int main()
{
LL a,b;

LL a1,a2;

while(1)
{
	sl(a),sl(b);
	if(a==-1 && b==-1)break;
a1 = solve(a-1,1);
a2 = solve (b,1);

cout<<a2-a1<<endl;
}
return 0;
}

