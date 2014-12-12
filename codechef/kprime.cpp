// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<assert.h>
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
int numFact[100004];//stores numbers of factors each number has
int nFact[100004];
int answer[100004][6];
int Fact[100004];


void setup(){
Fact[0]=0;
Fact[1]=1;

for(int i=2;i<100004;i++)
{
	if(Fact[i] ==0){
	Fact[i]=i;
//	fprintf(stderr,"%d ",i);//<<" ";
//	if(i==317)cout<<"whew\n";

	for(int j=2*i;j<100001;j+=i)Fact[j]=i; //stored that factor there
	//assert(Fact[i]!=0);
	}
}
int n,ans,a;
for(int i=2;i<100001;i++){
n=i;
ans=0;
while(n>1){
	a= Fact[n];
	while(n%a==0 && a!=1)
		n/=a;

ans++;
}
nFact[i]=ans;
}

for(int i=2;i<100001;i++)if(nFact[i]!=numFact[i])cout<<"Problem at"<<i<<endl;
}



void init(){
numFact[0]=6;
numFact[1]=6;
//numFact[2]=1;

for(int i=2;i*i<100004;i++)
{
if(numFact[i]==0){
numFact[i]=0;
for(int j=i*2;j<100001;j+=i)numFact[j]++;
}
}
memset(answer,0,sizeof(answer));
//for each I have the number of factors
for(int i=2;i<100001;i++)
{
	rep(j,6)answer[i][j]=answer[i-1][j];
	if(numFact[i]==0)numFact[i]=1;
	if(numFact[i]<6)answer[i][numFact[i]]++;
}

return;
}

int createSegments(int *st,int *arr,int ss,int se,int index,int val){
if(ss == se){
if(arr[ss] ==val ||( arr[ss]==0 && val==1))st[index]=1;
else st[index]=0;
return st[index];
}
if(ss > se)return 0;
int mid = ss + (se-ss)/2;

st[index] = createSegments(st,arr,ss,mid,2*index+1,val) + createSegments(st,arr,mid+1,se,2*index+2,val);
return st[index];

}

int findans(int *st,int qs,int qe,int ss,int se,int index){
if(ss >=qs && se<=qe)return st[index];
if(ss >qe || se <qs ||se < ss) return 0;

int mid = ss + (se-ss)/2;

return findans(st,qs,qe,ss,mid,2*index+1) + findans(st,qs,qe,mid+1,se,2*index+2);

}

int main()
{
int v,re,m,k;
memset(numFact,0,sizeof(numFact));

init();
setup();
int n = 100001;
int a =2;
int *st1 = (int*)malloc(sizeof(int)*262144);
int *st2 = (int*)malloc(sizeof(int)*262144);
int *st3 =(int*) malloc(sizeof(int)*262144);
int *st4 =(int*) malloc(sizeof(int)*262144);
int *st5 =(int*) malloc(sizeof(int)*262144);

createSegments(st1,numFact,0,n-1,0,1);
createSegments(st2,numFact,0,n-1,0,2);
createSegments(st3,numFact,0,n-1,0,3);
createSegments(st4,numFact,0,n-1,0,4);
createSegments(st5,numFact,0,n-1,0,5);


//si(re);
int ans;
//rep(i,100)cout<<numFact[i]<<" ";
//cout<<endl;
/*int x;
rep(v,re){

si(a),si(m),si(k);
//if(k==1)flag == true;
//a--,m--;


//cout<<endl;
switch(k){
	case 1:x=findans(st1,a,m,0,n-1,0);
	       break;
	case 2: x=findans(st2,a,m,0,n-1,0);
	       break;
	case 3:x= findans(st3,a,m,0,n-1,0);
	       break;
	case 4:x=findans(st4,a,m,0,n-1,0);
	       break;	       
	case 5:x=findans(st5,a,m,0,n-1,0);
	       break;
}
	       if(x!=answer[m][k]-answer[a-1][k]){
		       cout<<"no at "<<a<<" "<<m<<" "<<"for "<<k<<"\n";
		       cout<<x << "-----------------" <<answer[m][k] - answer[a-1][k]<<endl;}
	       else cout<<x<<endl;
//printf("%d\n",ans);
}*/
cout<<"done\n";
return 0;
}

