// BEGIN CUT HERE

// END CUT HERE
#line 5 "AstronomicalRecords.cpp"

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


class AstronomicalRecords {
	vector<long long > getLong(vector<int> arr){
		int n = arr.size();
		vector<long long > v(n);
		rep(i,n)
			v[i] = arr[i];
		return v;
	}
	int solve(vector<long long> a,vector<long long> b,int i,int j){
		int q = a[i];
		int p = b[j];
		rep(i,a.size())
			a[i]*=p;
		rep(i,b.size())
			b[i] *= q;
		int nx = a.size();
		int ny = b.size();
		int dp[nx+1][ny+1];
		// will find LCS now
		int res=0;
		rep(i,nx+1)
			rep(j,ny+1){
				if(i==0 || j==0)
					dp[i][j]=0;
				else{
					dp[i][j]=0;
					if(a[i-1] == b[j-1])
						dp[i][j] = dp[i-1][j-1]+1;
					dp[i][j] = max((max(dp[i-1][j],dp[i][j-1])),dp[i][j]);
				}
			}
		return (nx+ny-dp[nx][ny]);
	}
public:
int minimalPlanets(vector <int> A, vector <int> B) {
	vector<long long > a = getLong(A);
	vector<long long > b = getLong(B);
	int n = a.size();
	int m = b.size();
	int ans=n+m;
	rep(i,n)
		rep(j,m){
			ans = min(ans,(solve(a,b,i,j)));
		}
	return ans;	

}
};

// int main(){
// 	vec a;
// 	vec b;
// 	int n;
// 	si(n);
// 	a.resize(n);
// 	rep(i,n)
// 		si(a[i]);
// 	si(n);
// 	b.resize(n);
// 	rep(i,n)
// 		si(b[i]);
// 	AstronomicalRecords li;
// 	cout<<li.minimalPlanets(a,b)<<endl;
// }