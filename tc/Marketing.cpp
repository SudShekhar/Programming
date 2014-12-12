#line 2 "Marketing.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class Marketing {
	int arr[32][32];
	vector<int> parse(string s){
		vector<int> ans;
		int num;
		int len=s.size();
		int start=0;
		if(len==0)
			return ans;
		for(int i=0;i<len;i++){
			if(s[i]==' '){
				num=0;
				while(start<i)
				{
					num = num* 10+ (s[start++]-'0');
				}
				start=i+1;
				ans.push_back(num);
			}	
		}
		num=0;
		while(start<len){
			num = num* 10+(s[start++]-'0');
		}
		ans.push_back(num);
		return ans;
	}
	int dfs(int ind,int vis[],int len){
		stack<int> st;
		int cur,col;
		st.push(ind);
		vis[ind]=1;
		while(!st.empty()){
			cur = st.top();
			// cout<<cur<<" at "<<vis[cur]<<endl;
			st.pop();
			col = vis[cur];
			for(int j=0;j<len;j++){
				if(arr[cur][j] == 1 && vis[j]==col)
				{
					// cout<<"Loop at "<<cur<<" to "<<j<<endl;
					// for(int k=0;k<len;k++)
					// 	cout<<vis[k]<<" ";
					// cout<<endl;
					return -1;
				}
				else if(arr[cur][j]==1 && vis[j] == 0)
				{
					vis[j]=((col%2) +1);
					st.push(j);
				}
			}
		}
		return 0;
	}
public:
long long howMany(vector <string> compete) {
	int len = compete.size();
	memset(arr,0,sizeof arr);
	for(int i=0;i<len;i++){
		vector<int> v = parse(compete[i]);
		// cout<<i<<" = ";
		// rep(k,v.size())
		// 	cout<<v[k]<<" ";
		// cout<<endl;
		for(int j=0;j<v.size();j++)
			arr[i][v[j]] = 1,arr[v[j]][i]=1;
	}
	int vis[len];
	memset(vis,0,sizeof vis);
	// rep(i,len)
	// 	{
	// 		rep(j,len)
	// 			cout<<arr[i][j]<<" ";
	// 		cout<<endl;
	// 	}
	int cur,col,diff=0;
	for(int i=0;i<len;i++){
		if(vis[i] == 0){
				diff++;
				if(dfs(i,vis,len)==-1)
					return -1;	
		}
	}
	long long two=1;
	while(diff>0){
		two*=2;
		diff--;
	}
	return two;
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
		cout << "Testing Marketing (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415908092;
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
		Marketing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string compete[] ={"1 4", "2", "3", "0", ""};
				_expected = 2LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}
			case 1:
			{
				string compete[] = {"1","2","0"};
				_expected = -1LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}
			case 2:
			{
				string compete[] = {"1","2","3","0","0 5","1"};
				_expected = 2LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}
			case 3:
			{
				string compete[] = {"","","","","","","","","","",
				                    "","","","","","","","","","",
				                    "","","","","","","","","",""};
				_expected = 1073741824LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}
			case 4:
			{
				string compete[] = {"1","2","3","0","5","6","4"};
				_expected = -1LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}
			/*case 5:
			{
				string compete[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string compete[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string compete[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(compete, compete+sizeof(compete)/sizeof(string))); break;
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
