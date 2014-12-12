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
#define N 1000001
int arr[N];
int update(int idx,int val, int maxVal)
{
	while(idx<= maxVal)
	{
		arr[idx]+= val;
		idx+= (idx&-idx);
	}
}

int readCumm(int idx)
{
	int v = 0;
	while(idx >0)
	{
		v = (v + arr[idx])%mod;
		idx -= (idx&-idx);
	}
	return v;
}
LL b1,b2;

void calc(){
	update(1,0,N);
	update(2,1,N);
	int x = 0,y=0,z=1;
	FOR(i,3,N)
	{
		//	arr[i] = arr[i-1]+arr[i-2];
		x = (y+z)%mod;
		if(i == N-2)b1 = x;
		else if (i==N-1) b2 = x;

		update(i,x,N);
		y=z;
		z=x;
	}
}
map<int,LL> fibarr;

LL getFib(int n){
	if(n==1)return 1;
	if(n<=0)return 0;
	if(n < N && fibarr[n]!=0){
		//cout<<n<<" is foubd as val "<<fibarr[n]<<endl;
		return fibarr[n];
	}
	int z = (n+1)>>1;
	
	LL FibNMinusOne = getFib(z-1);
	LL FibN = getFib(z);

	if(n&1){
		//int z = n<<1;
	//	if(n < N){
			fibarr[n] = (((FibNMinusOne)*(FibNMinusOne) )%mod + (FibN*FibN)%mod)%mod;
		return fibarr[n];
	//	}
		//	return (((FibNMinusOne)*(FibNMinusOne) )%mod + (FibN*FibN)%mod)%mod;
	}

	else{
	//	if(n < N){
		fibarr[n]= ((((2*FibNMinusOne)%mod + FibN)%mod) * FibN) %mod;
		return fibarr[n];
	//	}

	//	return ((((2*FibNMinusOne)%mod + FibN)%mod) * FibN) %mod;
	}
}


int main()
{
	int v,re;
	int n,m;
	//fill(arr,0);
	//calc();
	int b1,b2,b3,b4,k;
	si(re);
	LL ans=0;
	rep(v,re){
		si(n),si(m);
		/*if(n < N && m < N)
		  {
		  a1 = readCumm(n);
		  a2 = readCumm(m);
		  if(a2 < a1) a2+=mod;

		  cout<<a2-a1<<endl;
		  }
		  else if(n < N && m > N)
		  {
		  a1 = readCumm(n);
		  a2 = readCumm(N);
		  if(a2 < a1) a2+=mod;
		  an = a2 - a1;
		  FOR(i,N,m+1){
		  ans= (b1 + b2)%mod;
		  an = (an+ans)%mod;
		  b1 = b2;
		  b2 = ans;
		  }
		  cout<<an<<endl;


		  }
		  else if (n> N && m > N)
		  {
		  ans= 0;
		  FOR(i,N,n)
		  {
		  ans = (b1+b2) % mod;
		  }
		  }*/

	//	b1 = getFib(n);
		
	//	k = m - n;
		//b2 = getFib(k);
		//b3 =  getFib(k-1);
		LL b4 = getFib(n+1);
		LL b2 = getFib(m+2);
		if(b2 < b4) b2 += mod;
		cout<<b2-b4<<endl;
		//cout<<b1 << " "<<b2 <<" "<<b3<<" "<<b4<<endl;
		//ans = ((b1*b3)%mod + (b2*b4)%mod)%mod;
		//ans =( b1 + b2)%mod;
		//cout<<ans<<endl;
	}

	return 0;
}

