#line 2 "ChessMetric.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
class ChessMetric {
public:
long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
	long long dp[size][size][numMoves+1];
	//0 se size-1 on each side;
	int dx[] = {-1,-1,-1,0,0,1,1,1,-2,-2,2,2,1,-1,1,-1};
	int dy[] = {-1,0,1,-1,1,-1,0,1,1,-1,1,-1,2,2,-2,-2};
	// int ddx[] = {};
	memset(dp,0,sizeof dp);
	// int ddy[] = {};
	int nx,ny;
	dp[start[0]][start[1]][0]=1;
	for(int i=1;i<=numMoves;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){	
				for(int l=0;l<16;l++){
					nx = j+dy[l];
					ny = k +dx[l];
					if(nx>=0 && nx<size && ny>=0 && ny<size)
						dp[j][k][i]+=dp[nx][ny][i-1];
				}
			}
		}
	}
	return dp[end[0]][end[1]][numMoves];
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
		cout << "Testing ChessMetric (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415468845;
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
		ChessMetric _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int size = 3;
				int start[] = {0,0};
				int end[] = {1,0};
				int numMoves = 1;
				_expected = 1LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}
			case 1:
			{
				int size = 3;
				int start[] = {0,0};
				int end[] = {1,2};
				int numMoves = 1;
				_expected = 1LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}
			case 2:
			{
				int size = 3;
				int start[] = {0,0};
				int end[] = {2,2};
				int numMoves = 1;
				_expected = 0LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}
			case 3:
			{
				int size = 3;
				int start[] = {0,0};
				int end[] = {0,0};
				int numMoves = 2;
				_expected = 5LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}
			case 4:
			{
				int size = 100;
				int start[] = {0,0};
				int end[] = {0,99};
				int numMoves = 50;
				_expected = 243097320072600LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}
			/*case 5:
			{
				int size = ;
				int start[] = ;
				int end[] = ;
				int numMoves = ;
				_expected = LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}*/
			/*case 6:
			{
				int size = ;
				int start[] = ;
				int end[] = ;
				int numMoves = ;
				_expected = LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
			}*/
			/*case 7:
			{
				int size = ;
				int start[] = ;
				int end[] = ;
				int numMoves = ;
				_expected = LL;
				_received = _obj.howMany(size, vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(end, end+sizeof(end)/sizeof(int)), numMoves); break;
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
