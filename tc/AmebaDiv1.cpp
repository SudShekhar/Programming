#line 2 "AmebaDiv1.cpp"

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


class AmebaDiv1 {
public:
int count(vector <int> X) {
	int ans;
	int n = X.size();
	// vector<int> cpy(X.begin(),X.end());
	map<int,int> m;
	for(int i=0;i<n;i++){
		//choosing i as a candidate
		int start=X[i];
		for(int j=0;j<n;j++){
			if(start == X[j])
				start+=X[j];
		}
		m[start]=1;//this state can be reached
	}

	ans=0;
	for(int i=0;i<n;i++){
		if(m[X[i]] != 1){
			ans++;
			m[X[i]]=1;
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
		cout << "Testing AmebaDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415133389;
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
		AmebaDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {3,2,1};
				_expected = 2;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}
			case 1:
			{
				int X[] = {2,2,2,2,2,2,4,2,2,2};
				_expected = 2;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}
			case 2:
			{
				int X[] = {1,2,4,8,16,32,64,128,256,1024,2048};
				_expected = 11;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}
			case 3:
			{
				int X[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
				_expected = 7;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}
			/*case 4:
			{
				int X[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int X[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int X[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(X, X+sizeof(X)/sizeof(int))); break;
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
