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
#define MIN(a,b) a>b?b:a
#define MAX(a,b) a>b?a:b
enum{MIN_TREE,MAX_TREE,SUM_TREE};
LL md;
int getMid(int ss,int se){return (ss + (se-ss)/2);}
int arr[100001];
LL st[300000];

LL createTree(int ss,int se,int index){
if(se == ss){
st[index] = (arr[ss])%md;
//printf("inde %d is %lld\n",index,st[index]);
return st[index];
}
if(ss > se)return INT_MAX;
int mid = ss + (int)(se-ss)/2; //getMid(se,ss);

st[index] = (createTree(ss,mid,2*index+1) * createTree(mid+1,se,2*index+2))%md;

return st[index];

}

LL Minquery(int qs,int qe,int ss,int se,int index){
if(qs <= ss && qe >= se)//contained in the tre segment
	return st[index];

if(qe<ss || qs > se || se < ss)return INT_MAX;

int mid = getMid(ss,se);
return (Minquery(qs,qe,ss,mid,2*index+1) * Minquery(qs,qe,mid+1,se,2*index+2) )%md;
}
/*
int update(int *st,int ss,int se,int num,int val, int index){
if(num==ss && se == num){
	st[index] = val;
	return st[index];
}
int mid = getMid(ss,se);

if(mid < num)st[index] = MIN(st[2*index+1],update(st,mid+1,se,num,val,2*index+2));
else st[index]= MIN(st[2*index+2],update(st,ss,mid,num,val,2*index+1));

return st[index];

}*/

int main()
{
int n,m;
si(n);
//int arr[100];
rep(i,n)si(arr[i]);
md = mod;
createTree(0,n-1,0);
int a,b;
//rep(i,max_size)printf("%lld ",st[i]);
//printf("\n");
si(m);
LL c;
rep(i,m){
	si(a),si(b),sl(c);
	//cout<<md<<endl;
	//fprintf(stderr,"%d\n",md);
	md=c;
	//cout << createTree(0,n-1,0) <<" ----"<<endl;
	//printf("%lld\n",createTree(a-1,b-1,0));
	printf("%lld\n",Minquery(a-1,b-1,0,n-1,0));
}

return 0;
}

