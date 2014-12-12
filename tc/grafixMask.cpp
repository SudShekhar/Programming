#line 2 "grafixMask.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class grafixMask {
	int arr[400][600];
	vector<int> parse(string s){
		vector<int> ans(4);
		int cnt=0,num;
		int len=s.size();
		int start=0;
		for(int i=0;i<len;i++){
			if(s[i]==' '){
				num=0;
				while(start<i)
				{
					num = num* 10+ (s[start++]-'0');
				}
				start=i+1;
				ans[cnt++]=num;
			}	
		}
		num=0;
		while(start<len){
			num = num* 10+(s[start++]-'0');
		}
		ans[cnt] = num;
		return ans;
	}
	int dfs(int xind,int yind){
		arr[xind][yind]=1;
		int dx[] = {-1,1,0,0};
		int dy[] ={0,0,1,-1};
		int ans=1;
		stack<pair<int,int> > st;
		st.push(make_pair(xind,yind));
		int nx,ny;
		pair<int,int> cur;
		int cnt=0;
		while(!st.empty()){
			cur = st.top();
			st.pop();
			cnt++;
			xind = cur.first;
			yind=cur.second;
			rep(i,4){
				nx = xind+dx[i];
				ny = yind+dy[i];
				if(nx>=0 && nx <400 && ny >=0 && ny <600 && arr[nx][ny]==0)
					arr[nx][ny]=1,st.push(make_pair(nx,ny));
			}
		}
		return cnt;
	}
public:
vector <int> sortedAreas(vector <string> rectangles) {
	memset(arr,0,sizeof arr);
	int len = rectangles.size();
	for(int i=0;i<len;i++){
		vector<int> v = parse(rectangles[i]);
		for(int j=v[0];j<=v[2];j++){
			for(int k=v[1];k<=v[3];k++)
				arr[j][k]=1;
		}
	}
	vector<int> ans;
	int cnt=0;
	int val;
	for(int i=0;i<400;i++){
		for(int j=0;j<600;j++){
			if(arr[i][j]==0){
				val = dfs(i,j);
				ans.push_back(val);
			}
		}
	}
	// ans.resize(cnt);
	sort(ans.begin(),ans.end());
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
		cout << "Testing grafixMask (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415906367;
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
		grafixMask _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rectangles[] = {"0 292 399 307"};
				int __expected[] = { 116800,  116800 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}
			case 1:
			{
				string rectangles[] = {"48 192 351 207", "48 392 351 407", "120 52 135 547", "260 52 275 547"};
				int __expected[] = { 22816,  192608 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}
			case 2:
			{
				string rectangles[] = {"0 192 399 207", "0 392 399 407", "120 0 135 599", "260 0 275 599"};
				int __expected[] = { 22080,  22816,  22816,  23040,  23040,  23808,  23808,  23808,  23808 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}
			case 3:
			{
				string rectangles[] = {"50 300 199 300", "201 300 350 300", "200 50 200 299", "200 301 200 550"};
				int __expected[] = { 1,  239199 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}
			case 4:
			{
				string rectangles[] = {"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
				                       "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
				                       "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
				                       "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
				                       "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
				                       "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
				                       "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
				                       "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
				                       "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
				                       "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
				                       "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
				                       "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
				                       "373 0 373 599", "389 0 389 599"};
				int __expected[] = { 15,  30,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  100,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  200,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}
			/*case 5:
			{
				string rectangles[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string rectangles[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string rectangles[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sortedAreas(vector <string>(rectangles, rectangles+sizeof(rectangles)/sizeof(string))); break;
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
