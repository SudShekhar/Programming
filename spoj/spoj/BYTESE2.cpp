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
class pt
{public:
int val;
int type;
};
bool mycomp(pt x, pt y)
{
	return x.val < y.val;
}
int main()
{

	int re,v,n,i,j,max,val;
	si(re);
	vector< pt > arr;
	rep(v,re)
	{
		si(n);
		arr.clear();
		arr.resize(2*n);

		for(i=0;i<2*n;i+=2){
			si(arr[i].val);
			arr[i].type = 1;
			si(arr[i+1].val);
			arr[i+1].type = 0;

	//		cout<<"arr " <<arr[i].val<<" "<<arr[i+1].val<<endl;
		}
		//rep(k,2*n)cout<<arr[k].val<<" ";
	//	
		sort(all(arr),mycomp);

	//	rep(k,2*n)cout<<arr[k].val<<" ";
		val=0,max=0;
		rep(k,2*n)
		{
			if(arr[k].type == 1)val++;
			if(val > max ) max = val;
			if(arr[k].type == 0) val--;
		}
		cout<<max<<endl;

	}

return 0;
}

