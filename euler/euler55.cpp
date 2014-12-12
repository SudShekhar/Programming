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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)
unsigned long long rev(unsigned long long n)
{
	LL t=0;
	while(n){
		t= t*10 +  n %10;
		n/=10;
	}
	return t;
}


int main()
{
	int cnt=0;
	unsigned long long temp,tr,r;
	//int i =196;
	rep(i,10001)
	{	tr=0;
		temp = i + rev(i);
		while(tr<50){

			r = rev(temp);
			cout<<" rev of "<<temp<<" is "<<r<<endl;
			//cout<<r<<" "<<temp<<endl;;
			if(temp == r) break;
			temp = r + temp;
			tr++;
		}
		if(tr >=50){
			cnt++;
		cout<<i <<" can't be done "<<endl;
		}

	}
	cout<<cnt<<endl;
	return 0;
}

