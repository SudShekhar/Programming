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
int arr[101];
double prob[101];
double mat[10001][101];
double ans;
void subs(int n,int sum){
mat[0][0]=1;
ans=0;
FOR(i,1,n+1)mat[0][i]=mat[0][i-1]*(1-prob[i-1]);

FOR(i,1,sum+1)mat[i][0]=0;
int ind;
FOR(i,1,sum+1)
{	FOR(j,1,n+1)
	{
		mat[i][j]=mat[i][j-1]*(1-prob[j-1]);
		//mat[i][j]=0;
		if(i>=arr[j-1])
			mat[i][j]+=mat[i-arr[j-1]][j-1]*prob[j-1];
	}
}
/*rep(i,sum+1){
	rep(j,n+1)
		cout<<mat[i][j]<<" ";
	cout<<endl;
}
*/
}


int main()
{
int v,re;
int n;
si(re);
int sum;
rep(v,re){
si(n);
sum=0;

rep(i,n)si(arr[i]),sum+=arr[i];
rep(i,n)sd(prob[i]),prob[i]/=100;
subs(n,sum);

int start = sum&1?(sum+1)/2:sum/2;
//cout<<sum<<" "<<start<<endl;
FOR(i,start,sum+1)ans+=mat[i][n];
printf("%lf\n",ans);
//printf("%lf\n",a);;
}
return 0;
}

