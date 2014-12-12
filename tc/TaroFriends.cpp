#line 2 "TaroFriends.cpp"

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


class TaroFriends {
public:
int getNumber(vector <int> coordinates, int X) {
	// sort(coordinates.begin(),coordinates.end());
	int n = coordinates.size();
	vector<pair<int,int> > options;
	for(int i=0;i<n;i++)
	{
		options.push_back(make_pair(coordinates[i]-X,i));
		options.push_back(make_pair(coordinates[i]+X,i));		
	}
	sort(options.begin(),options.end());
	int flen=0;
	int fnd[n];
	memset(fnd,0,sizeof fnd);
	
	int N = options.size();
	int start=0;
	int ans= (1<<30);
	for(int i=0;i<N;i++){
		if(fnd[options[i].second] == 0)
			flen++;
		fnd[options[i].second]++;
		if(flen >= n){
			while(fnd[(options[start].second)] > 1)
				fnd[options[start].second]--,start++;
			//found a crucial node;
			ans = min(ans,(abs(options[i].first - options[start].first)));
		}
	}
	return ans;

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
		cout << "Testing TaroFriends (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415168391;
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
		TaroFriends _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int coordinates[] = {-7,-5,-2,1,6};
				int X = 4;
				_expected = 5;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 1:
			{
				int coordinates[] = {4, 7, -7};
				int X = 5;
				_expected = 4;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 2:
			{
				int coordinates[] = {-100000000, 100000000};
				int X = 100000000;
				_expected = 0;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 3:
			{
				int coordinates[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
				int X = 7;
				_expected = 7;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 4:
			{
				int coordinates[] = {-4, 0, 4, 0};
				int X = 4;
				_expected = 4;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 5:
			{
				int coordinates[] = {7};
				int X = 0;
				_expected = 0;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			/*case 6:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
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
