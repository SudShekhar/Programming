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


int main()
{

	int n;
	int ar[100001],arr[100001];
	si(n);
	rep(i,n)si(ar[i]);
	sort(ar,ar+n);
	int k=0;
	while( (ar[k]&1) !=0)k++;
	arr[0]=ar[k];
	int j=1;
	while(k<n)	
	{	if(ar[k]!=ar[k-1] && !(ar[k]&1)) arr[j++]=ar[k];
	k++;}
	//store all even numbers
	int N=n;
	n=j;	
	if(n){
	int start,end;
	LL base;
	base=1;
	while(base<arr[n-1])base*=2;
	if(base!=arr[n-1])base/=2;
	end=n-1;
	start=n-1;
	int i = n-2;

	LL val= arr[n-1];
	if(!(val&(val-1)));
	else{
	while(i>=0){
	val&=arr[i--];
	if(!(val&(val-1)))break;
	}
	}
	LL temp = val;
	while(i>=0){
	temp&=arr[i];
	if(temp==val)i--;
	else break;
	}
	//printf("%d\n",end-i);
	//i+=1;
	//for(;i<=end;i++)printf("%d\n",arr[i]);
	int cnt=0;
	rep(l,N){
	if(ar[l]>=val && ar[l]<val*2)cnt++;
	}
	printf("%d\n",cnt);
	rep(l,N){
	if(ar[l]>=val && ar[l]<val*2)printf("%d\n",ar[l]);
	}
	}
	else{
	printf("%d\n",n);
	rep(i,n)printf("%d\n",ar[i]);
	}
return 0;
}

