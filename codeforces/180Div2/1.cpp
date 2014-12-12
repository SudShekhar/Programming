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
si(n);
char s[1001];

scanf("%s",s);
int i;
int count=0,count1=0;

rep(i,n){
if(s[i]=='R')count++;
if(s[i]=='L')count1++;
if(count && count1)break;
}
//only L's
int start=-1,end=-1;
if(!count){
rep(i,n){
if(s[i]=='L' && s[i+1]=='.')start=i+1;
if(s[i]=='L' && s[i-1]=='.')end=i;
}
cout<<start<<" "<<end<<endl;
return 0;
}
else if(!count1){
rep(i,n){
if(s[i]=='R'&& s[i+1]=='.')end=i+2;
if(s[i]=='R'&& s[i-1]=='.')start=i+1;
}
cout<<start<<" "<<end<<endl;
return 0;
}

for(i=0;i<n;i++){
if(s[i]=='L'&&s[i+1]=='R' || (s[i]=='R' && s[i+1]=='L'))break;
}
cout<<i+1<<" "<<i+2<<endl;
return 0;
}

