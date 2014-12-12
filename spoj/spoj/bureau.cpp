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

	int v,re,n,i,j;
	cin>>re;
	int len,x;
	string s;
	int ind;
	char str[10];
	rep(v,re)
	{
		cin>>n;
	ind=0;
		vector<bool> arr(n,true);
		vector<int> ans(n);
		vector<int> laws(n,-1);
		len=0;
		for(i=0;i<n;i++)
		{
		//	scanf("%s",s);
			scanf("%s",str);
			if(strcmp(str,"declare")==0)
				laws[i]=-2;
			else{
			si(x);
			laws[i]=x-1;//1 shows cancelin law
			}
		}
//
//		cout<<"hey\n";
		for(i=n-1;i>=0;i--)
		{
			if(arr[i])
			{		//ans.pb(i+1);
				ans[len]=i+1;	
				len++;
				if(laws[i] != -2)
				{
				arr[laws[i]] = false;
				}
			}		
		}
	//	cout<<"yo\n";
		cout<<len<<endl;
		for(i=len-1;i>0;i--)
			cout<<ans[i]<<" ";

		cout<<ans[0]<<endl;
	}
return 0;
}

