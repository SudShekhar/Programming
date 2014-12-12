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
int numFact[100004];//stores numbers of factors each number has
 
void init(){
numFact[0]=10;
numFact[1]=10;
//numFact[2]=1;
 
for(int i=2;i<100001;i++){
if(numFact[i]==0){
numFact[i]=0;
for(int j=i*2;j<100001;j+=i)numFact[j]++;
}
}
return;
}
 
 
 
int main()
{
int v,re,n,m,k;
memset(numFact,0,sizeof(numFact));
init();
si(re);
int ans;
//rep(i,100)cout<<numFact[i]<<" ";
//cout<<endl;
 
rep(v,re){
 
si(n),si(m),si(k);
//if(k==1)flag == true;
ans=0;
FOR(i,n,m+1)if(numFact[i]==k || (numFact[i]==0 && k==1)){
//cout<<i<<" ";
ans++;
}
//cout<<endl;
 
printf("%d\n",ans);
}
return 0;
}
 
