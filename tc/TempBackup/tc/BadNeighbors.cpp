// BEGIN CUT HERE

// END CUT HERE
#line 5 "BadNeighbors.cpp"

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


class BadNeighbors {
public:
int maxDonations(vector <int> donations) {
int len = donations.size();
vec l1(len),l2(len);
int dp[len],dp1[len];
cout<<len<<endl;
FOR(i,1,len-1){
	l1[i]=donations[i];
	l2[i-1]=donations[i];
}
l1[0]=donations[0];
l2[len-2]=donations[len-1];

dp[0]=l1[0];
dp[1]=max(l1[1],l1[0]);
FOR(i,2,len-1){
	dp[i]= max(dp[i-1] , (dp[i-2] + l1[i]));
}

dp1[0]=l2[0];
dp1[1]=max(l2[1],l2[0]);

FOR(i,2,len-1){
dp1[i] = max(dp1[i-1] , (dp1[i-2] + l2[i]));
}
rep(i,len-1)cout<<dp[i]<<" ";
cout<<endl;
rep(i,len-1)cout<<dp1[i]<<" ";
cout<<endl;
return max(dp[len-2],dp1[len-2]);
//created lists;
}
};
/*
int main(){
	while(1){
vec don;
int x;
while(1){
si(x);
if(x==-1)break;
don.pb(x);
}
BadNeighbors a;
cout<< a.maxDonations(don)<<endl;
}
}*/
