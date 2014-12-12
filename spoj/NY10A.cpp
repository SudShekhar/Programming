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


int main()
{
string str;
int v,re,n;
si(re);
int ind;
rep(v,re)
{
	si(n);
	int mat[8];
	fill(mat,0);
	cin>>str;
	rep(i,38){
	//int i =0;
	ind = 0;
	ind |= str[i]=='H'?4:0;
	ind |= str[i+1]=='H'?2:0;
	ind |= str[i+2]=='H'?1:0;
	//cout<<str[i]<<str[i+1]<<str[i+2]<<" == " <<ind<<endl;
	mat[ind]++;
	}
	printf("%d ",n);
	rep(i,8)
		pi(mat[i]);
	printf("\n");
}
return 0;
}

