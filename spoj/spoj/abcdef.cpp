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


/*long long  bins(long long  toFind,long long  l,long long r)
{
	if(r<l)return -1;
 	long long  m = l+(r-l)/2;

	if(two[m]==toFind)return m;

	else if(two[m]>toFind) return bins(toFind,l,m-1);
	
	else return bins(toFind,m+1,r);
}
*/
int main()
{

	vector <int > one,two;
	int n,i,j,k;
	int ans,exp;
	si(n);
	int ind;
	int  len = n*n*n;
	//vector <int> one(len),two(len);
	vector <int > num(105);
	//one.resize(len);
	//two.resize(len);
	pair<vector<int >::iterator,vector<int >::iterator> bounds;
	
	rep(i,n)
	{
		si(num[i]);
	}

	rep(i,n)
		rep(j,n)
			rep(k,n)
			{
				one.pb((num[i]*num[j]) + num[k]);
				if(num[i]!=0)
					two.pb(num[i]*(num[j]+num[k]));
			}
	ans=0;
	
	
	sort(all(two));
	
	rep(i,len)
	{
	
		bounds = equal_range (two.begin(),two.end(),one[i]);
		ans+= (int)(bounds.second - bounds.first);
	
	}
	cout<<ans<<endl;



return 0;
}

