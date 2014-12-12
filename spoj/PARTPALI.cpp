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
int ln(int num){
int count =0;
while(num){
num/=10;
count++;
}
return count;
}
int gcount;
void palin(int n1){
char str[23];
int l=0,b=0;
int num = n1;
while(num){
str[l++]=num%10;
num/=10;
}
l-=1;
int flag=0;

while(b<=l){
if(str[b++]==str[l--])
{}
else{flag=1;break;}
}
if(flag==0){
	//cout<<n1<<endl;
gcount++;
}
}

int main()
{
	 gcount=0;
int n,s;
si(n);
si(s);
int num=0;
while(1){
if(ln(num) == s) break;
else num+=n;
}

//have a length s multiple now
while(ln(num)==s){
palin(num);
num+=n;
}
cout<<"------"<<gcount<<"----\n";
return 0;
}

