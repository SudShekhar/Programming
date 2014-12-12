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
//idea : use a stack and add numbers that are greater than prev.. pop out smaller ones and match to get ans

vector<long long> arr(100001);
vector<long long> tm(100001);
int main()
{
int n;
long long  tem;
int rank;
int i,j,ans,top;
long long  max;
int t;
while(1){
	max = 0;
	si(n);
	if(n==0)break;
top = ans = 0;

rep(k,n)
{
	sl(tem);
	rank=1;
	t=k;
	while(top){
		
		if(tem < arr[top]){
			if(max < arr[top]*(k-tm[top]))
				max = arr[top]*(k-tm[top]);
		t=tm[top];
			top--;
		
		}
		else break;	
	}
	arr[++top]=tem;//stored the first num and the rest coming in line
	tm[top]=t;
	//cout<<"stored "<<tem<<"at "<<top<<"on time "<<k<<endl;
}
//cout<<max<<endl;
rank=1;
for(int i=top;i>0;i--)
{	
//	cout<<"Number "<<arr[i]<<"since"<<tm[i]<<"at ind "<<i<<endl;
	if(max < arr[i]*(n-tm[i]))  max = arr[i]*(n-tm[i]);

}
cout <<max<<endl;

}
return 0;
}


