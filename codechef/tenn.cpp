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
#define ALL(x) x.begine(),x.end()
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
	//char arr[100000];
	int i,j,k,n,m;
	vector<char> arr;
	int re,v;

	SI(re);int len;

	rep(v,re){
		SI(len);
		arr.resize(len);
		//arr.clear();
		rep(i,len){
		//	scanf("%c",&arr[i]);
		cin >> arr[i];
		}
		scanf("%*c");
		/*rep(i,len){
			printf("%c",arr[i]);
		}*/
		int a1=0,a2=0;
		int c1,c2;
		c1=0;c2=0;
		rep(i,len){
			if(arr[i]=='C')c1++;
			if(arr[i]=='S')c2++;

			if(c1==4 ) {
				a1++;
				c1=0;
				c2=0;
			}
			else if (c2==4){
				a2++;
				c2=0;
				c1=0;
			}
		}

		cout<<a2<<"-"<<a1;
		if(!(c1==0) || !(c2==0)){
			c1= c1==3?40:c1*15;
		
			c2= c2==3?40:c2*15;
			
			
			cout<<","<<c2<<"-"<<c1;
		}
		cout<<endl;


	}

	return 0;
}

