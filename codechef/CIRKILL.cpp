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
//#define fill(x,v) memset(x,v,sizeof(x))
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
int mat[4][4];
double fact[42];

double dist(pr a,pr b){
double ans = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
return sqrt(ans);
}
int main()
{
int p,re;
si(re);
int n,m;
vector < pr > lst,tr;
//int a,b;
//init();

vector < bool > v(n);
double a,b,c,k,ans;
double base,GLOBAL_ANS;
rep(p,re){
si(n);
rep(i,n)scanf("%lf %lf",&a,&b), lst.pb(mp(a,b));
//put all the vertices in a list
std::fill(v.begin(),v.begin()+n-3,false);
std::fill(v.begin()+n-3,v.end(),true);
 GLOBAL_ANS=0;
 base = n*n-1*n-2 / 6;

do{
	rep(i,n){
	if(v[i]){
	tr.pb(lst[v[i]]);
	}
	}
	a = dist(lst[0],lst[1]);
	b = dist(lst[1],lst[2]);
	c = dist(lst[2],lst[0]);
	if(a+b == c || a+c == b || c +b==a)continue;
	//we know there is a circle now
	k = ((lst[0].first - lst[1].first)*(lst[0].first-lst[2].first) + (lst[0].second-lst[1].second)*(lst[0].second-lst[2].second)  ) /(-(lst[0].second-lst[1].second - (lst[2].second - lst[1].second)/(lst[2].first-lst[1].first)*(lst[0].first-lst[1].first)) );
cout<<k<<endl;
	rep(i,n){
	if(!v[i]){
	ans = ((lst[v[i]].first - lst[1].first)*(lst[v[i]].first-lst[2].first) + (lst[v[i]].second-lst[1].second)*(lst[v[i]].second-lst[2].second) ) +(k*(lst[v[i]].second-lst[1].second - (lst[2].second - lst[1].second)/(lst[2].first-lst[1].first)*(lst[v[i]].first-lst[1].first)));
	if(ans<=0)GLOBAL_ANS++;
	}
	lst.clear();
	}
}
while(next_permutation(v.begin(),v.end()));
cout<<GLOBAL_ANS/base<<endl;

}
return 0;
}

