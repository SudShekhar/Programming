#line 2 "Stamp.cpp"
#include<bits/stdc++.h>
using namespace std;
class Stamp {
public:
int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	long long int mx =(1<<30)+((1<<30)-1);
	int len = desiredColor.size();
	vector<int> colr(len);
	for(int i=0;i<len;i++)
		switch(desiredColor[i]){
			case '*': colr[i]=7;
					  break;
			case 'R': colr[i]=1;
					  break;
			case 'G': colr[i]=2;
					  break;
			case 'B': colr[i]=4;
					   break;
		}
	int res=(1<<30);
	int cost[len+1];
	for(int l=1;l<=len;l++){
		// int okay=true;
		cost[0]=0;
		for(int i=1;i<=len;i++)
			cost[i] = (1<<30);
		
		for(int i=0;i<len;i++){
			int col = 7;
			for(int j =i;j<len;j++){
				col &= colr[j];
				if(col==0){
					break;
				}
				int seg = j-i+1;
				if(seg<l)continue;
				if(cost[i]!=(1<<30))
					cost[j+1] = min(cost[j+1],(cost[i]+((seg+l-1)/l)*pushCost));
			}
		}
		if(cost[len]!=(1<<30))
			res = min(res, cost[len]+ stampCost*l);
			
	}
	return res;
}
};

// BEGIN CUT HERE
// #include <ctime>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <iostream>
// #include <algorithm>


int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Stamp (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415104623;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Stamp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string desiredColor = "RRGGBB";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 1:
			{
				string desiredColor = "R**GB*";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 2:
			{
				string desiredColor = "BRRB";
				int stampCost = 2;
				int pushCost = 7;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 3:
			{
				string desiredColor = "R*RR*GG";
				int stampCost = 10;
				int pushCost = 58;
				_expected = 204;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 4:
			{
				string desiredColor = "*B**B**B*BB*G*BBB**B**B*";
				int stampCost = 5;
				int pushCost = 2;
				_expected = 33;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 5:
			{
				string desiredColor = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
				int stampCost = 7;
				int pushCost = 1;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			/*case 6:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}*/
			/*case 7:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}*/
			/*case 8:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
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
