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

int arr[100001];
int a[100001];
int b[100001];
int comp(const void* a,const void*b){
return *(int*)a - *(int*)b;
}

int main()
{
int n;
si(n);
rep(i,n)si(arr[i]);
qsort(arr,n,sizeof(int),comp);
int x,y;
rep(i,n/3)a[i]=0,b[i]=arr[i];

bool flag=true;
FOR(i,n/3,n){
x = arr[i]/2;
y = arr[i]-x;
cout<<arr[i]<<" "<<x<<" "<<y<<endl;
if(i>n/3+2){
if(a[i-1]==a[i-2]&& a[i-1]==a[i])flag = false;
}
if(flag==false)break;
if(a[i-1] == x){
	a[i]=y,b[i]=x;
}

else {
	if(x==y)x++,y--;
	a[i]=x,b[i]=y;
	
}
}
if(flag==false)cout<<"NO\n";
else{
rep(i,n-1)cout<<a[i]<<" ";
cout<<a[n-1]<<endl;

rep(i,n-1)cout<<b[i]<<" ";
cout<<b[n-1]<<endl;
}

return 0;
}


