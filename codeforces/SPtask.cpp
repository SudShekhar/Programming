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
LL  ans;
char s[100001];
int n;
int diff=10;
bool cnt[15];
scanf("%s",s);
rep(j,15)cnt[j]=false;

int len = strlen(s);
if(s[0]=='?')ans=9;
else if ((s[0] -'0') > 10)ans=9,cnt[s[0]-'A']=true,diff--;
else ans=1;

for(int i=1;i<len;i++)
{
	if(s[i]-'0' <=9)continue; //the case when its a number fixed
	else if(s[i]=='?')ans*=10;
	else if(cnt[s[i]-'A']==false)ans*=diff--,cnt[s[i]-'A']=true;
}
//printf("%d\n",ans);
cout<<ans<<endl;
return 0;
}

