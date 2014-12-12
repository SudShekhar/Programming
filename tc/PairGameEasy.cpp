#line 2 "PairGameEasy.cpp"

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


class PairGameEasy {
public:
string able(int a, int b, int c, int d) {
	pair<int,int> cur = make_pair(a,b);
	queue<pair<int,int> > q;
	q.push(cur);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.first == c && cur.second==d)
			return "Able to generate";
		if(cur.first+cur.second <=c && cur.second<=d)
			q.push(make_pair(cur.first+cur.second,cur.second));
		if(cur.first<=c && cur.first+ cur.second <= d)
			q.push(make_pair(cur.first,cur.first+cur.second));
	}
	return "Not able to generate";
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
		cout << "Testing PairGameEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415287570;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PairGameEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 1;
				int c = 1000;
				int d = 1000;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 1:
			{
				int a = 1;
				int b = 2;
				int c = 2;
				int d = 1;
				_expected = "Not able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 2:
			{
				int a = 2;
				int b = 2;
				int c = 2;
				int d = 999;
				_expected = "Not able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 3:
			{
				int a = 2;
				int b = 2;
				int c = 2;
				int d = 1000;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 4:
			{
				int a = 47;
				int b = 58;
				int c = 384;
				int d = 221;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 5:
			{
				int a = 1000;
				int b = 1000;
				int c = 1000;
				int d = 1000;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
