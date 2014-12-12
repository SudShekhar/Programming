#line 2 "StripePainter.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class StripePainter {
int dp[52][52][28];
int solve(string &stripes,int l,int r,int color){
	if(l>r)
		return 0;
	if(dp[l][r][color] != -1)
		return dp[l][r][color];
	if(stripes[l] == color)return dp[l][r][color] = solve(stripes,l+1,r,color);
	if(stripes[r] == color) return dp[l][r][color] = solve(stripes,l,r-1,color);

	int val = 987654321;
	for(int i=l;i<=r;i++){
		val = min(val,(1+solve(stripes,l,i,stripes[l])+solve(stripes,i+1,r,color)));
	}
	return dp[l][r][color]=val;
}
public:
int minStrokes(string stripes) {
	
	rep(i,52)
		rep(j,52)
			rep(k,28)
				dp[i][j][k]=-1;

	int n = stripes.size();
	return solve(stripes,0,n-1,27);
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
		cout << "Testing StripePainter (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415470876;
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
		StripePainter _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string stripes = "RGBGR";
				_expected = 3;
				_received = _obj.minStrokes(stripes); break;
			}
			case 1:
			{
				string stripes = "RGRG";
				_expected = 3;
				_received = _obj.minStrokes(stripes); break;
			}
			case 2:
			{
				string stripes = "ABACADA";
				_expected = 4;
				_received = _obj.minStrokes(stripes); break;
			}
			case 3:
			{
				string stripes = "AABBCCDDCCBBAABBCCDD";
				_expected = 7;
				_received = _obj.minStrokes(stripes); break;
			}
			case 4:
			{
				string stripes = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD";
				_expected = 26;
				_received = _obj.minStrokes(stripes); break;
			}
			/*case 5:
			{
				string stripes = ;
				_expected = ;
				_received = _obj.minStrokes(stripes); break;
			}*/
			/*case 6:
			{
				string stripes = ;
				_expected = ;
				_received = _obj.minStrokes(stripes); break;
			}*/
			/*case 7:
			{
				string stripes = ;
				_expected = ;
				_received = _obj.minStrokes(stripes); break;
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
// 	string stripes = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD";
// 	int expected = 26;
// 	StripePainter a;
// 	cout<<a.minStrokes(stripes)<<endl;
// }

// END CUT HERE
