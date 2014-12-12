#line 2 "PathFinding.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class PathFinding {
bool inbound(pair<int,int> n,vector<string> &board){
	return (n.first >=0 && n.first < board.size() &&
		n.second >=0 && n.second<board[0].size() && board[n.first][n.second]!='X');
}

public:
int minTurns(vector <string> board) {
	queue<pair< pair<int,int>, pair<int,int> > > q;
	int ax,ay,bx,by;
	int n = board.size();
	int m1 = board[0].size();
	rep(i,n)
		rep(j,m1)
			if(board[i][j]=='A')
				ax=i,ay=j;
			else if(board[i][j]=='B')
				bx=i,by=j;
	q.push(make_pair(make_pair(ax,ay),make_pair(bx,by)));
	int dx[] = {-1,-1,-1,0,0,1,1,1,0};
	int dy[] = {-1,0,1,1,-1,-1,0,1,0};
	pair< pair<int,int>,pair<int,int> > cur,op;
	queue<int> q1;
	q1.push(0);
	int step;
	pair<int,int> xstep,ystep,apoint,bpoint;
	apoint = make_pair(ax,ay);
	bpoint = make_pair(bx,by);
	// cout<<apoint.first<<" "<<apoint.second<<" "<<bpoint.first<<" "<<bpoint.second<<endl;
	map<pair<pair<int,int>, pair<int,int> >,int> m;
	while(!q.empty()){
		cur = q.front();
		step = q1.front();
		m[cur]=1;
		// cout<<cur.first.first<<" "<<cur.first.second<<" && "<<cur.second.first<<" "<<cur.second.second<<endl;
		// cout<<step<<endl;
		q.pop();
		q1.pop();
		if(cur.first == bpoint && cur.second == apoint)
			return step;
		for(int i=0;i<9;i++){
			xstep = make_pair(cur.first.first+dx[i],cur.first.second+dy[i]);
			for(int j=0;j<9;j++){
				if(i==8 && j==8)continue;
				ystep = make_pair(cur.second.first+dx[j],cur.second.second+dy[j]);
				op = make_pair(xstep,ystep);
				if(inbound(xstep,board) && inbound(ystep,board)&&
				!(xstep == cur.second && ystep==cur.first)&&(xstep!=ystep) && m[op]==0)
					m[op]=1,q.push(op),q1.push(step+1);
			}
		}
	}		
	return -1;		

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
		cout << "Testing PathFinding (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415913235;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PathFinding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"....",
				                  ".A..",
				                  "..B.",
				                  "...."};
				_expected = 2;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"XXXXXXXXX",
				                  "A...X...B",
				                  "XXXXXXXXX"};
				_expected = -1;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"XXXXXXXXX",
				                  "A.......B",
				                  "XXXXXXXXX"};
				_expected = -1;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"XXXXXXXXX",
				                  "A.......B",
				                  "XXXX.XXXX"};
				_expected = 8;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"...A.XXXXX.....",
				                  ".....XXXXX.....",
				                  "...............",
				                  ".....XXXXX.B...",
				                  ".....XXXXX....."};
				_expected = 13;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"AB.................X",
				                  "XXXXXXXXXXXXXXXXXXX.",
				                  "X..................X",
				                  ".XXXXXXXXXXXXXXXXXXX",
				                  "X..................X",
				                  "XXXXXXXXXXXXXXXXXXX.",
				                  "X..................X",
				                  ".XXXXXXXXXXXXXXXXXXX",
				                  "X..................X",
				                  "XXXXXXXXXXXXXXXXXXX.",
				                  "X..................X",
				                  ".XXXXXXXXXXXXXXXXXXX",
				                  "X..................X",
				                  "XXXXXXXXXXXXXXXXXXX.",
				                  "X..................X",
				                  ".XXXXXXXXXXXXXXXXXXX",
				                  "X..................X",
				                  "XXXXXXXXXXXXXXXXXXX.",
				                  "...................X",
				                  ".XXXXXXXXXXXXXXXXXXX"};
				_expected = 379;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTurns(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
