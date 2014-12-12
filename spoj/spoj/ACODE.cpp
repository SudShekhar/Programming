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
	//dp problem f(n) = f(n-1) + (a[n]<=6&&a[n-1]<=2)?f(n-2):0
	char s[5003];
	LL dp[5003];
	int len;
	while(1)
	{
		scanf("%s",s);
		len=strlen(s);
		if(s[0]=='0')break;
		dp[1]=1;
		dp[2]=1;
		
		if(s[1]!='0' && (((int)s[0]-'0'==2 && (int)s[1]-'0'<=6) ||s[0]-'0'==1 )){
		dp[2]++;
		};
		//if(s[0]<='2' && s[1]<='6')cout<<dp[2]<<endl;
		//printf("s[0]<<" "<<'2'<<endl;
		for(int i=3;i<=len;i++)
		{
		dp[i]=0;
		if(s[i-1]!='0')
		{	
		dp[i]+=dp[i-1];
		
		if(s[i-1]-'0'<=6 && s[i-2]-'0'==2 || s[i-2]-'0'==1)
			dp[i]+=dp[i-2];	
		}
		else dp[i]=dp[i-2];
		}
		printf("%lld\n",dp[len]);
	}
	//printf("%c\n",'a'+24);


return 0;
}

