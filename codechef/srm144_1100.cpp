#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<utility>
#include<stack>
#include<queue>
#include<map>
using namespace std;



#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define f(i,start,end) for(i=start;i<end;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define  sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))


#define SI(a) scanf("%d",&a)
#define SC(a) scanf("%c",&a)
#define SL(a) scanf("%lld",&a)
#define SS(a) scanf("%s",a)
#define SF(a) scanf("%f",&a)
#define Pi(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define LL long long

typedef pair<int,int> PI;
typedef vector<int> vec;
typedef vector<vec> matrix;


class PowerOutage{
	private:
		int sum;
		int arr[50][50];	
		int vis[50];		
		int count;
	public:
		void dfs(int node)
		{
			//printf("got count= =%d for node=%d\n",count,node);
			count--;
			int i;
			vis[node]=1;
			for(i=49;i>=0;i--)
			{
				if (arr[node][i]!=0 && vis[i]==0)
				{
					sum+=arr[node][i];
					dfs(i);
					if(count>0)
						{//	printf("count is %d for node==%d\n",count,node);
							sum+=arr[node][i];
						}
				}
			}
		}
		int estimateTimeOut(vec fromJunction,vec toJunction,vec ductLength){
		int i,j,k;
		sum=0;
		
		int len=fromJunction.size();
		
		count=len;
	for(i=0;i<50;i++){
		vis[i]=0;
		for(j=0;j<50;j++)
				arr[i][j]=0;
		}
		for(i=0;i<len;i++)
		{
			arr[fromJunction[i]][toJunction[i]]=ductLength[i];
		}
		
	
		dfs(0);
		return sum;
		}
};

int main()
{
PowerOutage a;

vec x (1,1);
vec b (1,0);
vec c (1,10);	
Pi(a.estimateTimeOut(b,x,c));
return 0;

}

