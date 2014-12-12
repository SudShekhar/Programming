//Realised the pattern made a stupid mistake... used sharky's help

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
#define MAX(a,b) a>b?a:b
int main()
{
int n,i,j;
int v,re;
si(re);int ind,ind2;
vec arr(1000006);
rep(v,re)
{
	cin>>n;
	arr[3]=3;
	arr[2]=0;
	arr[4]=3;
	for(i=5;i<=n;i++)
	{
		ind = (i-2)/2;
		if(i&1)ind2=ind+1;
		else ind2=ind;

		//arr[i]=( (MAX (arr[i/2],arr[i-(i/2)])) + 1);
		arr[i]=( MAX(arr[ind+1],arr[ind2 + 1]) )+1;
	}
cout<<arr[n]<<endl;
}



return 0;
}

