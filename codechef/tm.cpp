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

int main()
{
	map <float,int> ref;
	vector<float> a;
int i,j;
pair<map<float,int>::iterator,bool> ret;
for(i=1;i<10;i++)
{
	for(j=1;j<10;j++)
	{
		
	float z= (float)i/(float)j;
	
	//map[z]++;
	ret=ref.insert(mp(z,1));
	if(ret.second==false)
	{
		ref[z]++;
	}
	else a.pb(z);
	}
	
}

map<float,int>::iterator it;
//
ref.clear();
vector <float > mat;

for(i=0;i<56;i++)
	for(j=0;j<56;j++)
{
	
	float z= a[i]*a[j];
	
	//map[z]++;
	ret=ref.insert(mp(z,1));
	if(ret.second==false)
	{
		ref[z]++;
	}
	else mat.pb(a[i]*a[j]);
	
}


//596 unique for 4 such elements

ref.clear();
a.clear();
for(i=0;i<597;i++)
	for(j=0;j<597;j++)
{
	
	float z= mat[i]*mat[j];
	
	//map[z]++;
	ret=ref.insert(mp(z,1));
	if(ret.second==false)
	{
		ref[z]++;
	}
	else a.pb(a[i]*a[j]);
	
}
for ( it=ref.begin() ; it !=ref.end(); it++ )
cout << (*it).first << " => " << (*it).second << endl;



return 0;
}

