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
int reach[21][21];
int arr[21][21];
int n,m;
int flag;
int ex,ey;
void start(int x,int y){
if(flag==1)return;
//cout<<"can reach "<<x<<" "<<y<<endl;

if(x==0 || y ==0 || x== n-1 || y == m-1){
if(x!=ex || y!=ey)
{
	cout<<"valid\n";
	flag=1;
	return;
}
}

int x1,y1;
rep(i,3)
	rep(j,3){
	x1 = x + i -1;
	y1 = y+j-1;

//		cout<<"testing "<<x1<<" "<<y1<<endl;
	if(x1== x || y1==y)
	if(x1>=0 && x1 <n && y1 >=0 && y1 < m){
//		cout<<" pass basice testing "<<x1<<" "<<y1<<endl;
		
		if(arr[x1][y1]==1 && reach[x1][y1]==0)
		{
			reach[x1][y1]=1;
			start(x1,y1);
			if(flag==1)return;
		}
	}
	}
return;
}

int main()
{
char inp[21][21];

int v,re;
si(re);
int eps;
char x;

rep(v,re){
memset(reach,0,sizeof reach);
si(n),si(m);
scanf("%*c");
flag=0,eps=0;
rep(i,n){
	rep(j,m){

	scanf("%c",&x);;
	if(x == '.'){
		arr[i][j]=1;
		if(i==0 || i==n-1 || j==0 || j==m-1)eps++,ex=i,ey=j;
	
	}else arr[i][j]=0;
	}
scanf("%*c");
}
/*rep(i,n)
	{
		rep(j,m)
	cout<<arr[i][j]<<" ";
cout<<endl;
	}
*/
if(eps!=2)
{
	cout<<"invalid\n";
	continue;
}
	
reach[ex][ey]=1;
start(ex,ey);
if(flag==0)cout<<"invalid\n";
/*rep(i,n)
	{rep(j,m)
	cout<<reach[i][j]<<">> ";
cout<<endl;}
*/}
return 0;
}

