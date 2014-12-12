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

	int re,v,n,i;
	string s;
	cin>>re;
	rep(v,re)
	{
	vector<int> arr(26,0);
	char  buf[1000];
	scanf("%*c");
	scanf("%[^\n]",buf);
	string s(buf);
//	cout<<"hey\n";
	int len = s.length();
//	cout<<"len = "<<len<<endl;
	int ind;
	rep(i,len)
	{	//cout<<"mis"<<endl;
		ind = tolower(s[i]) - 'a';
		if( ind<26 && ind >=0)
		arr[ind]++;
	}
//	cout<<"nnop"<<endl;
	sort(all(arr));
	
//	cout<<"yo\n";
	int count = 0,x=26;
	while(x!=0)
	{	//cout<<arr[x-1]<<endl;
		count+=arr[x-1]*x;
		x--;
	}
	cout<<"Case #"<<v+1<<": "<<count<<endl;

		
	}

return 0;
}

