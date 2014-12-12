#line 2 "AvoidRoads.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class AvoidRoads {
public:
long long numWays(int width, int height, vector <string> bad) {
	long long dp[width+1][height+1];
	map<pair<int, int> , set<pair<int,int> > > banned;
	int temp[4],ind;
	int start;
	int num;
	memset(dp,0,sizeof dp);
	for(int i=0;i<bad.size();i++){
		start=0;
		num=0;
		ind=0;
		for(int j=0;j<bad[i].size();j++){
			if(bad[i][j] == ' ') // start to j-1 is a number
			{
				num=0;
				while(start<j){
					num = num*10 + (bad[i][start]-'0');
					start++;
				}
				start++;
				temp[ind++]=num;
			
			}
		}
		num=0;
		while(start<bad[i].size()){
				num = num*10 + (bad[i][start]-'0');
				start++;
		}
		start++;
		temp[ind++]=num;
		// rep(i,ind)
		// 	cout<<temp[i]<<" ";
		// cout<<endl;
	banned[make_pair(temp[0],temp[1])].insert(make_pair(temp[2],temp[3]));
	banned[make_pair(temp[2],temp[3])].insert(make_pair(temp[0],temp[1]));
	}
	//now we have all banned elements
	dp[0][0]=1;
	pair<int,int> cur,prev;
	for(int i=1;i<=width;i++)
	{
		cur = make_pair(i,0);
		prev = make_pair(i-1,0);
		if(banned[cur].find(prev)!=banned[cur].end())
			dp[i][0]=0;
		else dp[i][0]=dp[i-1][0];
	}

	for(int i=1;i<=height;i++)
	{
		cur = make_pair(0,i);
		prev = make_pair(0,i-1);
		if(banned[cur].find(prev)!=banned[cur].end())
			dp[0][i]=0;
		else dp[0][i]=dp[0][i-1];
	}
	long long op1,op2;
	for(int i=1;i<=width;i++)
	{
		for(int j=1;j<=height;j++){
			cur=make_pair(i,j);
			prev = make_pair(i-1,j);
			// int op1,op2;
			if(banned[cur].find(prev)!=banned[cur].end())
				op1=0;
			else op1 = dp[i-1][j];
			prev = make_pair(i,j-1);
			if(banned[cur].find(prev)!=banned[cur].end())
				op2=0;
			else op2 = dp[i][j-1];
			dp[i][j]=op1+op2;

		}
	}
	return dp[width][height];
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
		cout << "Testing AvoidRoads (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415466545;
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
		AvoidRoads _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 6;
				int height = 6;
				string bad[] = {"0 0 0 1","6 6 5 6"};
				_expected = 252LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 1:
			{
				int width = 1;
				int height = 1;
				string bad[] = {};
				_expected = 2LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 2:
			{
				int width = 35;
				int height = 31;
				string bad[] = {};
				_expected = 6406484391866534976LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 3:
			{
				int width = 2;
				int height = 2;
				string bad[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
				_expected = 0LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			/*case 4:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
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
