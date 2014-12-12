#line 2 "ORSolitaire.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class ORSolitaire {
	void printBits(int n){
		for(int j=0;j<32;j++){
			if(n&(1<<j))
				cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
		return;
	}
public:
int getMinimum(vector <int> num, int goal) {
	int ans=(1<<30),count=0;
	// sort(numbers.begin(),numbers.end());
	int n = num.size();
	// while(n>0 && (numbers[n-1] >goal))
	// 	n--;
	bool flag;
	int mask;
	vector<int> numbers;
	for(int i=0;i<n;i++){
		flag=true;
		for(int j=0;j<32;j++){
			mask = (1<<j);
			if((num[i]&mask)!=0 && (goal&mask)==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			numbers.push_back(num[i]);
	}
	n = numbers.size();
	// for(int i=0;i<n;i++)
	// 	printBits(numbers[i]);
	// // int mask;
	// cout<<"Goal"<<endl;
	// printBits(goal);
	for(int j=0;j<32;j++){
		mask = (1<<j);
		if((goal&mask) == 0)
			continue;
		//we need a 1 here now.
		count=0;
		for(int i=0;i<n;i++){
			if((numbers[i] & mask) !=0)
				count++;
		}

		if(count!=0)
			ans=min(ans,count);
		else {
			return 0;
		}
	}
	if(ans== (1<<30))
		return 0;
	// ans=min(ans,count);
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
		cout << "Testing ORSolitaire (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415336957;
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
		ORSolitaire _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {748543700, 285483932, 519266441, 316159832, 405530603, 302252740, 361164782, 260403486, 184590853, 328864359, 49806381, 620630387, 186736925, 36397396};
				int goal =  453288957;
				_expected = 0;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int numbers[] = {1, 2, 4, 7, 8};
				int goal = 7;
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int numbers[] = {12571295, 2174218, 2015120};
				int goal = 1;
				_expected = 0;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int numbers[] = {5,2,4,52,62,9,8,3,1,11,6};
				int goal = 11;
				_expected = 3;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 4:
			{
				int numbers[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
				int goal = 510;
				_expected = 5;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			/*case 5:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
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
