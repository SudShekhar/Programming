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
int m;
si(m);
int arr[100002];
int diff[100002];
rep(i,m)si(arr[i]);
sort(arr,arr+m);

int ans=0,ind=0;
int lst[30002];int flag;
while(ans<30000 && ind < m)
{	flag=0;
	rep(j,ans){
	if(diff[arr[ind]-lst[j]] !=0){
		flag=1;
		break;}
	}
	if(flag==0){
		lst[ans++]=arr[ind];
		rep(j,ans-1)diff[lst[ans-1]-lst[j]]++;
			}
	ind++;
}
printf("%d\n",ans);
rep(j,ans-1)printf("%d ",lst[j]);
printf("%d\n",lst[ans-1]);
return 0;
}

