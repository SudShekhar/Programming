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
//si == scanf
//pr pair<int,int>
//mp make_pair
//vec == vector<int>
int main()
{
	int x,y;
	int m,n;
	si(n),si(m);
	vec nodes(10005,0);
	map<pr,int> st;
	pr nd,rv;
	rep(i,m){
		si(x),si(y);
		nodes[x]=nodes[y]=1;
		//check for repeat edges / reverse directed ones
		nd = mp(x,y);
		rv = mp(y,x);
		if(st[nd] == 1 || st[rv]==1)m--;
		else st[nd]=1;
		// ^ added the edge to a list
	}
	if(n==1 && m ==0){
		//base case
		cout<<"YES\n";
		return 0;
	}	
	if(n-1 !=m)cout<<"NO\n";//edge constraint
	else{
		FOR(i,1,n+1){
			//if all edges are not visited ==> error
			if(nodes[i]==0){
				cout<<"NO\n";
				return 0;
			}
		}
		cout<<"YES\n";
	}
	return 0;
}

