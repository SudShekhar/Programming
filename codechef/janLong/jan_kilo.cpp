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
		float angle;
		float d;
		int quad;
		//ensuring sorting acc to clockwise + lengthwise
        bool operator <(const Point &p) const {
           //     return x < p.x || (x == p.x && y < p.y);
             
             return quad< p.quad || (quad==p.quad && angle>p.angle) || (quad==p.quad && angle==p.angle && d<p.d);  
                
        }
};
Point origin;
float dist( const Point &O,const Point &A)
{
	return (O.x-A.x)*(O.x-A.x) + (O.y-A.y)*(O.y-A.y);
}

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main()
{
	int re,v,n,i,j,a,b,c;
	float base=0,height=0;
	cin>>n;
	vector<Point> arr(n);
	for(i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y>>c;
		base+=arr[i].x;
		height+=arr[i].y;
	}
	base/=n;
	height/=n;
	origin.x=base;
	origin.y=height;
	
	vector<Point> ar(n);
	//translation done to pseudo-center
	for(i=0;i<n;i++)
	{
		ar[i].x=arr[i].x-origin.x;
		ar[i].y=arr[i].y-origin.y;
		if(ar[i].x!=0)
		{
			ar[i].angle = abs(ar[i].y/ar[i].x);
		
			if(ar[i].x>0)
			{
				if(ar[i].y>=0)ar[i].quad=1;
				else ar[i].quad=2;
			}
			else if(ar[i].x<0){
				if(ar[i].y>=0)ar[i].quad=4;
				else ar[i].quad=3;
			}
		}
		else {
			ar[i].angle=90;
			ar[i].quad=1;
		}
	}
	
	//need to sort them now along the clockwise direction
	//one way is to take cross product with another point such as (0,1) ans divide by the length of the dist bw pnt and center
	Point end;
	end.x=origin.x;
	end.y=origin.y+1;
	
	/*//cout<<origin.x<<" ,"<<origin.y<<endl;
	for(i=0;i<n;i++)
	{
		if(ar[i].x==0)
		{

			ar[i].angle=90;
			ar[i].quad=ar[i].y>=0?1:4;
		
		}
		else
		{
			ar[i].angle=abs(ar[i].y/ar[i].x);//initialising the distance and angle of each point
		if(ar[i].y>=0 && ar[i].x>0) ar[i].quad=1;
		if(ar[i].y<0 && ar[i].x<0) ar[i].quad=3;
		if(ar[i].y>=0 && ar[i].x<0)ar[i].quad=4;
		if(ar[i].y<0 && ar[i].x>0) ar[i].quad=2;
		}
		ar[i].d=dist(origin,ar[i]);
		
	}
	
	//for(i=0;i<n;i++)
	{//printing out re-translated vertices;
	//if(i<n-2 && ar[i+2].angle-ar[i].angle == ar[i+1].angle-ar[i].angle && dist(ar[i],ar[i+1])>dist(ar[i],ar[i+2])){
		//Point t=ar[i+1];
		//ar[i+1]=ar[i+2];
		//ar[i+2]=t;
	}
		*/
	sort(all(ar));
	cout<<n<<endl;
	
	for(i=0;i<n;i++)
	{	
		cout<<ar[i].x+ origin.x<<" "<<ar[i].y +  origin.y<<" angle= "<<ar[i].angle<<"quad = "<<ar[i].quad<< endl;
	}
	
return 0;
}

