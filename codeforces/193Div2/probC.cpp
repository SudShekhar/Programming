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
typedef struct request{
int numHair;
int dissp;
int num;
} req;

int comp(const void *a,const void *x){
req *c = (req*)a;
req* b= (req*)x;
int ret;
ret =  (b->dissp-c->dissp);
if(ret==0)
ret = b->numHair > c->numHair;
return -ret;

}
int main()
{
int n,k,p;
si(n),si(k),si(p);
req arr[n];

rep(i,n)arr[i].num = i+1,si(arr[i].numHair),si(arr[i].dissp);

qsort(arr,n,sizeof(req),comp);
//rep(i,n)cout<<arr[i].dissp<<" "<<arr[i].numHair<<endl;

rep(i,k-1)cout<<arr[i].num<<" ";
cout<<arr[k-1].num<<endl;

return 0;
}

