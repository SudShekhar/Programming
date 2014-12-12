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
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


int main()
{
	//set < int> myset,wrongOnes;
	int ref[101]={-1,1,-1,-1,-1,-1,-1,5,-1,-1,1,-1,-1,2,-1,-1,-1,-1,-1,4,-1,-1,-1,3,-1,-1,-1,-1,3,-1,-1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-    1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,3,-1,-1,-1,2,-1,-1,-1,-1,4,-1,-1,4,-1,-1,3,-1,-1,1};
	int n,x,sum,flag;
	int v,re,count;
	//si(re);
	//char arr[10],arr1[10];
	int sq[10] = {0,1,4,9,16,25,36,49,64,81};
	
	bool ans;
	int past[1000000];
	scanint(re);
	
	rep(v,re){
		scanint(n);
		ans = false;
		 count=0;
		 flag = 0;
		past[0]=n;
		while(1)
		{
			count++;sum=0;
			while(n)
			{
				x= n%10;
				sum+=sq[x];
				n/=10;
			}
			if(sum<=100)
			{	
				if(ref[sum]!=-1)
					{
						ans=true;
						count+=ref[sum];
					}
				else ans = false;
				break;
			}
			rep(k,count)
			{
				if(past[k] == sum ) {
				ans = false;flag =1;
				break;
				}
			}
			if(flag == 1)break;
			
			past[count] = sum;
			n=sum;
		}
		
		if(ans)printf("%d\n",count);
		else printf("-1\n");
	}
	return 0;
}


