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
#define max(a,b) a>b?a:b
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
	int re,v,i,j,k;
	int n,m,count;
	int l,r,weight,temp;
	si(re);
	rep(v,re)
	{
		cin>>l>>r;
	weight = r-l;
cin>>n;
vector<int> val(n),w(n),ans(weight + 1,0);
	rep(l,n)
	{
	cin>>val[l]>>w[l];
	}
	ans[0]=0;

	for(k=1;k<=weight;k++)
	{	temp = 10000000;
		for(i=0;i<n;i++)
		{
			
		if(k>=w[i])
		{
	//		cout<<"got in"<<w[i]<<endl;
		 temp = min(val[i] + ans[k - w[i]],temp);
//		cout<<temp<<endl;		
		}

	
		}
	ans[k]=temp;
	//	cout<<"min amount for "<<k<<"is "<<ans[k]<<endl;	

	}
	if(ans[weight]==10000000)
	{
		cout<<"This is impossible.\n";

	}
	else{
	cout<<"The minimum amount of money in the piggy-bank is "<<ans[weight]<<"."<<endl;
	}


}
return 0;
}

