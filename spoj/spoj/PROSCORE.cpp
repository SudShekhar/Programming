//SUPER EASY
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
#define nl printf("\n")
typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007

int main()
{
int v,re;
si(re);
long long n,p,i,j;
int count;
bool first,second,third;
int t;
rep(v,re)
{
	sl(n);sl(p);
	first=second=third=true;

	vector<int> arr(p,0);
	rep(i,n)
	{	count=0;	
		rep(j,p)
		{
			si(t);
			count+=t;
			arr[j]+=t;
		}
//		cout<<"got count ="<<count;nl;
		if(count ==0 )second = false;
		else if(count >= p)third = false;
	}
	rep(j,p)
	{
//		cout<<arr[j]<<" ";nl;
		if(arr[j]==0)first = false;break;
	}
	long long  ans=0;
//	cout<<first<<" "<<second<< " " <<third;nl;
	if(first)ans+=4;
	if(second)ans+=2;
	if(third)ans+=1;
	//ans<<endl;
	printf("Case %d: %lld\n",v+1,ans);
}	
return 0;
}

