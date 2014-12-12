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
int arr[100002][26];
matrix di(101);
int prs[] = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

LL pw(LL num,LL base,int md){
	LL ans=1;
int c;

while(base!=0){
c = base&1;
base>>=1;
if(c) ans = (ans*num)%md;
num = (num*num)%md;
}
return ans;
}

void init(){
FOR(i,1,101){
rep(j,26){
if(prs[j]>i)break;
else if(i%prs[j]==0)di[i].pb(j); // pushing in indexes of numbers that divide
}
}/*
FOR(i,1,101){
rep(j,di[i].size())cout<<prs[di[i][j]]<<" ";
cout<<"for "<<i<<endl;
}*/
}



int main()
{
int n;
si(n);
int x;
init();
memset(arr,0,sizeof arr);
si(x);
rep(j,di[x].size())
	while(j!=0 && x%prs[di[x][j]]==0)arr[1][di[x][j]]+=1, x/=prs[di[x][j]];


FOR(i,2,n+1){
si(x);
//cout<<x<<"==";
rep(j,25)arr[i][j] =arr[i-1][j];
rep(j,di[x].size())
	while(j!=0 && x%prs[di[x][j]]==0)arr[i][di[x][j]]+=1,x/=prs[di[x][j]];//,cout<<di[i][j]<<" ";
//cout<<endl;
}
//scanned input
int md,l,r,m;
si(m);
LL ans=1;
rep(k,m){
ans=1;
si(l),si(r),si(md);

FOR(i,0,24){
	//cout<<i<<" "<<i*(arr[l-1][i]-arr[r][i])<<endl;
//	cout<<pw(i,arr[r][i]-arr[l-1][i],md)<<endl;
//11	cout<<prs[i]<<" "<<"raise to "<<arr[r][i]-arr[l-1][i]<<endl;
	ans = (ans* pw(prs[i],arr[r][i]-arr[l-1][i],md))%md;
}

printf("%lld\n",ans%md);
}

return 0;
}

