//Learned that passing vectors as args leads to full copy of them being made

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
vector<char> ans;
int n;
int flag=0;
string s;
vector<char>arr;
int LEN;
void create()
{
	char i,j;
int len = LEN;
if(len==2*n)
{
	rep(k,2*n)
	ans[k]=arr[k];
	flag=1;
	return;
}

for( i ='A';i<='E';i++)
	{
		if(i!=s[len] && i!=s[len+1] && i!=arr[len-1])
			break;
	}
for(j='A';j<='E';j++)
{
	if(j!=s[len] && j!=s[len+1] && j!=i)break;

}
if(i=='E' || j=='E')return;

arr.pb(i);
arr.pb(j);
LEN+=2;
create();

if(flag ==0) {
	arr.pop_back();arr.pop_back();

	arr.pb(j);
	arr.pb(i);
	create();
}

return;

}
int main()
{
	int v,re;
	//	string s;
	//int n;
	cin>>n;
	cin>>s;


	//vector<char> arr;
	arr.clear();
	ans.clear();
	ans.resize(2*n);
	char i,j;
	for( i ='A';i<='D';i++)
	{
		if(i!=s[0] && i!=s[1])
			break;
	}
	for(j='A';j<='D';j++)
	{
		if(j!=s[0] && j!=s[1] && j!=i)break;

	}
	LEN=2;
	arr.pb(i);
	arr.pb(j);
	create();
	if(flag ==0) {
		arr.clear();
		arr.pb(j);
		arr.pb(i);
		create();
	}

	rep(k,2*n)
		cout<<ans[k];
	cout<<endl;
	return 0;
}

