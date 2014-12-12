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
// #define max(a,b) a>b?a:b
// #define min(a,b) a<b?a:b
#define sqr(x) (x*x)
int getSteps(int n){
	if(n==1 || n==0)
		return n;
	else if(n&1)
		return 2+getSteps(n/2);
	else return 1+getSteps(n/2);

}

int getMin(vec arr){
	// int ans=0;
	int c,numOnes;
	int sum=0;
	int mx=0;
	rep(i,arr.size()){
		int x = arr[i];
		c=0;
		numOnes=0;
		while(x){
			if(x&1)
				numOnes++;
			sum+=x%2;
			c++;
			x>>=1;
		}
		mx = max(c,mx);
	}
	return sum+mx-1;
}


int main(){
	vec arr(50);
	int n;
	si(n);
	arr.resize(n);
	rep(i,n)
		si(arr[i]);
	cout<<getMin(arr)<<endl;
	return 0;	

}