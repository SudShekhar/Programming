#line 2 "MinimumSquare.cpp"

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


class MinimumSquare {
	bool check(long long l,vector<long long> &x,vector<long long>&y,int K){
		int n=x.size();
		// cout<<l<<endl;
		// cout<<"Check "<<n<<endl;
		long long val,lowX,lowY;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				lowX = x[i]-l+1;
				val=0;
				lowY = y[j]-l+1;
				for(int k=0;k<n;k++)
				{
					if(x[k] > lowX && x[k] < lowX+l && y[k] > lowY && y[k] < lowY+l)
						val++;
				}
				if(val>=K)
					{
						// cout<<"Correct for "<<l<<endl;
						return true;
					}
			}
		}
		// cout<<"False for "<<l<<endl;
		return false;
	}
public:
long long minArea(vector <int> x, vector <int> y, int K) {
	int n = x.size();
	vector<long long> xarr(n),yarr(n);
	for(int i=0;i<n;i++){
		xarr[i] = x[i];
		yarr[i]=y[i];
	}
	// v has pairs for each number.
	long long l=1;
	long long r;
	r= 2100000000;
	// cout<<"sizeof long "<<sizeof(r)<<endl;
	long long m;
	while(l<=r){
		m = l+(r-l)/2;
		if(check(m,xarr,yarr,K)) 
			if(!check(m-1,xarr,yarr,K))
				return (m*m);
			else r=m-1;
		else l=m+1; 
	}
}
};

// BEGIN CUT HERE
// #include <ctime>
// #include <cmath>
// #include <string>
// #include <vector>
#include <sstream>
// #include <iostream>
// #include <algorithm>
// using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing MinimumSquare (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415135121;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MinimumSquare _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 3};
				int y[] = {0, 7};
				int K = 2;
				_expected = 81LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 1:
			{
				int x[] = {-4, 3, 1};
				int y[] = {3 , -1, -2};
				int K = 2;
				_expected = 16LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 2:
			{
				int x[] = {0, 0, 1, 1, 2, 2};
				int y[] = {0, 1, 0, 1, 0, 1};
				int K = 4;
				_expected = 9LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 3:
			{
				int x[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
				int y[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
				int K = 3;
				_expected = 4000000008000000004LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 4:
			{
				int x[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
				int y[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
				int K = 8;
				_expected = 1695545329LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// int main(){
// 	int x[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
// 	int y[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
// 	int K = 8;
// 	MinimumSquare a;
// 	vector<int> xarr(x,x+(sizeof(x)/sizeof(x[0])));
// 	vector<int> yarr(y,y+(sizeof(y)/sizeof(y[0])));
// 	cout<<a.minArea(xarr,yarr,8);
// }
// END CUT HERE
