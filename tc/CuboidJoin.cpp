// BEGIN CUT HERE

// END CUT HERE
#line 5 "CuboidJoin.cpp"

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


class CuboidJoin {
public:
struct pt{
int x,y,z;
int l;
};
int rank[101];

int comp(const void*a,const void*b){
pt * c = (pt*)a;
pt *d = (pt*)b;
int ret = c->x-d->x;
if(ret==0)ret = c->y-d->y;
if(ret==0)ret = c->z-d->z;
return ret;
}

int cmp(const void*a,const void*b){
return rank[((pt*)a)->l] - rank[((pt*)b)->l];
}


int vol(pt a,pt b){
return (a.x-b.x)*(a.y-b.y)*(a.z-b.z);
}
long long totalVolume(vector <int> cuboids) {

int len = cuboids.size();
pt left[len/6 +1];
pt right[len/6+1];
int i=0;
while(i<len){

left[i].x  = cuboids[i];
left[i].y  = cuboids[i+1];
left[i].z  = cuboids[i+2];
left[i].l  = i;
right[i].x = cuboids[i+3];
right[i].y = cuboids[i+4];
right[i].z = cuboids[i+5];
right[i].l = i;
i+=6;
}
//created arrays
LL ans =0;
len/=6;
sort(left,left+len,comp);
rep(i,len/6)rank[i]=left[i].l;
qsort(right,len,sizeof(*right),cmp);
//sorted left &&right
rep(i,len){
ans += vol(right[i],left[i]);
FOR(j,i+1,len)
	if(left[j].x<right[i].x || left[j].y<right[i].y||left[j].z<right[i].z)
		ans-=vol(right[i],left[j]);
}
return ans;
}
};


