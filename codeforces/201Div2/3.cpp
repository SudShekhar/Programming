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
int n;
vec arr;
int x;
int mx = -1;
si(n);
set < int > thr;
rep(i,n){
si(x);
thr.insert(x);
}

//rep(i,n)thr[arr[i]]=false;
int flag,len;
while(1){
len = thr.size();
flag=0;
for(set<int>::iterator i = thr.begin();i!=thr.end();++i)
{
	for(set<int>::iterator j = thr.begin(); j!=thr.end(),j!=i;++j){
	if(thr.count(abs(*i - *j)) == 0)
		thr.insert(abs(*i-*j)),flag=1;
	}
}
if(flag==0)break;
}
for(set<int>::iterator i = thr.begin();i!=thr.end();++i)cout<<*i<<" ";
cout<<endl;
len-=n;
if(len&1)cout<<"Alice\n";
else cout<<"Bob\n";
return 0;
}

