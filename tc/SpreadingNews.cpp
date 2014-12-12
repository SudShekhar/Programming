// BEGIN CUT HERE

// END CUT HERE
#line 5 "SpreadingNews.cpp"

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
matrix arr;

class SpreadingNews {
public:
int minTime(vector <int> supervisors) {
int len = supervisors.size();
arr.clear();
arr.resize(len);
//matrix arr(len);

FOR(i,1,len){
	arr[supervisors[i]].pb(i);
}
int ans = dfs(0);
/*rep(i,len){
	cout<<"row "<<i<<" ";
rep(j,arr[i].size())cout<<arr[i][j]<<" ";
cout<<endl;
}
*/
return ans;
}

int dfs(int v){
	int len = arr[v].size();
	int temp[len];
	if(len==0)return 0;
	int q=0;
	rep(i,len){
	temp[i]=dfs(arr[v][i]);
	}
	sort(temp,temp+len);
//	rep(i,len)cout<<temp[i]<<" ";
//	cout<<endl;
	rep(i,len){
	q = max(q,temp[i]+len-i);
	}
//	cout<<v<<"takes "<<q<<endl;
return (q)>len?q:len;
}

};

/*
int main(){
int n;
vec arr;
int a;
si(n);
rep(i,n)si(a),arr.pb(a);
SpreadingNews b;
cout<<b.minTime(arr)<<endl;

}*/
