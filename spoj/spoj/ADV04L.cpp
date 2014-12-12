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
vector<int> arr;

LL ** mul(LL **A,LL **B)
{	//int C[3][3];
	LL **C;
	C =(LL**) malloc(sizeof(LL*)*3);
			for(int i=0;i<3;i++)
				C[i] = (LL*) malloc(sizeof(LL)*3);
	int i,j,k;
	for(i=1;i<3;i++)
		for(j=1;j<3;j++)
		{	
			C[i][j]=0;
			for(k=1;k<3;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}

	return C;
}

LL ** RaiseTo(LL **arr, LL base)
{
	if(base == 0)
		{
			LL **ans;
			ans =(LL**) malloc(sizeof(LL*)*3);
			for(int i=0;i<3;i++)
				ans[i] = (LL*) malloc(sizeof(LL)*3);
			//int ans[3][3];
			ans[1][1]=1;ans[1][2]=0;
			ans[2][1]=0;ans[2][2]=1;
			return ans;
		}
	LL **ans = RaiseTo(arr,base/2);
	if (base&1){
//	int *ans = RaiseTo(arr,base/2);
	return mul(mul(ans,ans),arr);
	}
	else return mul(ans,ans);
		// mul(,RaiseTo(base/2);
}
//int n;
vector < long long > store(80);

void fiber( )
{

store[0]=1,store[1]=2;
LL **ans;
			ans =(LL**) malloc(sizeof(LL*)*3);
			for(int i=0;i<3;i++)
				ans[i] = (LL*) malloc(sizeof(LL)*3);
			//int ans[3][3];
			ans[1][1]=1;ans[1][2]=0;
			ans[2][1]=0;ans[2][2]=1;
	
LL **arr;
arr = (LL**) malloc(sizeof(LL*)*3);

rep(i,3)
	arr[i]= (LL*) malloc(sizeof(LL)*3);

arr[1][1]=1;arr[1][2]=1;
arr[2][1]=1;arr[2][2]=0;
	//fprintf(stderr,"yo\n");		

for(int i=1;i<=75;i++)
{
ans = mul(ans,arr);
store[i+1] =  2*ans[1][1] + ans[1][2];
}
//arr is the array to use

/*while(num>0)
{
	if(num&1)
		arr = mul(arr,RaiseTo(arr,num/2));
	else 
		arr = RaiseTo(arr,num/2);
	num<<1;
}
*/

/*
long long ret=0;
long long base =1;
LL prev=0;
//while(num)
//{
LL fans=0;
long long l,r,mid;
while(num >=3)
{
	ret=0,base=1;

l=1; r=75;
//cout<<"set";
while(l<=r)
{
	//cout<<l<< " "<<r<<endl;
mid = l+(r-l)/2;

LL ** ans = RaiseTo(arr,mid);
prev = 2*ans[2][1] + ans[2][2]; 
ret= 2*ans[1][1] + ans[1][2];
//cout<<"mid is "<<mid<<endl;
//cout <<"pre "<< prev << " ret " << ret << " num " <<num<<endl;
//ut<<"left"<<l<<" rig "<<r<< "mid "<< mid<<endl;
//need to work harder! goodnight
if(ret > num && prev <= num) {
	fans+=ret;

	num-=prev;
	break;
}
else if(ret <= num && prev < num)l = mid+1;
else if(ret > num && prev >= num){
	r = mid-1;
//cout<<"yup";
}

//cout<<"right " <<r<<endl;
}

//}
}
if(num == 2) fans+=3;
if(num == 1) fans+=2;


return fans;
*/
}

int main()
{

	int re,v;
	long long n,ans;
	si(v);
	//generate();
	fiber();
	std::vector<long long>::iterator low,up;
	
	//rep(i,75)
		//cout<<store[i]<<endl;
	rep(re,v)
	{	ans=0;
		sl( n);
		while(n>0){
		low=lower_bound(store.begin(), store.end(), n); 
		//cout<<"got "<<*low<<endl;
		if(*low == n)
			low+=1;
		ans+=*(low);
		n-=*(low-1);
		//if(n<10)break;
	}
	cout<<ans<<endl;
	}
		//printf("%lld\n",fibLessThan(n));//<<endl;
		
	
return 0;
}

