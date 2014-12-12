#line 2 "LCMSetEasy.cpp"

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


class LCMSetEasy {
vector<int> pset;
void seive(){
	bool primes[100000];
	memset(primes,true,sizeof primes);
	primes[0]=false; 
	// pset.push_back(1);
	// primes[1]=false;
	for(int i=2;i<100000;i++){
		if(primes[i]){
			pset.push_back(i);
			for(int j=2*i;j<100000;j+=i)
			{
				primes[j]=false;
			}
		}
	}	
}
void factor(int x,map<int,int> &arr){
	int count;
	// cout<<x<<" ka factor" <<endl;
	for(int i=0;i<pset.size() && pset[i]<=x;i++){
		if(x%pset[i]==0){
			// cout<<pset[i]<<"Divides"<<endl;
			count=0;
			while(x%pset[i]==0)
				x/=pset[i],count++;	
			arr[pset[i]]=count;
		}
	}
	if(x!=1){
		arr[x]=1;
	}
	// map<int,int> :: iterator it;
	// for(it=arr.begin();it!=arr.end();it++){
	// 	if((*it).second!=0)
	// 		cout<<(*it).first<<" => "<<(*it).second<<endl;
	// }
}
bool compare(map<int,int> &a,map<int,int>&b){
	map<int,int>::iterator it;
	int key;
	for(it=b.begin();it!=b.end();it++){
		key = (*it).first;
		if(a.find(key) == a.end() || (a[key]<b[key]))
			return false;
	}
	return true;
}
public:
string include(vector <int> S, int x) {
	seive();
	map<int,int> xfac;
	factor(x,xfac);
	int n=S.size();
	map<int,int> sfac[n];
	for(int i=0;i<n;i++){
		factor(S[i],sfac[i]);
	}

	int flen=0;
//now we have all the factors with their entire sets;
	map<int,int> :: iterator it;
	int key;
	map<int,int> fnd;
	for(int i=0;i<n;i++){
		if(compare(xfac,sfac[i])){
			// cout<<S[i]<<" divids "<<endl;
			for(it=xfac.begin();it!=xfac.end();it++){
				key= (*it).first;
				if(fnd[key]==0 && sfac[i].find(key)!=sfac[i].end() && sfac[i][key] == (*it).second && (*it).second!=0)
						fnd[key]=1,flen++;

			}
		}
	}
	if(flen==xfac.size())
		return "Possible";
	else return "Impossible";
}
int gcd(int a, int b)
{
    while (b != 0) {
        int c = a;
        a = b;
        b = c % a;
    }
    return a;
}
 
string cor(vector<int> &S, int x)
{
    int lcm = 1;
    for (int i=0;i<S.size();i++) {
    	int y = S[i];
        if ( x % y == 0) {
            lcm = lcm / gcd(lcm, y) * y;
        }
    }
    // cout<<" For "<<x<< " lcm is  "<<lcm<<endl;
    return (lcm == x) ? "Possible" : "Impossible";
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

// int main(){
// 	// int S[] = {36, 239, 450, 85, 22, 4, 38, 37, 110, 9, 5, 634, 6, 100, 694, 563, 83, 346, 2, 90, 53, 54, 585, 97, 13, 7, 661, 3, 118, 23, 10, 215, 16, 73, 498, 550, 329, 8, 400};
// 	// int A[] = {8, 585, 36, 73, 108, 634, 694, 330, 110, 85, 10, 90, 54, 23, 97, 346, 100, 3, 661, 13186, 7, 118, 239, 38, 11454, 16, 9, 13, 563, 83, 1406, 7740, 5, 53, 2, 6, 329, 4, 400, 1849860, 37, 498, 215, 450, 22};
// 	int B[] = {36, 239, 450, 85, 22, 4, 38, 37, 110, 9, 5, 634, 6, 100, 694, 563, 83, 346, 2, 90, 53, 54, 585, 97, 13, 7, 661, 3, 118, 23, 10, 215, 16, 73, 498, 550, 329, 8, 400};
// 	int A[]={2,3,4,5,7,8,9,13,16,22,23,37,38,53,54,73,83,85,97,100,118,215,239,329,346};			
// 	int x = 450;
// 	int y=550;
// 	std::vector<int> v(A,A+sizeof(A)/sizeof(A[0]));
// 	std::vector<int> v1(B,B+sizeof(B)/sizeof(B[0]));
// 	LCMSetEasy a;
// 	cout<<a.include(v,x)<<endl;
// 	cout<<a.cor(v,x)<<endl;

// }


int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing LCMSetEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415206092;
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
		LCMSetEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {36, 239, 450, 85, 22, 4, 38, 37, 110, 9, 5, 634, 6, 100, 694, 563, 83, 346, 2, 90, 53, 54, 585, 97, 13, 7, 661, 3, 118, 23, 10, 215, 16, 73, 498, 550, 329, 8, 400};
				int x = 450;
				// cout<<_obj.include()
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 1:
			{
				int S[] = {20, 79, 10, 43, 11};
				int x = 373670;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 2:
			{
				int S[] = {2,3,4};
				int x = 12;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 3:
			{
				int S[] = {1,2,3,4,5,6,7,8,9,10};
				int x = 24;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 4:
			{
				int S[] = {100,200,300,400,500,600};
				int x = 2000;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 5:
			{
				int S[] = {100,200,300,400,500,600};
				int x = 8000;
				_expected = "Impossible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 6:
			{
				int S[] = {1000000000,999999999,999999998};
				int x = 999999999;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			/*case 7:
			{
				int S[] = ;
				int x = ;
				_expected = ;
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}*/
			/*case 8:
			{
				int S[] = ;
				int x = ;
				_expected = ;
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}*/
			/*case 9:
			{
				int S[] = ;
				int x = ;
				_expected = ;
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
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
