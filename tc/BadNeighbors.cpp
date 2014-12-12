#line 2 "BadNeighbors.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class BadNeighbors {
public:
int maxDonations(vector <int> donations) {
	int n = donations.size();
	vector< pair<int,bool> > v(n);
	v[0].first = donations[0];
	v[0].second=true;
	int mx;
	bool includ;
	for(int i=1;i<n-1;i++){
		// v[i].first = donations[i];
		mx=0;
		includ=false;
		for(int j=i-2;j>=0;j--)
			if(mx < v[j].first || mx==v[j].first && v[j].first==false)
				mx = v[j].first,includ=v[j].second;
		v[i].first = mx+donations[i];
		v[i].second=includ;
	}
	mx=0;
	includ=false;
	for(int i=1;i<n-2;i++){
		if(v[i].second==false)
			mx=max(mx,v[i].first);
	}
	v[n-1].first = mx+donations[n-1];
	mx=0;
	// for(int i=0;i<n;i++)
	// 	cout<<v[i].first<<" "<<(v[i].second==true?"yes":"no")<<endl;
	for(int i=0;i<n;i++)
		mx =max(mx,v[i].first);
	v[0].first = 0;
	int temp;
	for(int i=1;i<n;i++){
		v[i].first = donations[i];
		temp = 0;
		for(int j=i-2;j>=0;j--)
			temp = max(temp,v[j].first);
		v[i].first += temp;
		mx = max(mx,v[i].first);
	}
	
	return mx;

//created lists;
}
// int oldAns(vector<int> donations){
// 	int len = donations.size();
// vec l1(len),l2(len);
// int dp[len],dp1[len];
// cout<<len<<endl;
// FOR(i,1,len-1){
// 	l1[i]=donations[i];
// 	l2[i-1]=donations[i];
// }
// l1[0]=donations[0];
// l2[len-2]=donations[len-1];

// dp[0]=l1[0];
// dp[1]=max(l1[1],l1[0]);
// FOR(i,2,len-1){
// 	dp[i]= max(dp[i-1] , (dp[i-2] + l1[i]));
// }

// dp1[0]=l2[0];
// dp1[1]=max(l2[1],l2[0]);

// FOR(i,2,len-1){
// dp1[i] = max(dp1[i-1] , (dp1[i-2] + l2[i]));
// }
// rep(i,len-1)cout<<dp[i]<<" ";
// cout<<endl;
// rep(i,len-1)cout<<dp1[i]<<" ";
// cout<<endl;
// return max(dp[len-2],dp1[len-2]);
// }

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
		cout << "Testing BadNeighbors (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415454927;
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
		BadNeighbors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int donations[] =  { 10, 3, 2, 5, 7, 8 };
				_expected = 19;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 1:
			{
				int donations[] = { 11, 15 };
				_expected = 15;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 2:
			{
				int donations[] = { 7, 7, 7, 7, 7, 7, 7 };
				_expected = 21;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 3:
			{
				int donations[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
				_expected = 16;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 4:
			{
				int donations[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
				                    6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
				                    52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
				_expected = 2926;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			/*case 5:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
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
