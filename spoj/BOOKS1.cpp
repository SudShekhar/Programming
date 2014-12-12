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
int v,re;
int arr[5005],s[5005],sum;
int m,k;
si(re);
int col[5003];
rep(v,re)
{
	si(m),si(k);
	rep(i,m)si(arr[i]);
	s[0]=arr[0];
	rep(i,m-1)s[i+1]  = s[i]+arr[i+1];//found cummulative array
	int avgSum = s[m-1]/k;
//	if(s[m-1]%k!=0)avgSum++;
	sum =0;
	k--;
	memset(col,0,sizeof(col));

	for(int j=0;j<m;j++){
	sum+=arr[j];
	if(sum<avgSum)col[j]=k;
	else
	{
	col[j]=k;
	k--;
	sum=0;
//	sum = arr[j]
	}
	}
	rep(i,m-1){
	if(col[i]==col[i+1])printf("%d ",arr[i]);
	else printf("%d / ",arr[i]);
	}
	printf("%d\n",arr[m-1]);
	/*
	rep(i,m){
	sum+=arr[i];
	if(sum<=avgSum)printf("%d ",arr[i]);
	else {
	if(k)printf("/ %d ",arr[i]),k--;
	else printf("%d ",arr[i]);
	
	sum=arr[i];
	}
	}
	printf("\n");
*/
}
return 0;
}

