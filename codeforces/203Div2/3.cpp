#include<iostream>
#include<vector>
#include<algorithm>

#define pb push_back

using namespace std;
typedef struct point{
	long long int x,y;
} Point;

vector<Point> A;

bool func(Point a,Point b)
{
	//return ((a.x*a.x + a.y*a.y)<=(b.x*b.x+b.y*b.y));
	return ((abs(a.x) + abs(a.y) ) < (abs(b.x) + abs(b.y)));
}
#define check(a) a==0?0:1


int main()
{
	int n;
	cin>>n;
	long long int step=0;
	for(int i=0;i<n;i++)
	{
		Point t;
		cin>>t.x>>t.y;
		step += 2*((check(t.x))+(check(t.y)))+2;
		A.pb(t);
		
	}
	sort(A.begin(),A.end(),func);
/*	for(int i=0;i<n;i++)
		cout<<A[i].x<<' '<<A[i].y<<"\n";*/
	
	//for(int i=0;i<n;i++)
		
	cout<<step<<"\n";
	for(int i=0;i<n;i++)
	{
		char dir1,dir2,dir3,dir4;
		if(A[i].x>0)
		{
			dir1='R';
			dir3='L';
		}
		else
		{
			dir1='L';
			dir3='R';
		}
		if(A[i].y>0)
		{
			dir2='U';
			dir4='D';
		}
		else
		{
			dir2='D';
			dir4='U';
		}
		if(check(A[i].x))
			cout<<"1 "<<abs(A[i].x)<<' '<<dir1<<"\n";
		if(check(A[i].y))
			cout<<"1 "<<abs(A[i].y)<<' '<<dir2<<"\n";
		cout<<"2\n";
		if(check(A[i].y))
			cout<<"1 "<<abs(A[i].y)<<' '<<dir4<<"\n";
		if(check(A[i].x))
			cout<<"1 "<<abs(A[i].x)<<' '<<dir3<<"\n";
		
		cout<<"3\n";
	}
	return 0;
}
