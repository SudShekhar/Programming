/*
 logic from topcoder- -> Totient function is number of coprimes <n.. so its n-1 if n is prime..

 What we do here is,, for each prime that divides n, we find all its multiples and subtract them from the result. what remains is our answer!
 */


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

LL fi(LL n){
LL result = n;
for(int i=2;i*i<=n;i++)
{
	if(n%i==0)result-=result/i;
//removed all multiples of i less than n..
	//now set n to new value
	while(n%i==0)n/=i;
}
if(n>1)result-=result/n;
//if n is at some other prime, removed its occurrences too
return result;//get our answer
}

int main()
{
//init();
int v,re;
LL n;
//double ans;
int p;
si(re);
rep(v,re){
sl(n);
printf("%lld\n",fi(n));
/*
ans=n;

while(n!=1){
p=arr[n];
ans*=(double)(p-1)/(double)p,n/=p;
}
printf("%lf\n",ans);
*/
}

return 0;
}

