#line 2 "DungeonEscape.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007
// class compare{
// public:
//  bool operator()(pair<int, pair<int,int> >  a,pair<int, pair<int,int> > b){
// 	return(a.first<b.first || (a.first==b.first && a.second.first<b.second.first)
// 		|| (a.first==b.first && a.second.first==b.second.first && a.second.second < b.second.second));
// }
// };

class DungeonEscape {
public:
int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) {
	int n = up.size();
	int m = up[0].size();
	int drown[n+1];
	memset(drown,0,sizeof drown);
	for(int i=n-1;i>=0;i--){
		drown[i] = drown[i+1]+m;
	}
	int vis[n][m];
	memset(vis,0,sizeof vis);
	pair<int,pair<int,int> > cur;
	priority_queue< pair<int, pair<int,int> >,vector<pair<int, pair<int,int> > > ,std::greater<pair<int,pair<int,int> > > > q;
	int cst,xind,yind;
	q.push(make_pair(0,make_pair(startLevel,startEasting)));
	// int cst;
	while(!q.empty()){
		cur = q.top();
		q.pop();
		// cout<<"dorwn " << drown[cur.second.first]<<" "<<cur.first<<" "<<cur.second.first<<" "<<cur.second.second<<endl;
		if(cur.second.first < 0)//above surface
			return cur.first;
		if(cur.first >= drown[cur.second.first])
			continue;
		xind = cur.second.first;
		yind = cur.second.second;
		if(vis[xind][yind] == 1)
			continue;
		vis[xind][yind]=1;
		{
				if(up[xind][yind]!='x'){
					cst=cur.first+(up[xind][yind]-'0');
					if(xind ==0 || cst < drown[xind-1])
						q.push(make_pair(cst,make_pair(xind-1,yind)));
				}
		}
		if(xind+1<n )
			{
				if(down[xind][yind]!='x'){
				cst = cur.first+(down[xind][yind]-'0');
				if(cst < drown[xind+1])
					q.push(make_pair(cst ,make_pair(xind+1,yind)));
			}	
		}
		if(yind+1 < m )
		{
			if(east[xind][yind] !='x'){
			cst = cur.first+(east[xind][yind]-'0');
			if(cst<drown[xind])
			q.push(make_pair(cst,make_pair(xind,yind+1)));
			}		
		}	
		if(yind-1 >=0){
			if(west[xind][yind] =='x'){}
			else{
				cst = cur.first+(west[xind][yind]-'0');
				if(cst< drown[xind])
					q.push(make_pair(cst,make_pair(xind,yind-1)));
			}
		}
	}

	return -1;


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
		cout << "Testing DungeonEscape (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415944983;
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
		DungeonEscape _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string up[] = {"0x4",
				               "0x3",
				               "0x3"};
				string down[] = {"0x9",
				                 "009",
				                 "0x9"};
				string east[] = {"0x9",
				                 "1x9",
				                 "009"};
				string west[] = {"0x9",
				                 "0x0",
				                 "009"};
				int startLevel = 2;
				int startEasting = 2;
				_expected = 10;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}
			case 1:
			{
				string up[] = {"xxxxxxxxx1",
				               "1xxxxxxxxx",
				               "xxxxxxxxx1"};
				string down[] = {"xxxxxxxxxx",
				                 "xxxxxxxxxx",
				                 "xxxxxxxxxx"};
				string east[] = {"1111111111",
				                 "xxxxxxxxxx",
				                 "1111111111"};
				string west[] = {"xxxxxxxxxx",
				                 "1111111111",
				                 "xxxxxxxxxx"};
				int startLevel = 2;
				int startEasting = 0;
				_expected = 30;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}
			case 2:
			{
				string up[] = {"xxxxxxxxx1",
				               "xxxx999991",
				               "x999999991"};
				string down[] = {"1111111111",
				                 "1111111111",
				                 "1111111111"};
				string east[] = {"1111122242",
				                 "2222222241",
				                 "2111111111"};
				string west[] = {"xxxxxxxxx1",
				                 "1111111111",
				                 "xxxxxxxxx1"};
				int startLevel = 2;
				int startEasting = 0;
				_expected = -1;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}
			case 3:
			{
				string up[] = {"1x2x3x4x5x6x7x8x9",
				               "00000000000000000",
				               "98765432223456789",
				               "12345678987654321"};
				string down[] = {"00000000000000000",
				                 "00000000000000000",
				                 "00000000000000000",
				                 "00000000000000000"};
				string east[] = {"xxxxxxxxxxxxxxxxx",
				                 "xxxxxxxxxxxxxxxxx",
				                 "22222222222222222",
				                 "33333333333333333"};
				string west[] = {"xxxxxxxxxxxxxxxxx",
				                 "xxxxxxxxxxxxxxxxx",
				                 "22222222222222222",
				                 "33333333333333333"};
				int startLevel = 3;
				int startEasting = 12;
				_expected = 17;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}
			/*case 4:
			{
				string up[] = ;
				string down[] = ;
				string east[] = ;
				string west[] = ;
				int startLevel = ;
				int startEasting = ;
				_expected = ;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}*/
			/*case 5:
			{
				string up[] = ;
				string down[] = ;
				string east[] = ;
				string west[] = ;
				int startLevel = ;
				int startEasting = ;
				_expected = ;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
			}*/
			/*case 6:
			{
				string up[] = ;
				string down[] = ;
				string east[] = ;
				string west[] = ;
				int startLevel = ;
				int startEasting = ;
				_expected = ;
				_received = _obj.exitTime(vector <string>(up, up+sizeof(up)/sizeof(string)), vector <string>(down, down+sizeof(down)/sizeof(string)), vector <string>(east, east+sizeof(east)/sizeof(string)), vector <string>(west, west+sizeof(west)/sizeof(string)), startLevel, startEasting); break;
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
