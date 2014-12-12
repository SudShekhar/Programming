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
LL HCF (LL a,LL b)
{	LL c;
	while(a%b !=0)
	{
		c = b;
		b=a%b;
		a = c;
	}
	return b;
}

int main()
{
LL p,q,m;
cin>>p>>q;
int n;
cin>>n;
LL arr[102];
rep(i,n)
cin>>arr[i];
LL num = 1;
LL base = arr[n-1];
LL temp,hcf;
int l = 0;
int flag = 1;
if(n>1 && arr[n-1]==1){
arr[n-2]++;n--;
}
for(l=0;l<n;l++)
{
//	cout<<p<<" "<<q<<" = " << arr[l]<<endl;
	if(q==0){flag=0;break;}
	if(p/q == arr[l]){
	temp = q;
	q = p%q;
	p=temp;

	}
	else{
		flag= 0;break;
	}
}
if(flag==1 and q==0) printf("YES\n");
else printf("NO\n");
return 0;
}/*
*while(1)
{
	//
	cin>>n>>m;//si(n),si(m);
		printf("%lld\n",HCF(n,m));
}
for(int i=n-2;i>=0;i--)
{
	//temp = 1/base;
	temp = base;
	base =num + base*arr[i];
	cout<<base<<endl;
	num = temp;
	hcf = HCF(base,num);
	base/=hcf;
	num/=hcf;
	
	//	temp = num;
//	num = base;
//	base = temp;
//	base = arr[i] + temp;
}
cout<<base<< " " <<num<<endl;
if(p>q)
	hcf = HCF(p,q);
	else hcf = HCF(q,p);
p/=hcf;q/=hcf;	
if((base == p and num == q) ) printf("YES\n");
else printf("NO\n");
return 0;
}
*/
