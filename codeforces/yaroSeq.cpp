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

	int n;
	si(n);
	int p = 0;
	//problem asks you to change any n elements at given stage
	//thus, you can change any set of numbers to all positives , unless there are even positives as in that case number of negatives is odd, and thus if n is even we HAVE to make one positive negative ; let it be the least, subtract twice of it!
	int min = 1002;
	int x;
	int sum = 0;
	rep(i,2*n-1)
	{
		si(x);
		if(x>=0)p++;
		else x=-x;
		sum+=(x);
		min = (x) < min?(x):min;
	}
	if(!(n&1) && !(p&1)) sum -= 2*min; 

	cout<<sum<<endl;
return 0;
}

