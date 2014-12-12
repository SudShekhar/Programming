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

int n,m;
char s[105];
int len;


bool check(int n1,int m1,int x,int y){
	//if((n-n1)%x== (m-m1)/y)

//if((n-n1)%x==0 && (m-m1)%y==0)return true;
	//int q=0,w=0;
int mul =0;
if(x) mul = (n-n1)/x;
if(y) mul  = (m-m1)/y;

if(mul<0)return false;
else return (n == mul*x+n1 && m == mul*y + m1);

}

int main()
{
si(n),si(m);
scanf("%s",s);

int delX=0,delY=0;
len = strlen(s);
rep(i,len){
switch(s[i]){
	case 'U':delY++;break;
	case 'D':delY--;break;
	case 'R':delX++;break;
	case 'L':delX--;break;
}
}
//found delta's
int a=0,b=0;
rep(i,len){
switch(s[i]){
	case 'U':a++;break;
	case 'D': a--;break;
	case 'R': b++;break;
	case 'L': b--;break;
}
if(check(b,a,delX,delY)){
printf("Yes\n");
return 0;
}
}
if(check(0,0,delX,delY)){
	printf("Yes\n");
	return 0;
}

//if(((delX>=0 && n >= 0)||(delX<=0 &&n<=0)) && ((delY>=0&& m>=0)||(delY<=0 &&m<=0))){
	//printf("No\n");
	//return 0;


//now hopefull n and m are in range of our 0


printf("No\n");
return 0;
}

