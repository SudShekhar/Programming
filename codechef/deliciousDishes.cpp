#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string.h>

#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<utility>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
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
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define LL long long

typedef pair<int,int> PI;
typedef vector<int> vec;
typedef vector<vec> matrix;
int fac(int n)
{
	vec arr(10);
	arr[0]=1;
	int i;
	f(i,1,n)
	{
		arr[i]=arr[i-1]*i;
	}
	return arr[n];
}


int count(int n)
{
	vec cs(10);
	cs[0]=0;
	cs[1]=1;
	int i;
	f(i,1,n)
	{
		cout << fac(10-i);
		//cs[i+1]=cs[i] + 9*fac(9)/fac(10-i);
	}
	return cs[n];
}

		

int main()
{
	int i,j,k,re,v,n,m;
	string arr;
	int sum;
	SI(re);
	rep(v,re)
	{
		cin >> arr;
		n=arr.length();
	if(n>11) PI(count(11));
	else 
	{
		sum=0;
		sum+=count(n);
		PI(sum);
	}
	}
//till now we have counted all numbers possible with less than the value given;
	return 0;
}

