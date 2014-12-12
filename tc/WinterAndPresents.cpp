#line 2 "WinterAndPresents.cpp"

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


class WinterAndPresents {
	bool ok(vector<int> & apple,int req,int mx){
		for(int i=0;i<apple.size();i++){
			req -= min(mx,apple[i]);
			if(req<=0)
				return true;
		}
		return false;
	}
public:
// Expected Order : 50*10^6 -> 5*10^7
long long getNumber(vector <int> apple, vector <int> orange) {
	int tmin=(1<<30);
	long long amin=0,osum=0;
	int n = apple.size();
	for(int k=0;k<n;k++)
		tmin = min(apple[k]+orange[k],tmin);
	// now we can take tmin*n total fruits.
	// but we can only take total X apples, 
	long long ans=0;
	// long long limiter = min(omin,amin);
	for(int i=1;i<=tmin;i++){
		//we will take i fruits in this go; now we need to see how many apples we can take
	amin=0,osum=0;
	for(int k=0;k<n;k++){
		osum += min(i,orange[k]);
		amin += min(i,apple[k]);
	}	
	// now we have the maximum number of apples we can take, and the minimum number too
	ans+= amin - (i*n-osum)+1;
		// cout<<"When taking "<<i*n<<" fruites we can take between "<<required<<" "<<end<<" at "<<ans<<endl;
	}
	return ans;
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
		cout << "Testing WinterAndPresents (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415252557;
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
		WinterAndPresents _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int apple[] = {1};
				int orange[] = {1};
				_expected = 3LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 1:
			{
				int apple[] = {1, 2, 0, 3};
				int orange[] = {4, 5, 0, 6};
				_expected = 0LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 2:
			{
				int apple[] = {2, 2, 2};
				int orange[] = {2, 2, 2};
				_expected = 16LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 3:
			{
				int apple[] = {7, 4, 5};
				int orange[] = {1, 10, 2};
				_expected = 46LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 4:
			{
				int apple[] = {1000000};
				int orange[] = {1000000};
				_expected = 1000002000000LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			/*case 5:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
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
