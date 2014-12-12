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
int prim[]={2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,
  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,

 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,

 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,

 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
 479, 487, 491, 499, 503};

int main()
{

	int v,re,c,r;
	si(re);
	int ans;
	char arr[501][501];
	int upper[501][501],lower[501][501],lside[501][501],rside[501][501];
	int mn,l;	
	rep(v,re){
		ans=0;
		memset(upper,0,sizeof upper);
		memset(lower,0,sizeof upper);
		memset(rside,0,sizeof upper);
		memset(lside,0,sizeof upper);

	si(r),si(c);
	getchar();

	rep(i,r)
	{	rep(j,c)
		{
			scanf("%c",&arr[i][j]);
		}
	getchar();
	}
/*	rep(i,r){
		rep(j,c)cout<<arr[i][j];
		cout<<endl;
	}
*/	for (int i=1;i<r;i++)
		for(int j=1;j<c;j++)
		{	if(arr[i][j-1] == '^' && arr[i][j]=='^')
				upper[i][j]=upper[i][j-1]+1;
			
			if(arr[i-1][j]=='^' && arr[i][j]=='^')
				lside[i][j] = lside[i-1][j]+1;
		}

	for (int i = r-2;i>=0;i--)
		for(int j=c-2;j>=0;j--){
		if(arr[i][j+1]=='^' && arr[i][j]=='^')
			lower[i][j] = lower[i][j+1]+1;

		if(arr[i+1][j]=='^' && arr[i][j]=='^')
			rside[i][j]= rside[i+1][j]+1;
		
		}
/*	printf("---------------------------\n");
	rep(i,r)
	{	rep(j,c)
		cout<<lower[i][j]<<" ";
	cout<<endl;}
*/
	for(int i=2;i<r-2;i++)
		for(int j=2;j<c-2;j++){
		
			mn = min(lower[i][j],upper[i][j]);
			mn = min(mn,rside[i][j]);
			mn = min(mn,lside[i][j]);
			l=0;
			while(prim[l]<=mn)l++;
			ans+=l;
		
		}

	printf("%d\n",ans);
	}
return 0;
}

