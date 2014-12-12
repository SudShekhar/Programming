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
//need to take in the numbers find their best match and pair them up
#define N 100001


int cnt[2][N];
int s[N],q[N],ans[N];

int main()
{
int n,m,k;
int top = 0 ,back=0,acount = 0;
si(n),si(m);
rep(i,2)
	rep(j,n)
		si(k),cnt[i][k]++;

//have found the number of digits of each type in each number set

rep(i,m)//for the entire allowable set
{
	while(cnt[0][i]--)
		s[++top] = i; // pushed number into stack
	
	k = m - 1- i; //found its best match
	while(cnt[1][k]--)
	{
		if(top) ans[acount++] = k + s[top--];
		else q[++back] = k;
	}
}
//now ans has all the exact matches ... have to empty stacks
int head = 1;

while(top){
ans[acount++] = (s[top--] + q[head++])%m;
}
sort(ans,ans+n);

for(k=acount-1;k>=0;k--)printf("%d ",ans[k]);
printf("\n");

return 0;
}

