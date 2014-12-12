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

LL pw(LL num,LL base){
int x;
LL ans=1;
while(base>0){
x = base&1;
base/=2;
if(x)ans = (ans*num)%mod;
num=(num*num)%mod;
}
if(ans>mod)ans%=mod;
return ans;
}

LL cal(int n,int ind,int type,int len){
LL ans=0;
for(int j=0;j<1;j++){
LL num = pw(2,ind+j*len);
ans+=num;
if(ans>mod)ans%mod;
}
return ans;
}

int main()
{
char str[100001];
int n;
scanf("%s",str);
si(n);
int len = strlen(str);
LL ans=0;
rep(i,len){
if( str[i]=='5'){
ans+=pw(2,i);
}
if(str[i]=='0'){
ans+=pw(2,i);
}
ans%=mod;
}

LL num = pw(2,n*len);
num= (num-1+mod)%mod;
LL denum = pw(2,len);
denum=(denum-1+mod)%mod;

ans=(ans*(num))%mod;
denum = pw(denum,mod-2)%mod;
ans = (ans*denum)%mod;

cout<<ans%mod<<endl;
return 0;
}

