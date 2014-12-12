#line 2 "QuizShow.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class QuizShow {
public:
int wager(vector <int> scores, int wager1, int wager2) {// int n = scores.size();
	int my = scores[0];
	int op1 = scores[1];
	int op2 = scores[2];
	int cor,best,bet;
	best=-1;
	bet=-1;
	int t1,t2,t3;
	// int arr[] = {-1,}
	for(int i=0;i<=my;i++){
		cor=0;
		for(int I=-1;I<=1;I+=2)
			for(int J=-1;J<=1;J+=2)
				for(int j=-1;j<=1;j+=2){
					t1 = my+j*i;
					t2 = op1 + I*wager1;
					t3 = op2 + J*wager2;
					if(t1 > t2 && t1 > t3)
						cor++;
				}
		if(cor>best)
			bet=i,best=cor;		
	}

	return bet;
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
		cout << "Testing QuizShow (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415686471;
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
		QuizShow _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = { 100, 100, 100 };
				int wager1 = 25;
				int wager2 = 75;
				_expected = 76;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 1:
			{
				int scores[] = { 10, 50, 60 };
				int wager1 = 30;
				int wager2 = 41;
				_expected = 0;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 2:
			{
				int scores[] = { 10, 50, 60 };
				int wager1 = 31;
				int wager2 = 41;
				_expected = 10;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 3:
			{
				int scores[] = { 2, 2, 12 };
				int wager1 = 0;
				int wager2 = 10;
				_expected = 1;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 4:
			{
				int scores[] = { 10000, 10000, 10000 };
				int wager1 = 9998;
				int wager2 = 9997;
				_expected = 9999;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 5:
			{
				int scores[] = { 5824, 4952, 6230 };
				int wager1 = 364;
				int wager2 = 287;
				_expected = 694;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			/*case 6:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}*/
			/*case 7:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}*/
			/*case 8:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
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
