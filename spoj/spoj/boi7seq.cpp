//sort of like the bracket matching part .. you compare and add the corresponding numbers

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
int arr[1000020];
int main()
{
int n,i,j,tem;
//while(1)

long long ans=0;
si(n);
int top = 0;
rep(k,n)
{
si(tem);
while(top)
{
//for all the previous numbers

	if(tem>=arr[top]) //see if the input is greater than top
	{
		if(top == 1) ans+=tem;
		else{
		if(tem>arr[top-1]) ans+=arr[top-1];
		else ans+=tem;
		}
		top--;
	}
	else break;
	
}
arr[++top]=tem;
//stored the num in arr
}

//cout<<ans<<endl;
for(i=1;i<top;i++)
{
ans+=arr[i];
}
cout<<ans<<endl;
return 0;
}

