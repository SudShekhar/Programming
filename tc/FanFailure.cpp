#line 2 "FanFailure.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007

//Made 1 mistake because I thought MFS was supposed to have the highest value closest to req as possible.
// While it is the max number of fans which can be clubbed together in one go.

class FanFailure {
public:
vector <int> getRange(vector <int> capacities, int minCooling) {
	int MFC,MFS;
	// create prefix sum array
	int n = capacities.size();
	sort(capacities.begin(),capacities.end());
	std::vector<int> preSum(n+1,0);
	for(int i=1;i<=n;i++)
		preSum[i] = preSum[i-1]+capacities[i-1];
	int totalSum = preSum[n];
	bool works;
	int req = totalSum-minCooling;
	for(MFC=n-1;MFC>0;MFC--){
		works=true;
		for(int i=0;i<=n-MFC;i++)
		{	
			if(preSum[i+MFC] - preSum[i] > req)
				{
					works=false;
					break;
				}
		}
		if(works==true)
			break;
	}
	// int ans[2];
	vector<int> ans(2,0);
	//we have count of fans now.
	pair<int,int> dp[n+1];
	if(capacities[0] > req){
		ans[1]=MFC;
		ans[0]=0;
		return ans;
	}
	// cout<<req<<endl;
	dp[0] = make_pair(capacities[0],1);
	int mcount = 1,mx=dp[0].first;
	for(int i=1;i<n;i++){
		if(capacities[i] > req)
			break;
		dp[i] = make_pair(capacities[i],1);
		for(int j=0;j<i;j++){
			if(capacities[i]+dp[j].first <= req && capacities[i]+dp[j].first > dp[i].first){
					if(dp[i].first == capacities[i]+dp[j].first)
						dp[i].second = max(dp[i].second,dp[j].second+1);
					else dp[i].second = dp[j].second+1;
					dp[i].first = dp[j].first+capacities[i];
				}
		}
		// if(dp[i].first > mx && dp[i].first <=req)
		// 	mx =dp[i].first,mcount=dp[i].second;
		mcount = max(mcount,dp[i].second);
	}
	// for(int i=0;i<n;i++)
	// 	cout<<dp[i].first<<" "<<dp[i].second<<endl;
	ans[1]=MFC;
	ans[0]=mcount;
	return ans;

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
		cout << "Testing FanFailure (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415437387;
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
		FanFailure _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int capacities[] ={452, 367, 916, 53, 433, 219, 29, 730};
				int minCooling = 1937;
				int __expected[] = { 5,  1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}
			case 1:
			{
				int capacities[] = {8,5,6,7};
				int minCooling = 22;
				int __expected[] = { 0,  0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}
			case 2:
			{
				int capacities[] = {676, 11, 223, 413, 823, 122, 547, 187, 28};
				int minCooling = 1000;
				int __expected[] = { 7,  2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}
			case 3:
			{
				int capacities[] = {955, 96, 161, 259, 642, 242, 772, 369, 311, 785,
				                    92, 991, 620, 394, 128, 774, 973, 94, 681, 771,
				                    916, 373, 523, 100, 220, 993, 472, 798, 132, 361,
				                    33, 362, 573, 624, 722, 520, 451, 231, 37, 921,
				                    408, 170, 303, 559, 866, 412, 339, 757, 822, 192};
				int minCooling = 3619;
				int __expected[] = { 46,  30 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}
			/*case 4:
			{
				int capacities[] = ;
				int minCooling = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}*/
			/*case 5:
			{
				int capacities[] = ;
				int minCooling = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
			}*/
			/*case 6:
			{
				int capacities[] = ;
				int minCooling = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getRange(vector <int>(capacities, capacities+sizeof(capacities)/sizeof(int)), minCooling); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
