#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<utility>
#include<stack>
#include<queue>
#include<map>
using namespace std;



//#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define f(i,start,end) for(i=start;i<end;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define INF INT_MAX
#define all(x) x.begin(),x.end()
#define pb push_back
#define  sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))


#define SI(a) scanf("%d",&a)
#define SC(a) scanf("%c",&a)
#define SL(a) scanf("%lld",&a)
#define SS(a) scanf("%s",a)
#define SF(a) scanf("%f",&a)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define LL long long

typedef pair<int,int> PI;
typedef vector<int> vec;
typedef vector<vec> matrix;


int main()
{	int arr[5001];
	int n,i,j,k,m;
	int re,v;
	SI(re);
	int min =1000000009;
	rep(v,re){
		SI(n);
	//	arr.clear;
		
		rep(i,n)
		{	
			SI(arr[i]);
			//arr[i]=m;
		}
		/*rep(i,n) cout<<arr[i]<< " ";
		cout<<endl;
		*/
		sort(arr,arr+n);
		/*
		rep(i,n) cout<<arr[i]<< " ";
		cout<<endl;
*/
		rep(i,n-1)
		{
			if(arr[i+1]-arr[i] <min)
			{
				//i1=i;
				//i2=i+1;
				min=arr[i+1]-arr[i];
			}
		}
		cout << min <<endl;
	}
return 0;
}



	//return 0;
//}//

