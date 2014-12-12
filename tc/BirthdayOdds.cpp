#line 2 "BirthdayOdds.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class BirthdayOdds {
public:
int minPeople(int minOdds, int daysInYear) {
	int reqPercent = 100-minOdds;
	if(daysInYear==1)
		return 2;
	double total = daysInYear;
	double ans=100;
	for(int i=0;i<daysInYear;i++){
		ans*= (total-i)/total;
		if(ans<=reqPercent)
			return i+1;
	}
	return daysInYear+1;
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
		cout << "Testing BirthdayOdds (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415442272;
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
		BirthdayOdds _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minOdds = 99;
				int daysInYear = 1;
				_expected = 2;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}
			case 1:
			{
				int minOdds = 99;
				int daysInYear = 2;
				_expected = 3;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}
			case 2:
			{
				int minOdds = 1;
				int daysInYear = 365;
				_expected = 4;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}
			case 3:
			{
				int minOdds = 84;
				int daysInYear = 9227;
				_expected = 184;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}
			/*case 4:
			{
				int minOdds = ;
				int daysInYear = ;
				_expected = ;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}*/
			/*case 5:
			{
				int minOdds = ;
				int daysInYear = ;
				_expected = ;
				_received = _obj.minPeople(minOdds, daysInYear); break;
			}*/
			/*case 6:
			{
				int minOdds = ;
				int daysInYear = ;
				_expected = ;
				_received = _obj.minPeople(minOdds, daysInYear); break;
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
