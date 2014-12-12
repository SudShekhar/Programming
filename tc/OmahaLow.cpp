#line 2 "OmahaLow.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class OmahaLow {
public:
string low(string sharedCards, string playersCards) {
	map<int,int> my,mi;
	for(int i=0;i<sharedCards.size();i++)
		if(sharedCards[i] <= '8')
			mi[(int)(sharedCards[i]-'0')]=1;

	for(int i=0;i<playersCards.size();i++)
		if(playersCards[i] <= '8')
			my[(int)(playersCards[i]-'0')]=1;
	string ans="";
	for(int i=3;i<=8;i++){
		for(int i1=2;i1<i;i1++){
			for(int i2=1;i2<i1;i2++){
				for(int i3=2;i3<=8;i3++){
					for(int j=1;j<i3;j++){
						if(i3 == i1 || i3==i || i3==i2)
							continue;
						if(j==i1||j==i||j==i2)
							continue;
						if(my[i3]+my[j]==2 && mi[i]+mi[i1]+mi[i2]==3){
							string res;
							res.resize(5);
							res[0] = i+'0';
							res[1]=i1+'0';
							res[2] = i2+'0';
							res[3]=i3+'0';
							res[4]=j+'0';
							sort(res.begin(),res.end());
							reverse(res.begin(),res.end());
							return res;
							// if(ans=="")
							// 	ans=res;
							// ans= min(res,ans);
						} 
					}
				}
			}
		}
	}
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
		cout << "Testing OmahaLow (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415439520;
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
		OmahaLow _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string sharedCards = "123QK";
				string playersCards = "45TJ";
				_expected = "54321";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 1:
			{
				string sharedCards = "55443";
				string playersCards = "2345";
				_expected = "";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 2:
			{
				string sharedCards = "1357Q";
				string playersCards = "345J";
				_expected = "75431";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 3:
			{
				string sharedCards = "76285";
				string playersCards = "4816";
				_expected = "65421";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 4:
			{
				string sharedCards = "12345";
				string playersCards = "3339";
				_expected = "";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 5:
			{
				string sharedCards = "58463";
				string playersCards = "947K";
				_expected = "76543";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			case 6:
			{
				string sharedCards = "67521";
				string playersCards = "J859";
				_expected = "86521";
				_received = _obj.low(sharedCards, playersCards); break;
			}
			/*case 7:
			{
				string sharedCards = ;
				string playersCards = ;
				_expected = ;
				_received = _obj.low(sharedCards, playersCards); break;
			}*/
			/*case 8:
			{
				string sharedCards = ;
				string playersCards = ;
				_expected = ;
				_received = _obj.low(sharedCards, playersCards); break;
			}*/
			/*case 9:
			{
				string sharedCards = ;
				string playersCards = ;
				_expected = ;
				_received = _obj.low(sharedCards, playersCards); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
