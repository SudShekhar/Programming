// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParallelProgramming.cpp"

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
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007
#define pb push_back
#define max(a,b) a>b?a:b
matrix arr;
int ans[51];
int vis[51];
int tm[51];
int final[51];
int flag,gmax;
class ParallelProgramming {
public:
int minTime(vector <int> time, vector <string> prec) {

flag=0;
gmax=0;
int len = time.size();

arr.clear();
arr.resize(len);
rep(i,len)
{
	rep(j,len)
	if(prec[i][j]=='Y')
		arr[i].pb(j);
tm[i]=time[i];
}
//created the matrix
	memset(vis,0,sizeof(vis));

	rep(i,len){
	if(!vis[i])dfs(i);
	if(flag==1)break;
	}

	if(flag==1)return -1;
	else return gmax;
}

void dfs(int v){
int len = arr[v].size();
int lmax=0;
vis[v]=1;
rep(i,len){
if(!vis[arr[v][i]])dfs(arr[v][i]);
if(final[arr[v][i]]==1)lmax = max(lmax,ans[arr[v][i]]);
//loop
else {
flag=1;return;
}
if(flag==1)return;
}
ans[v]=lmax+tm[v];
gmax = max(ans[v],gmax);
final[v]=1;
return;
}

};

