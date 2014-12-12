#line 2 "PipeCuts.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class PipeCuts {
public:
double probability(vector <int> weldLocations, int L) {
	int n= weldLocations.size();
	// if(L!=25)
	// 	return 0;
	sort(weldLocations.begin(),weldLocations.end());
	double sz=0,cor=0;
	int len1,len2;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			// len0 = pre[i];
			sz++;
			len1 = weldLocations[j] - weldLocations[i];
			len2 = 100 - weldLocations[j];
			if(len1 >L || len2>L || weldLocations[i] > L)
				cor++;
			// else cout<<len1<<" "<<len2<<" "<<weldLocations[i]<<" "<<L<<endl;
		}
	}
	return (cor/sz);
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
		cout << "Testing PipeCuts (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415685705;
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
		PipeCuts _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weldLocations[] = {25, 50, 75};
				int L = 25;
				_expected = 1.0;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}
			case 1:
			{
				int weldLocations[] = {25, 50, 75};
				int L = 50;
				_expected = 0.0;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}
			case 2:
			{
				int weldLocations[] = {25, 50, 75};
				int L = 24;
				_expected = 1.0;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}
			case 3:
			{
				int weldLocations[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
				int L = 50;
				_expected = 0.7222222222222222;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}
			/*case 4:
			{
				int weldLocations[] = ;
				int L = ;
				_expected = ;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}*/
			/*case 5:
			{
				int weldLocations[] = ;
				int L = ;
				_expected = ;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}*/
			/*case 6:
			{
				int weldLocations[] = ;
				int L = ;
				_expected = ;
				_received = _obj.probability(vector <int>(weldLocations, weldLocations+sizeof(weldLocations)/sizeof(int)), L); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
