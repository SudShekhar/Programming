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
#define min(a,b) a>b?b:a
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

	int v,re,n;
	int i=0,j=0,k=0;
string s;int c;
	cin>>re;
	rep(v,re)
	{
	cin>>s;
	if(s=="1/4")i++;
	if (s=="1/2")j++;
	if(s=="3/4")k++;
	}
//	cout<<i<< " " << j<<" " << k<<endl;
	int ans = 1;

	//while(i!=0 || j!=0 || k!=0)
//	{
	//pair up the 1/4 and 3/4 first
		if(i!=0 && k!=0)
		{
			if(i==k)
			{
				ans+=i;
				i=k=0; //if both same , make them 0
			}
			else{
			c = min(i,k);//remove the smaller one
			i-=c;k-=c;
			ans+=c;
			
			}
		}
		if(k!=0)//remaining 3/4 will take one pizza each : assume : i==0
		{
			ans+=k;
			k=0;
		}
		if(j!=0)//taking out all the 1/2 ones in pairs
		{
			ans+=j/2;
			j=j%2;
		}
		if(j!=0)//if one 1/2 is left 
		{
			ans+=1;
			j=0;
			i=i-2; //reduces i indicating that 2 more slices CAN be eaten along with the one 1/2
		}
		if(i>0)
		{
			ans+=i/4;
			if(i%4!=0)ans++;//if slices are STILL left put them on a separate shit
			i=0;
		}

	cout<<ans<<endl;

	

	return 0;
}

