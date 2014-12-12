#line 2 "WakingUp.cpp"

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


class WakingUp {
int gcd(int a,int b){
	if(a<b)
		return gcd(b,a);
	while(b!=0){
		int t = a%b;
		a=b;
		b=t;
	}
	return a;
}

public:
int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
	int sleep=0;
	int mn = 0;
	int lcm=period[0];
	int n = period.size();
	for(int i=1;i<n;i++)
	{
		lcm *= (period[i]/gcd(lcm,period[i]));
	}
	//found the large cycle
	for(int i=1;i<=lcm;i++){
		sleep +=D;
		for(int j=0;j<n;j++){
			if(i%period[j] == start[j]%period[j])
				sleep-=volume[j];
		}
		mn = min(mn,sleep);
	}
	return (sleep<0?-1:-mn);
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
// 
int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing WakingUp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415127579;
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
		WakingUp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int period[] = {2, 3};
				int start[] = {1, 2};
				int volume[] = {3, 4};
				int D = 3;
				_expected = 2;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 1:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {17};
				int D = 17;
				_expected = 0;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 2:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {23};
				int D = 17;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 3:
			{
				int period[] = {9, 2, 5, 5, 7};
				int start[] = {6, 1, 4, 1, 6};
				int volume[] = {71, 66, 7, 34, 6};
				int D = 50;
				_expected = 78;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 4:
			{
				int period[] = {5, 6, 5, 3, 8, 3, 4};
				int start[] = {1, 1, 3, 2, 6, 3, 3};
				int volume[] = {42, 85, 10, 86, 21, 78, 38};
				int D = 88;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			/*case 5:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 6:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 7:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
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
