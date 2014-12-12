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
#define mod 3046201
long long pw(LL num, int base)
{
	bool odd;
	LL ans=1;
	while(base!=0)
	{
		if(base&1)odd=true;
		else odd=false;
		base = base/2;
		if(odd)
			ans=(ans*num )%mod;
		num= (num*num) %mod;
		//if(num < 0)printf("%lld\n",num);

	}
	return ans;
}

int arr[100002];
LL fact[3000002];
LL invfact[100002];
int MX = 1000000;

void extend(int n){
	for(LL i=MX;i<=n;i++)
		fact[i]=(fact[i-1]*(i%mod))%mod;
	MX = n+1;
}

void init(){
	fact[0]=1;
	fact[1]=1;
	invfact[0]=1;
	invfact[1]=1;
	for(LL i=2;i<MX;i++)
		fact[i]=(fact[i-1]* (i%mod))%mod;
	
	return;
}
//got all factorials and inverserfactorials that i might need.
int tree[100003];
void inc(int,int,int);

void settree(int n){
for(int i=0;i<n;i++)
{
inc(i,arr[i],n);
}
}

void inc(int i,int d,int n){
	for(int j=i;j<n;j|=j+1)
		tree[j]+=d;
}


int sum(int ind)
{
int s=0;
while(ind>=0){
s+=tree[ind];
ind&=ind+1;
ind--;
}
return s;
}
int getsum(int l,int r)
{
	if(l==0)return sum(r);
return sum(r)-sum(l-1);
}
int main()
{
	init();int x,y;
	/*for(int i=2;i<10000;i++)
		printf("%lld\n",fact[i]*invfact[i]%mod);
	r*/
	int n,q;
	si(n);
	int k;
	LL ans;
	rep(i,n)si(arr[i]);
	settree(n);
	//cumm[0]=0;
	//FOR(i,1,n+1)cumm[i]=cumm[i-1]+arr[i];
	si(q);
	int sum,diff;
	char s[20];
	int each,rem,quant;
	LL invf;
	rep(j,q){
	scanf("%s",s);
	si(x),si(y);
	
	if(s[0]=='c')
	{	
	x--;
	inc(x,y-arr[x],n);
	arr[x]=y;
	}
	else{
		x--,y--;
		sum=getsum(x,y);
		
		//for(int l=x;l<=y;l++)sum+=arr[l];
	//	printf("%d\n",sum);
		k = y-x+1;
		each = sum/k;
		rem = sum%k;
		quant = k - rem;
		//cout<<"Divide "<<sum<<" beries in "<<k<<" with "<<quant<<" getting "<<each <<" and "<<rem<<" geting "<<each+1<<endl;
		if(sum>MX)extend(sum);

		ans = fact[sum];
		LL t=1;
		if(invfact[each]==0)
			invf = pw(fact[each],mod-2),invfact[each]=invf;
		else invf = invfact[each];
		//rep(l,quant){//number that get stock amount
		t= pw(invf,quant);
	//	}
		ans=(ans*t)%mod;
		t=1;
		if(invfact[each+1]==0)
			invf = pw(fact[each+1],mod-2),invfact[each+1]=invf;
		else invf = invfact[each+1];

		
		t=pw(invf,rem);
		ans=(ans*t)%mod;

		if(invfact[quant]==0)
			invf = pw(fact[quant],mod-2),invfact[quant]=invf;
		else invf=invfact[quant];

		ans=(ans*invf)%mod;
		
		if(invfact[rem]==0)
			invf = pw(fact[rem],mod-2),invfact[rem]=invf;
		else invf = invfact[rem];

		ans=(ans*invf)%mod;
		ans=(ans*fact[k])%mod;
		
		printf("%lld\n",ans);

	}
	
	}
	
	return 0;
}


