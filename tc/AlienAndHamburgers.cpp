#line 2 "AlienAndHamburgers.cpp"

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


class AlienAndHamburgers {
public:
int getNumber(vector <int> type, vector <int> taste) {
	vector<int> tasteSum(100,0);
	int n = type.size();
	for(int i=0;i<n;i++){
		if(taste[i] >0){
			if(tasteSum[type[i]] <0)
				tasteSum[type[i]]=0;
			tasteSum[type[i]]+= taste[i];
		}
		else{
			if(tasteSum[type[i]] >0);
			else if(tasteSum[type[i]]==0)tasteSum[type[i]] =taste[i];
			else tasteSum[type[i]] = max(tasteSum[type[i]],taste[i]);//both negative
		}
	}

	int dtypes=0;
	long long sm=0;
	int cnt=0;
	std::vector<int> negs;
	map<int,int> ze;
	for(int i=0;i<n;i++){
		if(taste[i]==0 && tasteSum[type[i]] <=0 && ze[type[i]]==0)
			negs.push_back(0),tasteSum[type[i]]=0,cnt++,ze[type[i]]=1;		
	}
	for(int i=0;i<101;i++){
		if(tasteSum[i] > 0){
			sm+=tasteSum[i];
			dtypes++;
		}
		else if(tasteSum[i]<0){
			negs.push_back(tasteSum[i]);
			cnt++;
		}
	}
	int posVal = dtypes*sm;
	// cout<<posVal<<endl;
	sort(negs.begin(),negs.begin()+cnt);
	reverse(negs.begin(),negs.begin()+cnt);
	//we have smallest numbers first now
	// n = negs.size();
	int ans=posVal;
	for(int i=0;i<cnt;i++){
		// if((dtypes+1)*(sm+negs[i]) < posVal)
		// 	break;
		// else posVal = (dtypes+1)*(sm+negs[i]),dtypes++,sm+=negs[i]; 
		// cout<<posVal<<endl;
		posVal = (dtypes+1)*(sm+negs[i]) ;
		dtypes++;
		sm += negs[i];
		ans = max(ans,posVal);
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
		cout << "Testing AlienAndHamburgers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415222503;
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
		AlienAndHamburgers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int type[] = {2, 19, 2, 46, 80, 55, 31, 98, 35, 80, 38, 8, 73, 6, 94, 35};
				int taste[] =  {-41785, 84130, -31315, 21553, -75840, 41033, -60983, -74023, 52912, -58789, -13260, 61190, -93331, -88395, -19813, -21761};
				_expected = 1594215;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 1:
			{
				int type[] = {2, 2, 2, 3, 3, 3, 2};
				int taste[] = {6, 0, -7, -8, -8, 0, -4};
				_expected = 12;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 2:
			{
				int type[] = {13, 13, 52, 52, 52, 100, 100};
				int taste[] = {0, -1, 0, -1, 1, 0, 0};
				_expected = 3;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 3:
			{
				int type[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
				int taste[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
				_expected = 54;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 4:
			{
				int type[] = {30, 20, 10};
				int taste[] = {100000, -100000, 100000};
				_expected = 400000;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 5:
			{
				int type[] = {1,2} ;
				int taste[] = {-1,-1};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			/*case 6:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
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
