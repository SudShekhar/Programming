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



#define min(a,b) a<b?a:b
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
{
	vec arr;
	int i,j,k,n,m,l,re,v;
	SI(n);
	pair<vector<int>::iterator,vector<int>::iterator> bound;
	rep(i,n){
		SI(m);
		arr.pb(m);
	}
	sort(all(arr));
	vec::iterator low;
	int count=0,ind;
	rep(i,n) cout<<arr[i]<<" ";
	cout<<endl;
	rep(i,n)
	{
//		vec v2(arr);
//		v2.pop(i);
		f(j,i+1,n)
		{	//v2.pop(j);
			if((-arr[i] + arr[j]*2)  >arr[n-1]){
				break;
			
			}
			else {
			//	bound=equal_range((vec::iterator)(&arr[0]),arr.end(),(arr[i]+arr[j])/2);
				bound=equal_range((vec::iterator)(&arr[j+1]),arr.end(),(-arr[i]+arr[j]*2));
				ind=(int)(bound.second - bound.first);
			//	cout <<"gt "<< (*low) << "for " << arr[i]<<" and" << arr[j] << endl;
				/*if( ind<=j)continue;
				else if(arr[i]+arr[j] == 2*arr[ind]) 
				{*/
					for(vec::iterator b = bound.first;b!=bound.second;b++)
						cout<<*b<<endl;

					count+=ind;
					cout <<arr[i]<<"-"<<ind<<"-"<<arr[j]<<endl;
			//	}				
			}
				
		}
	}
	cout <<count<<endl;
	
	return 0;
}

