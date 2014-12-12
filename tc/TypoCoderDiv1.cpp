#line 2 "TypoCoderDiv1.cpp"

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


class TypoCoderDiv1 {
public:
int getmax(vector <int> D, int X) {
}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing TypoCoderDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415252506;
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
		TypoCoderDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D[] = {100,200,100,1,1};
				int X = 2000;
				_expected = 3;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 1:
			{
				int D[] = {0,0,0,0,0};
				int X = 2199;
				_expected = 0;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 2:
			{
				int D[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
				int X = 0;
				_expected = 1;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 3:
			{
				int D[] = {1000000000,1000000000,10000,100000,2202,1};
				int X = 1000;
				_expected = 4;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 4:
			{
				int D[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
				int X = 2199;
				_expected = 0;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 5:
			{
				int D[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
				int X = 1223;
				_expected = 29;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			case 6:
			{
				int D[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
				int X = 1328;
				_expected = 20;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}
			/*case 7:
			{
				int D[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int D[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
			}*/
			/*case 9:
			{
				int D[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(D, D+sizeof(D)/sizeof(int)), X); break;
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

// END CUT HERE
