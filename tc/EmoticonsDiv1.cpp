#line 2 "EmoticonsDiv1.cpp"

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

int dp[1001][1001];
class EmoticonsDiv1 {
//We need to do BFS because depth first approach will never close. Whenever we have a circular dependency
	// That is we can go both front or back, use BFS as it goes according the number of steps and thus, the first
	// answer that you find, is your actual answer.

int solve(int &smiles){
		queue<pair<int, pair<int,int> > > q;
		q.push(make_pair(1,make_pair(0,0)));
		pair<int, pair<int,int> > cur;
		pair<int, pair<int,int> > temp;
		map<pair<int,pair<int,int> >, int> lp;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(cur.first == smiles)
				return cur.second.second; //steps
			if(cur.first + cur.second.first < 2*smiles)
				{	temp = cur;
					temp.first += temp.second.first;
					temp.second.second++;
					if(lp[temp]==0)
						lp[temp]=1,q.push(temp);
				}
			if(temp.second.first < temp.first){
				temp = cur;
				temp.second.first=temp.first;
				temp.second.second++;
				if(lp[temp]==0)
				lp[temp]=1,q.push(temp);
			}
			if(cur.first>1){
				temp=cur;
				temp.second.second++;
				temp.first = cur.first-1;
				temp.second.first=cur.second.first;
				if(lp[temp]==0){
				q.push(temp);
				lp[temp]=1;
				}
			}
		}
}

public:
int printSmiles(int smiles) {
	return solve(smiles);
}
};

// BEGIN CUT HERE
// #include <ctime>
// #include <cmath>
// #include <string>
// #include <vector>
#include <sstream>
// #include <iostream>
// #include <algorithm>
// using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing EmoticonsDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415172562;
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
		EmoticonsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int smiles = 2;
				_expected = 2;
				_received = _obj.printSmiles(smiles); break;
			}
			case 1:
			{
				int smiles = 4;
				_expected = 4;
				_received = _obj.printSmiles(smiles); break;
			}
			case 2:
			{
				int smiles = 6;
				_expected = 5;
				_received = _obj.printSmiles(smiles); break;
			}
			case 3:
			{
				int smiles = 255;
				_expected = 17;
				_received = _obj.printSmiles(smiles); break;
			}
			case 4:
			{
				int smiles = 11;
				_expected = 8;
				_received = _obj.printSmiles(smiles); break;
			}
			/*case 5:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
			}*/
			/*case 6:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
			}*/
			/*case 7:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
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
