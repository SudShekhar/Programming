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
int v,re,n,i,k,j,dist,min_dist;
	vector<long long> line;
	vector<long long > ::iterator ind;
	bool set;
	int c,c1;
	si(re);
	int x1,x;
	long long t;
	int check;
	rep(v,re)
	{
		line.clear();
		si(n);
		si(c);
		rep(i,n)
			{
				sl(t);
		line.pb(t);
		}
		sort(all(line));
		int  max=1000000007;
		int min=0;

		while(max>=min)
		{	set= true;
			dist = 0;
			 check =min+(max-min) /2;
	//took mid of max and min
			c1=c-1;
			x=0;
			x1=1;
			while(c1>0)
			{
				while(x1<n && line[x1]-line[x] <check)x1++;			
				if(x1<n)
				{
					c1--;
					x=x1;
					x1++;
				}
				else
				{
					max = check -1;
					set = false;
					break;
					
				}
				//	ind = uper_bound(all(line),dist);
			
			}
			if(set)
			{
				min = check+1;
			}	//if the last loop worked fine we inc min and hope to get the new max
//		cout << "updated max "<<max<<"min "<<min<<endl;
		}

	set=false;	
	int c1 = c-1;
	x=0,x1=1;
	while(c1>0)
	{
		while(x1<n && line[x1]-line[x] <min) x1++;
		if(x1 <n)
		{
			c1--;
			x=x1;
			x1++;
		}
		else{
			printf("%d\n",min-1);
			set=true;
			break;
		}
	}
	if(!set)
		printf("%d\n",min);;
//	cout<<check-1<<endl;
	}

return 0;
}

