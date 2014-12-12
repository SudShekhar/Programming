#line 2 "BinPacking.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class BinPacking {
public:
int minBins(vector <int> item) {
	int n = item.size(); //this is the maximum number of bins required.
	// int ans=n;
	int cap[51];
	sort(item.begin(),item.end());
	reverse(item.begin(),item.end());
	int bestFit,sz;
	//Faster appraoch => jo item na fit ho paye current scheme mein, allot it a new bucket
	// order = N*B where B is optimal bucket size and N is number of elements in item.
	int buck=1;
	cap[0]=300;
	for(int i=0;i<n;i++){
		bool alloted=false;
		for(int j=0;j<buck;j++)
			if(cap[j]>=item[i]){
				cap[j]-=item[i],alloted=true;
				break;
			}
		if(!alloted)
			cap[buck]=300-item[i],buck++;	
	}
	return buck;
	// for(int i=1;i<=n;i++){
	// 	// trying to fit all in these number of bins
	// 	for(int j=0;j<i;j++)
	// 		cap[j]=300;
	// 	//initialized
	// 	bool alloted=true;
	// 	for(int k=0;k<n;k++){
	// 		//for kth item
	// 		bestFit=-1;
	// 		sz=(1<<30);
	// 		for(int j=0;j<i;j++){
	// 			if(cap[j] >= item[k] && sz > cap[j])
	// 				bestFit=j,sz=cap[j];
	// 		}
	// 		if(bestFit == -1)
	// 			{
	// 				alloted=false;
	// 				break;
	// 			}
	// 		else {

	// 			// cout<<" fit "<<item[k]<<" in "<<bestFit<<" box with "<<cap[bestFit]<<endl;
	// 			cap[bestFit]-=item[k];	
	// 		}
	// 	}
	// 	if(alloted)
	// 		return i;
	// }
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
		cout << "Testing BinPacking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415338849;
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
		BinPacking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int item[] = {150, 150, 100, 100, 100};
				_expected = 2;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}
			case 1:
			{
				int item[] = {130, 140, 150, 160};
				_expected = 2;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}
			case 2:
			{
				int item[] = {100, 100, 100, 100, 100, 100, 100, 100, 100};
				_expected = 3;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}
			case 3:
			{
				int item[] = {100, 200, 100, 100, 100, 100, 200, 100, 200};
				_expected = 4;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}
			case 4:
			{
				int item[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152};
				_expected = 8;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}
			/*case 5:
			{
				int item[] = ;
				_expected = ;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int item[] = ;
				_expected = ;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int item[] = ;
				_expected = ;
				_received = _obj.minBins(vector <int>(item, item+sizeof(item)/sizeof(int))); break;
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
