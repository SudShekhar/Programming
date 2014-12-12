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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
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
long long fib[100];
void fibb(){
fib[0]=0;
fib[1]=1;
fib[2]=1;
FOR(i,3,92){
	fib[i]=fib[i-1]+fib[i-2];
	if(fib[i]<0)cout<<i<<endl;
}
return;
}
int main()
{
LL x,y,m;
sl(x),sl(y),sl(m);

fibb();
LL max = MAX(x,y);
LL min= MIN(x,y);
int flag=0;
LL one,two,three;
rep(i,92){

one = fib[i]*min;
two = fib[i+1]*max;
if((two<0 && max >0)||(two>0&&max<0)||one>0&&min<0 || one<0 && min>0)break;
three = two + one;
//if(three<0 && max>0)break;
if(three <=0 && two>0 && one>0 || (three>=0 &&two<0&&one<0))break;

if( three >= m)
{
	flag =1;
	cout<<i<<endl;
	break;
}
}
if(flag==0)cout<<"-1\n";
//cout<<i+1<<endl;
return 0;
}

