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
bool comp(const int&a,const int &b){
    return a>b;
}

int main(){
    int re,n,m;
    int xcut[1002],ycut[1002];
    int dp[1002][1002];
    si(re);
    // 0 0
    // 2 1 => 1 3 | 2 
    rep(v,re){
        si(n),si(m);
        n--,m--;
        rep(i,n)
            si(xcut[i]);
        rep(j,m)
                si(ycut[j]);
        sort(xcut,xcut+n,comp);
        sort(ycut,ycut+m,comp);
        memset(dp,0,sizeof dp);
        FOR(i,1,n+1)
            dp[i][0] = dp[i-1][0]+ xcut[i-1];
            int op1,op2;
        FOR(j,1,m+1)
            dp[0][j] = dp[0][j-1] + ycut[j-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                op1 = (dp[i-1][j] + (j+1)*xcut[i-1]);
                op2 = (dp[i][j-1] + (i+1)*ycut[j-1]);
                dp[i][j] = min(op1,op2);
            }
        }
        // rep(i,n+1)
        //     {
        //         rep(j,m+1)
        //             cout<<dp[i][j]<<" ";
        //         cout<<endl;
        //     }
        printf("%d\n",dp[n][m]);    
    }
    return 0;
}
