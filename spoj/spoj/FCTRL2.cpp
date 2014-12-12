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
int ans[200];
int len;

void mul(int n)
{
	int temp = 0;
	for(int i=0;i<len;i++)
	{
		ans[i]*=n ;
		ans[i]+=temp;
		temp=0;
		if(ans[i] >9){
			temp = ans[i]/10;
		ans[i]%=10;
		}
	}
	while(temp!=0)
	{
		ans[len] = temp%10;
		temp/=10;
		len++;
	}
	
}

int main()
{
int v,re;
si(re);
int n,i;
rep(v,re)
{
	len=1;
	ans[0]=1;
	si(n);
	for(i=1;i<=n;i++)
	{
		mul(i);
	}
	for(i=len-1;i>=0;i--)
	{
		cout<<ans[i];
	}
	cout<<endl;


}
return 0;
}

