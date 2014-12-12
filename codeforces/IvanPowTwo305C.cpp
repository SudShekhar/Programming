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
int n;
//vec arr(1000001);
si(n);int k;
int max=-1000,y;
int prev = 0;
map<int,int> mp;
int count=0,ans=0;
rep(i,n)
{
	si(k);
	mp[k]++;
}
//got count of each
while(!mp.empty())
{
	k = mp.begin()->first;
	count = mp.begin()->second;
	mp.erase(mp.begin());
	if(count&1){
	if(max<k)max = k;
	ans++;
	}
	if(count>1){
	mp[k+1]+= count/2;
	}
}
printf("%d\n",max-ans+1);
return 0;
}

