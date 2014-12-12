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
int month[]= {31,28,31,30,31,30,31,31,30,31,30,31};


int main()
{
char s1[11],r1[11];
scanf("%s",s1);
int s[11],r[11];
//-------------------
rep(i,11)s[i]=(int)s1[i]-'0';
int a = s[9] + s[8]*10;

int lim= (s[6]+s[5]*10)-1;

rep(i,lim)a+=month[i];
int year = s[0]*1000 + s[1]*100 + s[2]*10 + s[3];
if(year%4==0 && year!=1900 && lim>1)a+=1;
a+=(year-1900)*365;
if(year > 1900)a+=(year-1-1900)/4;
//===========
scanf("%s",r1);

rep(i,11)r[i]=r1[i]-'0';
int b = r[9]+r[8]*10;
//if(b>0)b-=1;
lim = r[6]+r[5]*10-1;
rep(i,lim)b+=month[i];
year = r[0]*1000 + r[1]*100 + r[2]*10 + r[3];
if(year%4 == 0 && year!=1900 && lim >1 )b+=1;
b+= (year-1900)*365;
if(year> 1900)b+=(year-1-1900) /4;
//====
//printf("%d\n",b);
printf("%d\n",abs(b-a));



return 0;
}

