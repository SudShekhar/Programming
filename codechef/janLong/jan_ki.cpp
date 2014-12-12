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

typedef float coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2


struct Point {
        coord_t x, y;
        int nat;
		/*float angle;
		float d;
		int quad;
		//ensuring sorting acc to clockwise + lengthwise
        */
        
        bool operator <(const Point &p) const {
           //     return x < p.x || (x == p.x && y < p.y);
             
             return x<p.x || (x==p.x && y<p.y);  
                
        }
};
Point origin;
float dist( const Point &O,const Point &A)
{
	return (O.x-A.x)*(O.x-A.x) + (O.y-A.y)*(O.y-A.y);
}

bool func(Point q,Point p){ return q.y<p.y || (q.y==p.y && q.x<p.x);  }
int main()
{
	int re,v,n,i,j,a,b,c;
	float base=1005,height=-1000,hd=-1000;
	cin>>n;
	vector<Point> arr(n);
	for(i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y>>arr[i].nat;
		if(arr[i].x<base)base=arr[i].x;
		if(arr[i].nat==1000 && arr[i].y>height)height=arr[i].y;
		if(arr[i].nat==1024 && arr[i].y > hd) hd = arr[i].y;
	}
	
	sort(all(arr));
	
	
	int k=0;
	int c1=0,c2=0;
	//find numbers same from begining
	while(arr[k].nat==arr[k+1].nat){
		k++;
		c1++;
	}
	int len=n-1;
	//find number same from end
	while(len>=0 && arr[len-1].nat==arr[len].nat){
		len--;
		c2++;
	}
	int flag=0;
	
	if(arr[0].nat==arr[n-1].nat)c1+=c2;
	else if(c2>c1){
		flag=1;
		c1=c2;
	}
	if(!flag){
		k=0;
	while(arr[k].nat==arr[k+1].nat){
		k++;
	}
	while(arr[n-1].nat==arr[0].nat)n--;
	if(arr[0].nat==1024)height=hd;
	}	
	
	else{
		while(arr[n-1].nat==arr[n-2].nat)n--;
		k=0;
		while(arr[k].nat==arr[n-1].nat)k++;
		if(arr[n-1].nat==1024)height=hd;
	}
	c=0,v=0;
	//error region
	
	//proper stuff
	cout<<n-c1+2<<endl;
	for(i=k;i<n;i++)
	{	
		if(arr[i].nat!=0)
		cout<<arr[i].x<<" "<<arr[i].y<<endl;
	}
	cout<<arr[n-1].x<<" "<<height+1<<endl;
	cout<<base-1<<" " <<height+1<<endl;
	
	
return 0;
}

