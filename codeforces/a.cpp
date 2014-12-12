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
int comp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
int v,re,n,i,j,k,l;
int arr[105];
si(re);

rep(i,re)
{
	si(arr[i]);
}
qsort(arr,re,sizeof(int),comp);
i=0;
while(i<re)
{

	if(arr[i+1] == 0)
	{
		printf("%d",i+1);
		for(k=0;k<=i;k++)
			printf(" %d",arr[k]);
	break;
	}
}
printf("\n");


for( k=re-1;k > i;k--)
{
	if(arr[k-1] ==0)
	{
		printf("%d",re-k);
		for(j=k;j<re;j++)printf(" %d",arr[j]);
	break;
	}
}
printf("\n");

printf("%d",k-i-1);
for(j = i+1;j<k;j++)printf(" %d",arr[j]);
printf("\n");

return 0;
}

