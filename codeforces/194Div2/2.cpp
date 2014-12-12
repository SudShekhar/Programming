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
typedef struct st{
int x;
int y;
}st;

int comp(const void *a,const void *b){
st* c = (st*)a;
st *d = (st*)b;

int ret = c->x - d->x;
if(ret==0)ret =c->y - d->y;
return ret;

}
int main()
{
st arr[8];
rep(i,8)
	si(arr[i].x),si(arr[i].y);

qsort(arr,8,sizeof(st),comp);

int x[3],y[3];

x[0]=arr[0].x;
y[0]=arr[0].y;
y[1] = arr[1].y;
y[2]=arr[2].y;
x[1] =arr[3].x;
x[2]=arr[7].x;
set <pair< int,int> > sett;
pair<int,int>a;
rep(j,8){
int ind1=4,ind2=4;	
rep(i,3){
if(arr[j].x==x[i]){
	ind1=i;break;}
}
rep(i,3){
if(arr[j].y==y[i]){
	ind2=i;
	break;}

}
if(ind1>2||ind2>2){
cout<<"ugly\n";return 0;
}

a = mp(x[ind1],y[ind2]);
if(sett.count(a)==1){
cout<<"ugly\n";return 0;

}
else sett.insert(a);
}

rep(i,3)
	rep(j,3)
{		a=mp(x[i],y[j]);
	if(i==1&&j==1){
	if(sett.count(a)==1){
	cout<<"ugly\n";
	return 0;
	}
	continue;
	}
	if(sett.count(a)==1)continue;
	else{
	cout<<"ugly\n";
	return 0;
	}

}
cout<<"respectable\n";
return 0;
}

