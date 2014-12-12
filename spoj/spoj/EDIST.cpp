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
#define min(a,b) a>b?b:a
int main()
{
int v,re;
string s,s1;
cin>>re;
int i,j,k;
int l1,l2;
rep(v,re)
{
	cin>>s>>s1;
	l1=s.length()+1;
	l2 = s1.length()+1;
	vector< vector<int> > arr( l1  , vector<int > (l2));

	for(i=0;i<l1;i++)
		arr[i][0]=i;
	for(j=0;j<l2;j++)
		arr[0][j]=j;

	for(i=1;i<l1;i++)
	{
		for(j=1;j<l2;j++)
		{
			int t = arr[i-1][j-1];

			if(s[i-1]!=s1[j-1]){
			t++;
			}
				arr[i][j] = min((min(arr[i-1][j],arr[i][j-1]))+1,t);
		}

	}
/*	rep(k,l1)
	{	rep(z,l2)
			{cout<<arr[k][z]<<" ";
			}
	cout<<endl;
	}
*/	cout<<arr[l1-1][l2-1]<<endl;
}
	return 0;
}

