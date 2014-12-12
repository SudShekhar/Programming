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

long long GCD(LL a , LL b){
LL c;
	while(b!=0){
c = a%b;
a = b;
b=c;

}
return a;
}

int main()
{
int n,m;
char first[1000001];
char sec[1000001];
si(n),si(m);
scanf("%s %s",first,sec);

long long len1 = strlen(first);
long long len2 = strlen(sec);
long long gcd = GCD(len1,len2);

LL lm = len1* (len2 / gcd);
cout<<lm<<endl;
int ind1=0,ind2=0;
LL ans = lm;
int cnt[len1][26];
memset(cnt,0,sizeof cnt);
rep(i,lm){
cnt[(i%gcd)][first[(i%len1)]-'a']++;
}
rep(i,len1)
{
	rep(j,27)cout<<cnt[i][j]<<" ";
	cout<<endl;
}
rep(j,len2){
ans-=cnt[(j%gcd)][sec[j]-'a'];
}

ans*= (len1*n)/lm;
cout<<ans<<endl;
return 0;
}

