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

int comp(const void*a,const void*b){
return *(int*)a - *(int*)b;
}

int main()
{
int n,m,k;
si(n),si(m),si(k);
int arr[100001],mat[100001];

rep(i,n)si(arr[i]);
rep(i,m)si(mat[i]);

qsort(arr,n,sizeof(int),comp);
qsort(mat,m,sizeof(int),comp);

if(m<n){//if bob has lesser fish,he is done
cout<<"YES\n";
return 0;
}


int c=0;
//n is alice
int j=0;
rep(i,n){
while(j<m && mat[j]<arr[i])j++;
if(j==m){
cout<<"YES\n";
return 0;
}
j++;

}


//cout<<"YES\n";
cout<<"NO\n";
return 0;
}

