#line 2 "MaxMinTreeGame.cpp"

// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pil(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007
//Since our opponent will always try to minimize the output, we must remove the min element at each step
// He will do the same for every max element.
// So our only option is to use elements which have a single degree (and separate them from the tree immediately)
// Way to think : What should be the best move of someone trying to win? => Remove the smallest node
// What should be the best move of someone trying to lose => Remove max
// so if we have 3 nodes, we will automatically lose out on any non-leaf node (if it's the best option, since the other player will remove it)
// So you can only look at leaf nodes.

class MaxMinTreeGame {
public:
int findend(vector <int> edges, vector <int> costs) {
	int n = costs.size();
	vector<int> deg(n,0);
	for(int i=0;i<n-1;i++){
		deg[i+1]++;
		deg[edges[i]]++;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(deg[i]==1)
			ans = max(ans,costs[i]);
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
		cout << "Testing MaxMinTreeGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415251875;
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
		MaxMinTreeGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int edges[] = {0};
				int costs[] = {4,6};
				_expected = 6;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 1:
			{
				int edges[] = {0,1};
				int costs[] = {4,6,5};
				_expected = 5;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 2:
			{
				int edges[] = {0,1,2,3};
				int costs[] = {0,1,0,1,0};
				_expected = 0;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 3:
			{
				int edges[] = {0,0,0};
				int costs[] = {5,1,2,3};
				_expected = 3;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 4:
			{
				int edges[] = {0,0};
				int costs[] = {3,2,5};
				_expected = 5;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			/*case 5:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
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
