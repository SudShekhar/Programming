#line 2 "Egalitarianism.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007


class Egalitarianism {

	int dfs(int ind,int vis[],std::vector<string>&arr,int n){
		vis[ind]=1;
		int val,len=0;
		for(int i=0;i<n;i++){
			if(arr[ind][i] != 'N' && vis[i]==0)
				val=dfs(i,vis,arr,n),len=max(len,val);
		}
		return len+1;
	}
public:
int maxDifference(vector <string> isFriend, int d) {
	int n = isFriend.size();
	// second is the value given
	int vis[n];
	memset(vis,0,sizeof vis);
	dfs(0,vis,isFriend,n);
	rep(i,n)
		if(vis[i]==0)
			return -1;
	
	int mx=-1;
	memset(vis,0,sizeof vis);
	queue<pair<int,int> > q;
	int nstart;
	// q.push(make_pair(0,0));
	// while(!q.empty()){
	// 	pair<int,int> cur = q.front();
	// 	q.pop();
	// 	vis[cur.first]=1;
	// 	int ind = cur.first;
	// 	int depth = cur.second;
	// 	mx = max(depth,mx);
	// 	if(mx == depth)
	// 		nstart = ind;
	// 	for(int i=0;i<n;i++){
	// 		if(isFriend[ind][i] !='N' && vis[i]==0)
	// 			vis[i]=1,q.push(make_pair(i,depth+1));
	// 	}
	// }
	// rep(i,n)
	// 	if(vis[i]==0)
	// 		cout<<"Nahi gya\n";
	// cout<<" distant path "<<mx<<" nstart " << nstart<<endl;
	mx=-1;
	for(nstart=0;nstart<n;nstart++){
	memset(vis,0,sizeof vis);
	int mind;
	q.push(make_pair(nstart,0));
	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();
		int ind = cur.first;
		vis[ind]=1;
		int depth = cur.second;
		if(depth>mx)
			mx=depth,mind=ind;
		// mx = max(depth,mx);
		// if(mx == depth)
		// 	nstart = ind;
		for(int i=0;i<n;i++){
			if(isFriend[ind][i] !='N' && vis[i]==0)
				vis[i]=1,q.push(make_pair(i,depth+1));
		}
	}
	// cout<<nstart<<" to "<< mind<<" distant path2 "<<mx<<endl;
	}
	// rep(i,n)
	// 	if(vis[i]==0)
	// 		cout<<"Nahi gya\n";
	// if(d==557)
	// rep(i,n)
	// {
	// 	rep(j,n)
	// 		cout<<isFriend[i][j]<<" ";
	// 	cout<<endl;
	// }
	if(mx ==-1)
		return -1;
	return (mx*d);
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
		cout << "Testing Egalitarianism (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415555904;
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
		Egalitarianism _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string isFriend[] = {"NYYNYNNNNNNNNYNNNNYNNYNYNNYNY", "YNNYYNNNYNNNYYNNNNNNNNNNNNNYN", "YNNNNNNYYYNYNNNNNYNNYYNNNYNNN", "NYNNNYNNNNNNNNNNNNNNNNNNNYNNN", "YYNNNNNNNNYNNNNNYNYYNYNNNYNNN", "NNNYNNYYNNNYNNNNNNNNYNNNYYYYN", "NNNNNYNNYNNNNNNYNNNYNNNYYNNNN", "NNYNNYNNNNNNNNNNNNNNNNNNNNNNN", "NYYNNNYNNNYNNNNNYNYNYNNNNNNNN", "NNYNNNNNNNNNNNYNNNNNNNNNYNNNN", "NNNNYNNNYNNYNYNNNNNNNNNYNNYYY", "NNYNNYNNNNYNYNNNNNNYNNNNYNNNN", "NYNNNNNNNNNYNNNYNNYNYNNYYNNYN", "YYNNNNNNNNYNNNNNNYNYNNYNNYNNN", "NNNNNNNNNYNNNNNNNNNNYNNNNNNNY", "NNNNNNYNNNNNYNNNNNNNNNNNNNYYN", "NNNNYNNNYNNNNNNNNNNNYNYYNNNNY", "NNYNNNNNNNNNNYNNNNNNNNYNNNYNN", "YNNNYNNNYNNNYNNNNNNNYNNNNNNNY", "NNNNYNYNNNNYNYNNNNNNYNNNNNYYN", "NNYNNYNNYNNNYNYNYNYYNYYYNNNNY", "YNYNYNNNNNNNNNNNNNNNYNYYNNNNN", "NNNNNNNNNNNNNYNNYYNNYYNNNNNNN", "YNNNNNYNNNYNYNNNYNNNYYNNNNNNY", "NNNNNYYNNYNYYNNNNNNNNNNNNNNNY", "NNYYYYNNNNNNNYNNNNNNNNNNNNNNN", "YNNNNYNNNNYNNNNYNYNYNNNNNNNNN", "NYNNNYNNNNYNYNNYNNNYNNNNNNNNN", "YNNNNNNNNNYNNNYNYNYNYNNYYNNNN"};
				int d = 80;
				_expected = 240;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 1:
			{
				string isFriend[] ={"NNNNNNNNNYYNNNNYYNNNNNYNYNNNNYNN", "NNNYNNNYNYYNNNYNNNYNNYNNYNNNNYNN", "NNNNYNNNNNNYNYNNNNNNNNNNNNYNNNNN", "NYNNYYNNNNNNNNNNYNYNNNYYYYNYNNNN", "NNYYNNYYNNNNYYYNNNNNNNNNNNNNNYNY", "NNNYNNNNNNNNNNNYYNNNNNYNNNNYYNYN", "NNNNYNNNNYNNNNYNNNNNYNNNNNYNYNYN", "NYNNYNNNNNNNNNYNNYNNNNNNNNNNYNNN", "NNNNNNNNNNNNNYNNNNNNNYNNNYNYNYNN", "YYNNNNYNNNNNYNNNYNNNNNNYNYNNNNYY", "YYNNNNNNNNNNNNNNNYNNYYNNNNNNNYNN", "NNYNNNNNNNNNNNYNNNYNYNNNNNNNNNNN", "NNNNYNNNNYNNNNYYYNNYNNYNYNNYYNNY", "NNYNYNNNYNNNNNNNNNNYNNNNYNNNNYNN", "NYNNYNYYNNNYYNNNNNYYNNYNNNYNNNNN", "YNNNNYNNNNNNYNNNNNNYNNYNYNNNYNNN", "YNNYNYNNNYNNYNNNNNNYNNYNNYNNNNNY", "NNNNNNNYNNYNNNNNNNNNYNNNNNNNYNNN", "NYNYNNNNNNNYNNYNNNNNYNYYYNNNNYNY", "NNNNNNNNNNNNYYYYYNNNYNNNNNNNYNNN", "NNNNNNYNNNYYNNNNNYYYNNNNYNNYYNNN", "NYNNNNNNYNYNNNNNNNNNNNNNNNNNNYNN", "YNNYNYNNNNNNYNYYYNYNNNNYNNNNNNNN", "NNNYNNNNNYNNNNNNNNYNNNYNNNNYNNYY", "YYNYNNNNNNNNYYNYNNYNYNNNNNNNNNNN", "NNNYNNNNYYNNNNNNYNNNNNNNNNNNNNNN", "NNYNNNYNNNNNNNYNNNNNNNNNNNNYNNNY", "NNNYNYNNYNNNYNNNNNNNYNNYNNYNNNNY", "NNNNNYYYNNNNYNNYNYNYYNNNNNNNNYYN", "YYNNYNNNYNYNNYNNNNYNNYNNNNNNYNNN", "NNNNNYYNNYNNNNNNNNNNNNNYNNNNYNNY", "NNNNYNNNNYNNYNNNYNYNNNNYNNYYNNYN"};
				int d =  557;
				_expected = 2228;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 2:
			{
				string isFriend[] = {"NNYNNN",
				                     "NNYNNN",
				                     "YYNYNN",
				                     "NNYNYY",
				                     "NNNYNN",
				                     "NNNYNN"};
				int d = 1000;
				_expected = 3000;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 3:
			{
				string isFriend[] = {"NNYN",
				                     "NNNY",
				                     "YNNN",
				                     "NYNN"};
				int d = 584;
				_expected = -1;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 4:
			{
				string isFriend[] = {"NYNYYYN",
				                     "YNNYYYN",
				                     "NNNNYNN",
				                     "YYNNYYN",
				                     "YYYYNNN",
				                     "YYNYNNY",
				                     "NNNNNYN"};
				int d = 5;
				_expected = 20;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 5:
			{
				string isFriend[] = {"NYYNNNNYYYYNNNN",
				                     "YNNNYNNNNNNYYNN",
				                     "YNNYNYNNNNYNNNN",
				                     "NNYNNYNNNNNNNNN",
				                     "NYNNNNYNNYNNNNN",
				                     "NNYYNNYNNYNNNYN",
				                     "NNNNYYNNYNNNNNN",
				                     "YNNNNNNNNNYNNNN",
				                     "YNNNNNYNNNNNYNN",
				                     "YNNNYYNNNNNNNNY",
				                     "YNYNNNNYNNNNNNN",
				                     "NYNNNNNNNNNNNNY",
				                     "NYNNNNNNYNNNNYN",
				                     "NNNNNYNNNNNNYNN",
				                     "NNNNNNNNNYNYNNN"};
				int d = 747;
				_expected = 2988;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 6:
			{
				string isFriend[] = {"NY",
				                     "YN"};
				int d = 0;
				_expected = 0;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			/*case 7:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 8:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 9:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
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
