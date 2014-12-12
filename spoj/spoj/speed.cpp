//Had absolute issues while coding ... didnt realize both of themm could be anti-clock (i.e. negative inputs) and thus WA

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
#define MIN(a,b) a>b?b:a
LL GCD(LL a,LL b)
{
//	cout<<"GCD of "<<a <<" nad " <<b <<"is";
	LL x;
	while(b!=0)
	{
	x=b;
	b=a%b;
	a=x;
	}
//cout<<a<<endl;	
	return a;
}

int main()
{
long long v,re,i,x,y,n;
float theta;
sl(re);
int count;
LL max , min;
LL gcc;
while(re--)
{
	sl(x);sl(y);
//	x=abs(x);
//	y=abs(y);
	max = x + y - (min=MIN(x,y));
	//gcc = GCD(abs(x),abs(y));
	//x/=gcc;
	//y/=gcc;

	//cout<<abs(x-y)<<endl;
	
//cout << (x-y)/GCD(x,y)<<endl;	
	cout<<abs(max-min)/GCD(abs(max),abs(min))<<endl;
//	cout << count<<endl;
}
return 0;
}

