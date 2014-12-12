#line 2 "LittleElephantAndString.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class LittleElephantAndString {
public:
int getNumber(string B, string A) {
	int ans=A.size();
	int charSet[256];
	memset(charSet,0,sizeof charSet);
	for(int i=0;i<A.size();i++)
		charSet[A[i]]++;
	for(int i=0;i<B.size();i++)
		charSet[B[i]]--;
	for(int i=0;i<256;i++)
		if(charSet[i]!=0)
			return -1;
	// strings are equal
		int start;
	for(int i=0;i<=ans;i++){
		//we will shift these many digits.
		start=i;
		for(int j=0;j<B.size();j++)
			if(B[j] == A[start])
				start++;
		if(start==A.size())
			return i;
	}


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
		cout << "Testing LittleElephantAndString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415340768;
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
		LittleElephantAndString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "ABC";
				string B = "CBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			case 1:
			{
				string A = "A";
				string B = "B";
				_expected = -1;
				_received = _obj.getNumber(A, B); break;
			}
			case 2:
			{
				string A = "AAABBB";
				string B = "BBBAAA";
				_expected = 3;
				_received = _obj.getNumber(A, B); break;
			}
			case 3:
			{
				string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string B = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
				_expected = 25;
				_received = _obj.getNumber(A, B); break;
			}
			case 4:
			{
				string A = "A";
				string B = "A";
				_expected = 0;
				_received = _obj.getNumber(A, B); break;
			}
			case 5:
			{
				string A = "DCABA";
				string B = "DACBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 8:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
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
