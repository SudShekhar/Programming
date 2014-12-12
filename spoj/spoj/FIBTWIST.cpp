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
//#define mod 1000000007
int mod;

vector<vector <int> >  mul(vector < vector <int> > arr1,vector < vector <int > >arr2)
{
	vector < vector <int > > C(5,vector<int> (5) );
	int i,k,j;
/*	for(i=1;i<5;i++)
	{for(j=1;j<5;j++)
		cout<<arr1[i][j]<<" ";
		cout<<endl;
	}
	cout<<"intot";
	for(i=1;i<5;i++)
	{for(j=1;j<5;j++)
		cout<<arr2[i][j]<<" ";
	cout<<endl;
	}
	cout<<"Resuk\n";
*/	
	for(i=1;i<5;i++)
	{for(j=1;j<5;j++)
		{
			C[i][j]=0;
			for(k=1;k<5;k++)
				C[i][j]= (C[i][j] + (arr1[i][k]*arr2[k][j])%mod)%mod; //%mod;
			
//			cout<<"C["<<i<<"]["<<j<<"]="<<C[i][j]<<" ";
		}
	//cout<<endl;
	}

///	cout<<"--------\n";
return C;
}


int cal(int base)
{
//	if(base == 0 || base == 1) return (base%mod);
	bool odd;

	//int rem;
	vector < vec > arr(5, vec (5));
	arr[1][1]=1;arr[1][2]=1;arr[1][3]=1;arr[1][4]=0;
	arr[2][1]=1,arr[2][2]=0;arr[2][3]=1;arr[2][4]=0;
	arr[3][1]=0;arr[3][2]=0;arr[3][3]=1;arr[3][4]=1;
	arr[4][1]=0;arr[4][2]=0;arr[4][3]=0;arr[4][4]=1;
//	int ans = 1;

	vector < vec> ans(5,vec(5));
	ans[1][1]=1,ans[1][2]=0,ans[1][3]=0,ans[1][4]=0;
	ans[2][1]=0,ans[2][2]=1,ans[2][3]=0,ans[2][4]=0;
	ans[3][1]=0,ans[3][2]=0,ans[3][3]=1,ans[3][4]=0;
	ans[4][1]=0,ans[4][2]=0,ans[4][3]=0,ans[4][4]=1;

//cout<<"hey\n";
	while (base != 0)
	{	
		if(base&1) odd = true;
		else odd = false;
		//rem = base%2;
		base= base/2;
		if (odd)
		{//	cout<<"ans chn\n";
			ans = mul(ans,arr);
		}// % mod;
		if(base == 0)break;
		//cout<<"arr*arr\n";
		arr= mul(arr,arr);// % mod; 
	//	cout<<"-----";
	//	cout<<ans[0][0]<<endl;
	}
//	return ans;

	return (ans[1][1] + ans[1][4]+ans[3][4])%mod;
}/*
long long cal(int n)
{

//	int **arr;
//	arr = (int **)  
	//vec ans(4);

	if(n==0)return 0;
	if(n==1) return 1;
	//handled weak cases
	vector   < vector<int> > arr1 = power(n-1);
	return (arr1[1][1] + arr1[1][4]+arr1[3][4])%mod;
	//return 2*arr1[1][1] + 2*arr1[1][3] + arr1[1][2];
}
*/
int main()
{
	int v,re,n,m;
	si(re);
	rep(v,re)
	{
		si(n),si(m);

		mod = m;
		if(n < 2)
			printf("%d\n",n);
		else
			printf("%d\n",cal(n-1));
	}

return 0;
}

