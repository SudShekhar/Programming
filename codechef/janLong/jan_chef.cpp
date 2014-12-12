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
map <string,string> list;
map <string,int> name,ctry;
string first,sec;
int re,v,n,i,j,k,m;
cin>>n>>m;
string ans1,ans2;
int max1=-100000,max2=-10000;
	for(v=0;v<n;v++)
	{
		cin>>first>>sec;
		list[first]=sec;
		ctry[sec]=0;
		name[first]=0;

	}

	for(i=0;i<m;i++){
		cin>>first;
		name[first]++;
		if(name[first]>max1 || (name[first]==max1 && first<ans1)){
			ans1=first;
			max1=name[first];
		}

		ctry[list[first]]++;
		
		if(ctry[list[first]]>max2 || (ctry[list[first]]==max2 && list[first]<ans2)){
			ans2=list[first];
			max2=ctry[list[first]];
		}
	}
	cout<<ans2<<endl<<ans1<<endl;

return 0;
}

