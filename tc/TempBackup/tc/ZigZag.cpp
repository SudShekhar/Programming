// BEGIN CUT HERE

// END CUT HERE
#line 5 "ZigZag.cpp"

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


class ZigZag {
public:
int longestZigZag(vector <int> sequence) {
int bigdp[51],smalldp[51];
int ans=0;
int len = sequence.size();

bigdp[0]=1;
smalldp[0]=1;
ans=1;
FOR(i,1,len){
	bigdp[i]=smalldp[i]=0;
	rep(j,i){
	if(sequence[j] < sequence[i]){
	bigdp[i] = max(bigdp[i],(smalldp[j]+1));
	}
	else if(sequence[i]<sequence[j])
	smalldp[i]=max(smalldp[i], (bigdp[j]+1));
	}
	
	ans = max(ans,bigdp[i]);
	ans = max(ans,smalldp[i]);
}

return ans;

}
};

