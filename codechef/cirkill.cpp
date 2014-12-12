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
#define sq(x) x*x
int mat[4][4];
double fact[42];

double dist(pair<double,double> a,pair<double,double> b){
double ans = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
return sqrt(ans);
}
int main()
{
int p,re;
si(re);
int n,m;
vector < pair<double,double> > lst,tr;
pair<double,double>center;
//int a,b;
//init();

vector < bool > v(n);
double a,b,c,k,ans;
double base,GLOBAL_ANS;
double x1,x2,x3,y1,y2,y3;
double m1,m2,num1,num2,denum1,denum2;
double centerX,centerY,radius;
rep(p,re){
si(n);
lst.clear();
rep(i,n){
	scanf("%lf %lf",&a,&b);
	lst.pb(mp(a,b));
}
//put all the vertices in a list
//std::fill(v.begin(),v.begin()+n-3,false);
//std::fill(v.begin()+n-3,v.end(),true);
 GLOBAL_ANS=0;
 base = n*(n-1)*(n-2)*(n-3) / 6;

rep(i,n)
	FOR(j,i+1,n)
	FOR(k,j+1,n){
	//three points taken
	x1 = lst[i].first,y1 = lst[i].second;
	x2 = lst[j].first,y2 = lst[j].second;
	x3 = lst[k].first,y3 = lst[k].second;

	m1 = (double)(	y1 - y2 )/(x1 -x2);
	m2 = (double)(y2 - y3)/(x2 - x3);

	if(m1!=m2){
	num1 = ((sq(x1) + sq(y1))*(y3 - y2) + (sq(x2) + sq(y2))*(y1 - y3) + (sq(x3)+sq(y3) ) *(y2 - y1));

	denum1 = (x1*(y3 - y2) + x2*(y1-y3) +x3*(y2 - y1));

	num2 = ((sq(x1) + sq(y1))*(x3 - x2) + (sq(x2) + sq(y2))*(x1 - x3) + (sq(x3)+sq(y3) ) *(x2 - x1));
	denum2 = (y1*(x3 - x2) + y2*(x1 - x3) + y3*(x2-x1));	
	centerX = (double)num1 / (double)denum1;
	centerY = (double)num2 / (double)denum2;

	centerX/=2.0;
	centerY/=2.0;
	center = mp(centerX,centerY);
	radius = (dist(center, lst[i]));
	//have center and radius


	
	//found equation of the two lines ... 
	
//	cout<<k<<endl;
	rep(l,n){
	if(l!=i && l!=j && l!=k){
	if(dist(center,lst[l]) <= radius+0.000001)
		GLOBAL_ANS++;
	}
	//tr.clear();
	}
	}
//	tr.clear();
	
}
printf("%lf\n",(double)GLOBAL_ANS/(double)base);//<<endl;

}
return 0;
}

