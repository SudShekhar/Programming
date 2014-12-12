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

long long int P(int i,int a){
	int ans=1;
	while(a--)ans*=i;
	return ans;
}
int main(){
  int a,b,c;
  si(a),si(b),si(c);
  long long int ans[100];
  int ind=0;
  int exp;
  int digSum,temp,val;
  long long int mx;
  long long int mn;
 
  for(int i=1;i<82;i++){
    mx = P(i,a);
    mx = b*mx+c;
    mn = mx;
    temp=0;
    while(mx)
      temp+=mx%10,mx/=10;
    if(temp==i)
      ans[ind++]= mn;
  }
  sort(ans,ans+ind);
  int len=0;
  while(len < ind && ans[len] <1000000000)
	  len++;
  cout<<len<<endl;
  if(len==0){
  	return 0;
  }
  rep(i,len){
     cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
